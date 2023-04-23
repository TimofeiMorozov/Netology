#include <iostream>
#include <string>
#include "counter.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::string choice = " ";
    char sign = ' ';
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choice;
    Counter number(choice);
    
    do {
        switch (sign) {
            case '+':
                number.IncreaseCounter();
                break;
            case '-':
                number.DecreaseCounter();
                break;
            case '=':
                number.ShowValue();
                break;
        }
        
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> sign;
    } while(sign != 'x');
    std::cout << "До свидания!" <<std::endl;
    
    return 0;
}
