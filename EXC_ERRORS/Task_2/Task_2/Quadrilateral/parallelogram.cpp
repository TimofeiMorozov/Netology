#include "parallelogram.h"

bool Parallelogram::ParallelogramCheck(int a, int b, int c, int d, int A, int B, int C, int D) {
    if ((a != c) || (b != d)) {
        throw std::domain_error("стороны должны быть попарно равны");
        return false;
    } else if ((A != C) || (B != D)) {
        throw std::domain_error("углы должны быть попарно равны");
        return false;
    }
    return true;
}

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B, "Параллелограмм") {
    //a = 10;
    //A = 10;
    ParallelogramCheck(a, b, c, d, A, B, C, D);
}
Parallelogram::Parallelogram(int a, int A, int B, std::string name) : Quadrilateral(name) {
    this->a = b = c = d = a;
    this->A = C = A; this->B = D = B;
    //a = 10;
    //A = 10;
    ParallelogramCheck(a, b, c, d, A, B, C, D);
}
Parallelogram::Parallelogram(std::string name, int a, int b, int A) : Quadrilateral(name) {
    this->a = c = a; this->b = d = b;
    this->A = B = C = D = A;
    //a = 10;
    //A = 10;
    //A = 120; B = 60; C = 120; D = 60;
    ParallelogramCheck(a, b, c, d, A, B, C, D);
}
Parallelogram::Parallelogram(int a, int A, std::string name) : Quadrilateral(name) {
    this->a = b = c = d = a;
    this->A = B = C = D = A;
    //a = 10;
    //A = 10;
    ParallelogramCheck(a, b, c, d, A, B, C, D);
}
