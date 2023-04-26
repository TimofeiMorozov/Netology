#pragma once
#include "parallelogram.h"

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B);
    Rhombus(int a, int A, std::string name);
    bool RhombusCheck(int a, int b, int c, int d, int A, int B, int C, int D);
};
