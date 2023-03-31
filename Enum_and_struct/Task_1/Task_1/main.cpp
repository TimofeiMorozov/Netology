#include <iostream>
#include <string>
#include <vector>

enum class Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    setlocale(LC_ALL, "Russian");
    int month = 1;
    std::vector<std::string> months = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    
    while(true) {
        std::cout << "Введите номер месяца: ";
        std::cin >> month;
        
        if(month == 0) {
            std::cout << "До свидания!" << std::endl;
            return 0;
        }
        
        Months temp = static_cast<Months>(month);
        if((month < 1) || (month > 12)) {
            std::cout << "Неправильный номер!" << std::endl;
        } else {
            std::cout << months[static_cast<int>(temp) - 1] << std::endl;;
        }
    }

    return 0;
}
