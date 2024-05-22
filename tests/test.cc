#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // 提取子字符串 "Hello"
    std::string sub1 = str.substr(0, 5);
    std::cout << "sub1: " << sub1 << std::endl; // 输出: sub1: Hello
    

    std::cout << "str: " << str << std::endl; // 输出: sub2: World
    
    return 0;
}
