#pragma once
#include "parallelogram.h"

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B);
    Rhombus(int a, int A, std::string name);
};
