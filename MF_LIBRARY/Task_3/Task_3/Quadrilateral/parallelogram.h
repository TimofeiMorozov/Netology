#pragma once
#include "quadrilateral.h"

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B);
    Parallelogram(int a, int A, int B, std::string name);
    Parallelogram(std::string name, int a, int b, int A);
    Parallelogram(int a, int A, std::string name);
};
