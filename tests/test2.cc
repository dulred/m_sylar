#include <iostream>
#include "../sylar/log.h"
int main (int argc , char** argv){
    

    sylar::LogEvent::ptr event(new sylar::LogEvent(__FILE__, __LINE__, 0 , 1, 2, time(0)));
    event->getSS() << "hello sylar log i'm ok";

    std::cout << event->getContent() << std::endl;
    std::cout << event->getFile() << std::endl;
    return 0;
}