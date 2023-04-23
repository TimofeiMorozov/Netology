#include <iostream>
#include <cmath>
#include "power.h"

int Power(int num1, int num2) {
    std::cout << num1 << " в степени " << num2 << " = " << pow(num1, num2) << std::endl;
    return 0;
}
