#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(int a) : Triangle(a, 60, "Равносторонний треугольник") {
    if ((a != b) || (a != c) || (b != c)) {
        throw std::domain_error("все стороны должны быть равны");
    } else if ((A != B) || (A != C) || (B != C)) {
        throw std::domain_error("все углы должны быть равны");
    }
}
