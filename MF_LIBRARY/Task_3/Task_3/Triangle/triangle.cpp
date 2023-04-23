#include <iostream>
#include  "triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "Треугольник") {
    this->a = a; this->b = b; this->c = c;
    this->A = A; this->B = B; this->C = C;
}
Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(3, name) {
    this->a = a; this->b = b; this->c = c;
    this->A = A; this->B = B; this->C = C;
}
Triangle::Triangle(int a, int b, int A, int B, std::string name) : Figure(3, name) {
    this->a = c = a; this->b = b;
    this->A = C = A; this->B = B;
}
Triangle::Triangle(int a, int A, std::string name) : Figure(3, name) {
    this->a = b = c = a;
    this->A = B = C = A;
}

int Triangle::GetSideA() const { return a; }
int Triangle::GetSideB() const { return b; }
int Triangle::GetSideC() const { return c; }
int Triangle::GetAngleA() const { return A; }
int Triangle::GetAngleB() const { return B; }
int Triangle::GetAngleC() const { return C; }

void Triangle::PrintInfo() const {
    Figure::PrintInfo();
    std::cout << "Стороны: " << "a=" << GetSideA() << " " << "b=" << GetSideB() << " " << "c=" << GetSideC() << std::endl;
    std::cout << "Углы: " << "A=" << GetAngleA() << " " << "B=" << GetAngleB() << " " << "C=" << GetAngleC() << std::endl;
}
