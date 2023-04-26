#pragma once
#include <iostream>
#include <string>
#include "figure.h"

class Quadrilateral : public Figure {
protected:
    int a, b, c, d; //sides
    int A, B, C, D; //angles
    bool QuadrilateralCheck(int A, int B, int C, int D);
private:
    int GetSideA() const;
    int GetSideB() const;
    int GetSideC() const;
    int GetSideD() const;
    int GetAngleA() const;
    int GetAngleB() const;
    int GetAngleC() const;
    int GetAngleD() const;
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    Quadrilateral(int a, int b, int A, int B, std::string name);
    Quadrilateral(std::string name);
    
    void PrintInfo() const override;
};
