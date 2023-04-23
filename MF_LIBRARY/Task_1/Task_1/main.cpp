#include <iostream>
#include "adding.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"
#include "power.h"

int main() {
    int num1, num2 = 0;
    int operation = 0;
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;
    switch(operation) {
        case(1): Adding(num1, num2); break;
        case(2): Subtraction(num1, num2); break;
        case(3): Multiplication(num1, num2); break;
        case(4): Division(num1, num2); break;
        case(5): Power(num1, num2); break;
    }
    
    return 0;
}
