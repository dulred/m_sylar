#include <iostream>
#include <sstream>
int main() {
   std::string str= "%d  [%p]  <%f:%l>  %m  %n";
   std::cout << str.size();
}
