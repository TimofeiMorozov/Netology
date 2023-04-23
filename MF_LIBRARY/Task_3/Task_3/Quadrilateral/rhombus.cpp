#include "rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, A, B, "Ромб") {}
Rhombus::Rhombus(int a, int A, std::string name) : Parallelogram(a, A, name) {}
