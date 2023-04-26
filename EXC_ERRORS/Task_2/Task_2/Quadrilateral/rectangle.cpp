#include "rectangle.h"

Rectangle::Rectangle(int a, int b) : Parallelogram("Прямоугольник", a, b, 90) {
    if (A != 90 || B != 90 || C != 90 || D != 90) {
        throw std::domain_error("все углы должны быть равны 90");
    }
}
