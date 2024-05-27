#include "log.h"
#include <map>
#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>
#include <stdarg.h>

namespace sylar{

    const char *LogLevel::ToString(LogLevel::Level Level)
    {
        switch (Level){
#define XX(name) \
        case LogLevel::name: \
            return #name; \
            break;
        XX(DEBUG);
        XX(INFO);
        XX(WARN);
        XX(ERROR);
        XX(FATAL);
#undef XX
        default:
            return "UNKNOW";
        }
        return "UNKNOW";
    }

LogEventWrap::LogEventWrap(LogEvent::ptr e):m_event(e){

};
LogEventWrap::~LogEventWrap(){
    m_event->getLogger()->log(m_event->getLevel(), m_event);
};

std::stringstream&  LogEventWrap::getSS(){
    return m_event->getSS();
};


/**
 *  void format(const char* fmt, ...); 是一个直接接受可变数量参数的函数。
    void format(const char* fmt, va_list al); 接受一个 va_list 类型的参数，这个参数已经包含了可变参数列表。
    两者常常配合使用，前者用于接收可变参数并将其转化为 va_list 类型，后者用于实际的处理工作。
*/
void LogEvent::format(const char* fmt, ...){
    va_list al;
    va_start(al, fmt);
    format(fmt, al);
    va_end(al);
};
void LogEvent::format(const char* fmt, va_list al){
    char* buf = nullptr;
    int len = vasprintf(&buf, fmt, al);
    if (len != -1)
    {
        m_ss << std::string(buf, len);
        free(buf);
    }
    
};


class MessageFormatItem : public LogFormatter::FormatItem{
public:
    MessageFormatItem(const std::string& str = ""){}
    void format (std::ostream& os ,std::shared_ptr<Logger> logger, LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getContent();
    }
};

class LevelFormatItem : public LogFormatter::FormatItem{
public:
    LevelFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<LogLevel::ToString(level);
    }
};

class ElapseFormatItem : public LogFormatter::FormatItem{
public:
    ElapseFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getElapse();
    }
};

class NameFormatItem : public LogFormatter::FormatItem{
public:
    NameFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<logger->getName();
    }
};

class ThreadIdFormatItem : public LogFormatter::FormatItem{
public:
    ThreadIdFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getThreadId();
    }
};

class FiberIdFormatItem : public LogFormatter::FormatItem{
public:
    FiberIdFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getFiberId();
    }
};

class DateTimeFormatItem : public LogFormatter::FormatItem{
public:
    DateTimeFormatItem(const std::string& format = "%Y-%m-%d %H:%M:%S"):m_format(format){
        if (m_format.empty())
        {
            m_format = "%Y-%m-%d %H:%M:%S";
        }
        
    }
    void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        struct tm tm;
        time_t time =event->getTime();
        localtime_r(&time, &tm);
        char buf[64];
        strftime(buf, sizeof(buf), m_format.c_str(), &tm);
        os<< buf;
    }
private:
    std::string m_format;

};

class FilenameFormatItem : public LogFormatter::FormatItem{
public:
    FilenameFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getFile();
    }
};

class LineFormatItem : public LogFormatter::FormatItem{
public:
    LineFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<event->getLine();
    }
};

class NewLineFormatItem : public LogFormatter::FormatItem{
public:
    NewLineFormatItem(const std::string& str = ""){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<std::endl;
    }
};


class StringFormatItem : public LogFormatter::FormatItem{
public:
    StringFormatItem(const std::string& str):m_string(str){}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<m_string;
    }
private:
    std::string m_string;
};

class TabFormatItem : public LogFormatter::FormatItem{
public:
    TabFormatItem(const std::string& str = "") {}
     void format (std::ostream& os , std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event) override{
        os<<"\t";
    }
private:
    std::string m_string;
};


LogEvent::LogEvent
(std::shared_ptr<Logger> logger, LogLevel::Level level,const char *file, int32_t line, uint32_t elapse, uint32_t thread_id, uint32_t fiber_id, uint64_t time)
:m_file(file)
,m_line(line)
,m_elapse(elapse)
,m_threadId(thread_id)
,m_fiberId(fiber_id)
,m_time(time)
,m_logger(logger)
,m_level(level)
{
}
    Logger::Logger(const std::string& name):m_name(name),m_level(LogLevel::DEBUG){
        m_formatter.reset(new LogFormatter("%d{%Y-%m-%d %H:%M:%S}%T%t%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"));
    };

    void Logger::addAppender(LogAppender::ptr appender){
        if (!appender->getFomatter())
        {
            appender->setFormatter(m_formatter);
        }
        
        m_appenders.push_back(appender);
    };
    void Logger::delAppender(LogAppender::ptr appender){
        for (auto it = m_appenders.begin(); it !=m_appenders.end(); ++it)
        {
            if (*it == appender)
            {   
                m_appenders.erase(it);
                break;
            }
            
        }
        
    };

    void Logger::log(LogLevel::Level level, LogEvent::ptr event){
            if (level >= m_level)
            {
                auto self =shared_from_this();
                for (auto &i : m_appenders)
                {
                    i->log(self,level,event);
                }
                
            }
 
    };

    void Logger::debug(LogEvent::ptr event){
        log(LogLevel::DEBUG,event);
    };
    void Logger::info(LogEvent::ptr event){
        log(LogLevel::INFO,event);
    };
    void Logger::warn(LogEvent::ptr event){
        log(LogLevel::WARN,event);
    };
    void Logger::error(LogEvent::ptr event){
        log(LogLevel::ERROR,event);
    };
    void Logger::fatal(LogEvent::ptr event){
        log(LogLevel::FATAL,event);
    };


    void StdoutLogAppender::log(std::shared_ptr<Logger> logger,LogLevel::Level level, LogEvent::ptr event)
    {
        if (level >= m_level)
        {
            std::cout<<m_formatter->format(logger,level,event);
        }
        
    }
    FileLogAppender::FileLogAppender(const std::string &filename):m_filename(filename)
    {
        reopen();
    }
    void FileLogAppender::log(std::shared_ptr<Logger> logger,LogLevel::Level level, LogEvent::ptr event)
    {
        if (level >= m_level)
            {
                 // 打开一个文件。如果文件不存在，将创建该文件
                m_filestream.open(m_filename, std::ios::app);

                // 检查文件是否成功打开
                if (!m_filestream.is_open()) {
                    std::cerr << "Failed to open the file." << std::endl;
                }

                // 使用流插入运算符将内容写入文件
                m_filestream << m_formatter->format(logger,level,event);
                
                // 关闭文件
                m_filestream.close();
            }
    }
    bool FileLogAppender::reopen()
    {
        if (m_filestream)
        {   
            m_filestream.close();
        }   
        return !!m_filestream;
        
    }

    LogFormatter::LogFormatter(const std::string &pattern):m_pattern(pattern)
    {
        init();
    }

    std::string LogFormatter::format(std::shared_ptr<Logger> logger,LogLevel::Level level, LogEvent::ptr event)
    {
        std::stringstream ss;
        for (auto &i : m_items)
        {
            i->format(ss,logger,level,event);
        }
        
        return  ss.str();
    }
//%xxx %xxx{xxx} %%
void LogFormatter::init() {
    //str, format ,type
    std::vector<std::tuple<std::string,std::string,int>> vec;
    std::string nstr;
    for (size_t i = 0; i < m_pattern.size(); ++i)
    { 
        
        if(m_pattern[i]!='%'){
            nstr.append(1,m_pattern[i]);
            continue;
        }
        if ((i+1)<m_pattern.size())
        {
            if(m_pattern[i+1]=='%'){
                nstr.append(1,'%');
                continue;
            }
        }

        size_t n = i + 1;
        int fmt_status = 0;
        size_t fmt_begin = 0;

        std::string str;
        std::string fmt;

        while(n<m_pattern.size()){
            if (!fmt_status && (!isalpha(m_pattern[n]) && m_pattern[n] != '{' && m_pattern[n] != '}'))
            {
                str = m_pattern.substr(i + 1 , n - i - 1);
                break;
            }
            if (fmt_status==0){
                if (m_pattern[n]=='{')
                {
                    str = m_pattern.substr(i + 1, n - i - 1);
                    fmt_status = 1; //解析格式
                    fmt_begin = n; 
                    ++n;
                    continue;

                }
                
            } else if (fmt_status == 1)
            {
                if (m_pattern[n] == '}')
                {
                   fmt = m_pattern.substr(fmt_begin + 1 ,n - fmt_begin - 1);
                   fmt_status = 0;
                   ++n;
                   break;
                }
                
            }   
            ++n; 
            if (n == m_pattern.size())
            {
                if(str.empty()){
                    str = m_pattern.substr(i + 1);
                }
            }
            
        }

        if (fmt_status == 0){
          if (!nstr.empty()){
                vec.push_back(std::make_tuple(nstr,std::string(),0));
                nstr.clear();
          }
          
          vec.push_back(std::make_tuple(str,fmt,1));
          i = n - 1;

        }else if (fmt_status == 1){
            std::cout << "pattern parse error: " << m_pattern << " - " << m_pattern.substr(i) << std::endl;
            vec.push_back(std::make_tuple("<<pattern_error>>", fmt, 0));
        }
    }
    if (!nstr.empty()){
            vec.push_back(std::make_tuple(nstr,"",0));
    }
    
    // 遍历并输出向量中的每个元素
    // for (const auto& item : vec) {
    //     std::cout << "First: " << std::get<0>(item) << ", Second: " << std::get<1>(item) << ", Third: " << std::get<2>(item) << std::endl;
    // }
    
    static std::map<std::string, std::function<FormatItem::ptr(const std::string& str)>> s_format_items = {
#define XX(str, C) \
            {#str, [](const std::string& fmt){return FormatItem::ptr(new C(fmt));}} 

            XX(m, MessageFormatItem),
            XX(p, LevelFormatItem),
            XX(r, ElapseFormatItem),
            XX(c, NameFormatItem),
            XX(t, ThreadIdFormatItem),
            XX(n, NewLineFormatItem),
            XX(d, DateTimeFormatItem),
            XX(f, FilenameFormatItem),
            XX(l, LineFormatItem),
            XX(T, TabFormatItem),
            XX(F, FiberIdFormatItem),
#undef XX
    };
    
    //    for (const auto& item : s_format_items) {
    //     std::cout << "Key: " << std::get<0>(item) << ", Function exists: " << (std::get<1>(item) ? "Yes" : "No") << std::endl;
    //     }

    for(auto& i : vec){
        if(std::get<2>(i) == 0){
           m_items.push_back(FormatItem::ptr(new StringFormatItem(std::get<0>(i))));
        } else {
            auto it = s_format_items.find(std::get<0>(i));
            if(it == s_format_items.end()) {
               m_items.push_back(FormatItem::ptr(new StringFormatItem("<<error_fomat %" + std::get<0>(i) + ">>")));
            } else {    
                m_items.push_back(it->second(std::get<1>(i)));       
            }
        } 

        // std::cout <<"(" << std::get<0>(i) << ") - (" << std::get<1>(i) << ") - (" << std::get<2>(i) << ")"<< std::endl;
    }
    // std::cout<< m_items.size() << std::endl;
}


LoggerManager::LoggerManager(){
    m_root.reset(new Logger);
    m_root->addAppender(LogAppender::ptr(new StdoutLogAppender));
};
Logger::ptr LoggerManager::getLogger(const std::string& name){
    auto it = m_loggers.find(name);
    return it == m_loggers.end() ? m_root : it->second;
};



}