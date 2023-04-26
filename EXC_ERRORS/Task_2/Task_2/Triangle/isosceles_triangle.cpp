#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, A, B, "Равнобедренный треугольник") {
    if(a != c) {
        throw std::domain_error("минимум две стороны должны быть равны");
    } else if (A != C) {
        throw std::domain_error("минимум два угла должны быть равны");
    }
}
