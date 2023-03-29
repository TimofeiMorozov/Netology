#include <iostream>
//Структура для хранения информации о банковском счете
struct BankAccount {
    int account_number;
    std::string name;
    double balance;
};
//Функция изменения баланса банковского счета
void UpdateAccountBalance(BankAccount& account, double balance) {
    account.balance = balance;
}

int main() {
    setlocale(LC_ALL, "Russian");
    BankAccount account;
    double new_balance = 0;
    //Получаем всю необходимую информацию от пользователя
    std::cout << "Введите номер счёта: ";
    std::cin >> account.account_number;
    std::cout << "Введите имя владельца: ";
    std::cin >> account.name;
    std::cout << "Введите баланс: ";
    std::cin >> account.balance;
    std::cout << "Введите новый баланс: ";
    std::cin >> new_balance;
    //Изменяем баланс с новой суммой
    UpdateAccountBalance(account, new_balance);
    std::cout << "Ваш счёт: " << account.name << ", " << account.account_number << ", " << account.balance << std::endl;

    return 0;
}