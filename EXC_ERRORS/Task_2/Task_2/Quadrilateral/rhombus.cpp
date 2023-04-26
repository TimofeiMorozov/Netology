#include "rhombus.h"

bool Rhombus::RhombusCheck(int a, int b, int c, int d, int A, int B, int C, int D) {
    if (a != c || a != b || b != c) {
        throw std::domain_error("все стороны должны быть равны");
        return false;
    }
    return true;
}

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, A, B, "Ромб") {
    //a = c = 15;
    RhombusCheck(a, b, c, d, A, B, C, D);
}
Rhombus::Rhombus(int a, int A, std::string name) : Parallelogram(a, A, name) {
    RhombusCheck(a, b, c, d, A, B, C, D);
}
