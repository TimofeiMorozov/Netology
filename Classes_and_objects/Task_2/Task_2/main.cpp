#include <iostream>
#include <string>

class Counter {
private:
    int counter;
public:
    Counter(std::string& choice) {
        if(choice == "да") {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> counter;
        } else {
            counter = 1;
        }
    }
    //Increace counter
    int IncreaseCounter() {
        return ++counter;
    }
    //Decrease counter
    int DecreaseCounter() {
        return --counter;
    }
    //Show value
    void ShowValue() {
        std::cout << counter << std::endl;
    }
};

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
