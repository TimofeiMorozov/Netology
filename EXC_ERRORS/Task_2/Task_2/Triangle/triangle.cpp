#include <iostream>
#include  "triangle.h"
#include <exception>

bool Triangle::TriangleCheck(int A, int B, int C) {
    if (sides_count != 3) {
        throw std::domain_error("количество сторон не равно 3");
        return false;
    } else if ((A + B + C) != 180) {
        throw std::domain_error("сумма углов не равна 180");
        return false;
    }
    return true;
}

Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "Треугольник") {
    this->a = a; this->b = b; this->c = c;
    this->A = A; this->B = B; this->C = C;
    TriangleCheck(A, B, C);
}
Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(3, name) {
    this->a = a; this->b = b; this->c = c;
    this->A = A; this->B = B; this->C = C;
    TriangleCheck(A, B, C);
}
Triangle::Triangle(int a, int b, int A, int B, std::string name) : Figure(3, name) {
    this->a = c = a; this->b = b;
    this->A = C = A; this->B = B;
    //a = 10; b = 20; c = 30;
    //A = 50; B = 60; C = 70;
    TriangleCheck(A, B, C);
}
Triangle::Triangle(int a, int A, std::string name) : Figure(3, name) {
    this->a = b = c = a;
    this->A = B = C = A;
    //a = 10; b = 20; c = 30;
    //A = 50; B = 60; C = 70;
    TriangleCheck(A, B, C);
}

int Triangle::GetSideA() const { return a; }
int Triangle::GetSideB() const { return b; }
int Triangle::GetSideC() const { return c; }
int Triangle::GetAngleA() const { return A; }
int Triangle::GetAngleB() const { return B; }
int Triangle::GetAngleC() const { return C; }

void Triangle::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "(стороны " << a << ", " << b << ", " << c << "; " << "углы " << A << ", " << B << ", " << C << ") создан" << std::endl;
}
