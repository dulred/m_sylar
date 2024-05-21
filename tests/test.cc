#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";

    // 访问字符串中的第一个字符
    char firstChar = str[2];
    std::cout << "First character: " << firstChar << str.size() <<std::endl;

    // 修改字符串中的第一个字符
    str[0] = 'h';
    std::cout << "Modified string: " << str << std::endl;

    return 0;
}
