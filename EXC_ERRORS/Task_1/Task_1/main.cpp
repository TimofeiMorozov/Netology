#include <iostream>
#include <string>

int Function(std::string& str, int forbidden_length) {
    if(str.length() < forbidden_length) {
        throw std::runtime_error("Вы ввели слово запретной длины! До свидания");
    }
    else {
        return str.length();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int length = 0;
    std::string word = " ";
    std::cout << "Введите запретную длину: ";
    std::cin >> length;
    std::cout << "Введите слово: ";
    std::cin >> word;
    
    try {
        Function(word, length);
        std::cout << "Длина слова \"" << word << "\"" <<  " равна " << word.length() << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}
