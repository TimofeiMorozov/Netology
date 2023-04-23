#include <iostream>
#include <string>
#include "counter.h"
    
Counter::Counter(std::string& choice) {
    if(choice == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> counter;
    } else {
        counter = 1;
    }
}
    //Increace counter
    int Counter::IncreaseCounter() {
        return ++counter;
    }
    //Decrease counter
    int Counter::DecreaseCounter() {
        return --counter;
    }
    //Show value
    void Counter::ShowValue() {
        std::cout << counter << std::endl;
    }
