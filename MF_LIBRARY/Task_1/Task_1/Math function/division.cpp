#include <iostream>
#include "division.h"

double Division(int num1, int num2) {
    std::cout << num1 << " / " << num2 << " = " << static_cast<double>(num1) / static_cast<double>(num2) << std::endl;
    return 0;
}
