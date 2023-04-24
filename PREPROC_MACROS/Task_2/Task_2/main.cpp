#include <iostream>
#define SUB(num1, num2) ((num1) - (num2))

int main() {
    int num1 = 6;
    int num2 = 5;
    int num3 = 2;
    
    std::cout << SUB(num1, num2) << std::endl;
    std::cout << SUB(num1, num2) * num3 << std::endl;
    std::cout << SUB(num1, num2 + num3) * num3 << std::endl;
    
    return 0;
}
