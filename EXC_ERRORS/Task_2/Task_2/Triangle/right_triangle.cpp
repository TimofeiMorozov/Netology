#include "right_triangle.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
    if((A != 90) && (B != 90) && (C != 90)) {
        throw std::domain_error("хотя бы один угол должен быть равен 90");
    }
}
