#include <iostream>
//Class with different operation with nums
class Calculator {
    private:
        double num1;
        double num2;
    public:
        //Sum of two numbers
        double Add() {
            return num1 + num2;
        }
        //Multiply two numbers
        double Multiply() {
            return num1 * num2;
        }
        //Subtract num2 from num1
        double Subtract_1_2() {
            return num1 - num2;
        }
        //Subtract num1 from num2
        double Subtract_2_1() {
            return num2 - num1;
        }
        //Divide num1 to num2
        double Divide_1_2() {
            return num1 / num2;
        }
        //Divide num2 to num1
        double Divide_2_1() {
            return num2 / num1;
        }
        //Check that num1 != 0
        bool SetNum1(double num1) {
            if(num1 != 0) {
                this->num1 = num1;
                return true;
            } else {
                return false;
            }
        }
        //Check that num2 != 0
        bool SetNum2(double num2) {
            if(num2 != 0) {
                this->num2 = num2;
                return true;
            } else {
                return false;
            }
        }
        //Ask user to type two numbers
        void Result() {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            while(!SetNum1(num1)) {
                std::cout << "Неверный ввод!" << std::endl;
                std::cout << "Введите num1: ";
                std::cin >> num1;
            }

            std::cout << "Введите num2: ";
            std::cin >> num2;
            while(!SetNum2(num2)) {
                std::cout << "Неверный ввод!" << std::endl;
                std::cout << "Введите num2: ";
                std::cin >> num2;
            }
        }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Calculator calculator;

    while(true) {
        calculator.Result();
        std::cout << "num1 + num2 = " << calculator.Add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.Subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator.Subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calculator.Multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.Divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.Divide_2_1() << std::endl;
    }

    return 0;
}
