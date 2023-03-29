#include <iostream>
//Структура для хранения полного адреса
struct Address {
    std::string country;
    std::string city;
    std::string street;
    int building;
    int apartment_number;
    int postcode;
};
//Функция вывода адреса на экран
void PrintAddress(const Address& address) {
    std::cout  << "Страна: " << address.country << std::endl;
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.building << std::endl;
    std::cout << "Номер квартиры: " << address.apartment_number << std::endl;
    std::cout << "Индекс: " << address.postcode << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Address address = {"Россия", "Москва", "Мичуринский проспект", 5, 23, 123456};
    PrintAddress(address);

    return 0;
}