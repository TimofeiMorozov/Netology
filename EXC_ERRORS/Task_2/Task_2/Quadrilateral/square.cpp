#include "square.h"

Square::Square(int a) : Rhombus::Rhombus(a, 90, "Квадрат") {
    if (A != 90 || B != 90 || C != 90 || D != 90) {
        throw std::domain_error("все углы должны быть равны 90");
    }
}
