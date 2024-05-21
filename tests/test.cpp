#include <iostream>
#include <memory>

class LogEvent {
public:
    LogEvent() {
        std::cout << "LogEvent created" << std::endl;
    }
    ~LogEvent() {
        std::cout << "LogEvent destroyed" << std::endl;
    }
    void log() {
        std::cout << "Logging event" << std::endl;
    }
};

void sharedPointerExample() {
    // 创建一个 shared_ptr，引用计数为1
    std::shared_ptr<LogEvent> event1 = std::make_shared<LogEvent>();
    std::cout << "Reference count after event1 creation: " << event1.use_count() << std::endl;

    {
        // 创建第二个 shared_ptr，共享 event1 指向的对象，引用计数增加到2
        std::shared_ptr<LogEvent> event2 = event1; 
        std::cout << "Reference count after event2 creation: " << event1.use_count() << std::endl;

        // 使用 event2 访问对象的方法
        event2->log();
    } // event2 离开作用域，引用计数减少到1

    std::cout << "Reference count after event2 goes out of scope: " << event1.use_count() << std::endl;

    // event1 仍然指向对象，所以对象不会被销毁
    event1->log();
}

int main() {
    sharedPointerExample();
    // event1 离开作用域，引用计数减少到0，对象被销毁
    return 0;
}
