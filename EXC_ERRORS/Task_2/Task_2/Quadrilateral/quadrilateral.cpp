#include <iostream>
#include <string>
#include "quadrilateral.h"

bool Quadrilateral::QuadrilateralCheck(int A, int B, int C, int D) {
    if (sides_count != 4) {
        throw std::domain_error("количество сторон не равно 4");
        return false;
    } else if ((A + B + C + D) != 360) {
        throw std::domain_error("сумма углов не равна 360");
        return false;
    }
    return true;
}

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4, "Четырехугольник") {
    QuadrilateralCheck(A, B, C, D);
    this->a = a; this->b = b; this->c = c; this->d = d;
    this->A = A; this->B = B; this->C = C; this->D = D;
}
Quadrilateral::Quadrilateral(int a, int b, int A, int B, std::string name) : Figure(4, name) {
    this->a = c = a; this->b = d = b;
    this->A = C = A; this->B = D = B;
    QuadrilateralCheck(A, B, C, D);
}
Quadrilateral::Quadrilateral(std::string name) : Figure(4, name) {}

int Quadrilateral::GetSideA() const { return a; }
int Quadrilateral::GetSideB() const { return b; }
int Quadrilateral::GetSideC() const { return c; }
int Quadrilateral::GetSideD() const { return d; }
int Quadrilateral::GetAngleA() const { return A; }
int Quadrilateral::GetAngleB() const { return B; }
int Quadrilateral::GetAngleC() const { return C; }
int Quadrilateral::GetAngleD() const { return D; }

void Quadrilateral::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "(стороны " << a << ", " << b << ", " << c << ", " << d << "; " << "углы " << A << ", " << B << ", " << C << ", " << D << ") создан" << std::endl;
}
