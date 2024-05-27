#include <iostream>
#include "../sylar/log.h"
#include "../sylar/util.h"
int main (int argc , char** argv){
    
    sylar::Logger::ptr logger(new sylar::Logger);
    logger->addAppender(sylar::LogAppender::ptr(new sylar::StdoutLogAppender));

    // sylar::LogEvent::ptr event(new sylar::LogEvent(__FILE__, __LINE__, 0 , sylar::GetThreadId(), sylar::GetFiberId(), time(0)));
    // event->getSS() << "hello sylar log i'm ok";

    // logger->log(sylar::LogLevel::DEBUG,event);
    // std::cout << "hello sylar log" << std::endl;    
    SYLAR_LOG_INFO(logger) << "test macro";
    SYLAR_LOG_ERROR(logger) << "test macro error";


    return 0;
}