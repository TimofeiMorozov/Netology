#pragma once
#include <iostream>
#include "figure.h"

class Triangle : public Figure {
protected:
    int a, b, c; //sides
    int A, B, C; //angles
private:
    int GetSideA() const;
    int GetSideB() const;
    int GetSideC() const;
    int GetAngleA() const;
    int GetAngleB() const;
    int GetAngleC() const;
public:
    Triangle(int a, int b, int c, int A, int B, int C);
    Triangle(int a, int b, int c, int A, int B, int C, std::string name);
    Triangle(int a, int b, int A, int B, std::string name);
    Triangle(int a, int A, std::string name);
    void PrintInfo() const override;
};
