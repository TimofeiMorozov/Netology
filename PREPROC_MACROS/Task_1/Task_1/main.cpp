#include <iostream>

#define MODE 1
#ifndef MODE
#error You should define MODE
#endif

#if MODE == 1
    const int Add (int const num1, int const num2) {
        return num1 + num2;
    }
#endif

int main() {
    setlocale(LC_ALL, "Russian");

#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    int num1, num2 = 0;
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> num1;
    std::cout << "Введите число 2: ";
    std::cin >> num2;
    std::cout << "Результат сложения: " << Add(num1, num2) << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
    
    return 0;
}
