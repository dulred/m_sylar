#include <iostream>
#include <typeinfo>

int main() {
    int num = 10;
    double pi = 3.14159;

    std::cout << "Type of num: " << typeid(num).name() << std::endl;
    std::cout << "Type of pi: " << typeid(pi).name() << std::endl;

    return 0;
}
