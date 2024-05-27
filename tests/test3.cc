#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    std::cout << "Before clear: " << str << std::endl; // 输出: "Hello, World!"
    
    str.clear(); // 清空字符串
    
    std::cout << "After clear: " << str << std::endl; // 输出: ""
    std::cout << "Length after clear: " << str.length() << std::endl; // 输出: 0

    return 0;
}
