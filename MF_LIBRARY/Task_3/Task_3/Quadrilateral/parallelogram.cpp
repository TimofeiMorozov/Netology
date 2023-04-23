#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B, "Параллелограмм") {}
Parallelogram::Parallelogram(int a, int A, int B, std::string name) : Quadrilateral(name) {
    this->a = b = c = d = a;
    this->A = C = A; this->B = D = B;
}
Parallelogram::Parallelogram(std::string name, int a, int b, int A) : Quadrilateral(name) {
    this->a = c = a; this->b = d = b;
    this->A = B = C = D = A;
}
Parallelogram::Parallelogram(int a, int A, std::string name) : Quadrilateral(name) {
    this->a = b = c = d = a;
    this->A = B = C = D = A;
}
