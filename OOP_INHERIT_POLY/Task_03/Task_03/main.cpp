#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;
public:
    Figure() {
        sides_count = 0;
        name = "Фигура";
    }
    Figure(int sides_count, std::string name) {
        this->sides_count = sides_count;
        this->name = name;
    }
    int GetCount() {
        return sides_count;
    }
    std::string GetName() {
        return name;
    }
    virtual bool Check() {
        if(sides_count == 0) {
            return true;
        } else {
            return false;
        }
    }
    virtual void PrintInfo() {
        std::cout << name << ":" << std::endl;
        if(Check()) {
            std::cout << "Правильная";
        } else {
            std::cout << "Неправильная";
        }
        std::cout << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c; //Sides
    int A, B, C; //Angles
private:
    int GetSideA() { return a; }
    int GetSideB() { return b; }
    int GetSideC() { return c; }
    int GetAngleA() { return A; }
    int GetAngleB() { return B; }
    int GetAngleC() { return C; }
public:
    Triangle() : Figure(3, "Треугольник") {
        a = 10; b = 20; c = 30;
        A = 50; B = 60; C = 70;
    }
    /* Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "Треугольник") {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    } */
    Triangle(int a, int b, int c, int A, int B) : Figure(3, "Прямоугольный треугольник") {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B;
    }
    Triangle(int a, int b, int A, int B) : Figure(3, "Равнобедренный треугольник") {
        this->a = a; this->b = b;
        this->A = A; this->B = B;
    }
    Triangle(int a) : Figure(3, "Равносторонний треугольник") {
        this->a = a;
    }
    
    bool Check() override {
        if(sides_count == 3 && (A + B + C == 180)) {
            return true;
        } else {
            return false;
        }
    }
    void PrintInfo() override {
        Figure::PrintInfo();
        std::cout << "Стороны: " << "a=" << a << " " << "b=" << b << " " << "c=" << c << std::endl;
        std::cout << "Углы: " << "A=" << A << " " << "B=" << B << " " << "C=" << C << std::endl;
    }
};
class RigthTriangle : public Triangle {
public:
    RigthTriangle() : Triangle(10, 20, 30, 50, 60) {
        C = 90;
    }
};
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : Triangle(10, 20, 50, 60) {
        c = a;
        C = A;
    }
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() : Triangle(30) {
        b = c = a;
        A = B = C = 60;
    }
};


class Quadrilateral : public Figure {
protected:
    int a, b, c, d; //sides
    int A, B, C, D; //angles
private:
    int GetSideA() { return a; };
    int GetSideB() { return b; };
    int GetSideC() { return c; };
    int GetSideD() { return d; };
    int GetAngleA() { return A; };
    int GetAngleB() { return B; };
    int GetAngleC() { return C; };
    int GetAngleD() { return D; };
public:
    Quadrilateral() : Figure(4, "Четырехугольник") {
        a = 10; b = 20; c = 30; d = 40;
        A = 50; B = 60; C = 70; D = 80;
    }
    /* Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4, "Четырехугольник") {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;
    } */
    Quadrilateral(int a, int b, int A, int B) : Figure(4, "Параллелограмм") {
        this->a = a; this->b = b;
        this->A = A; this->B = B;
    }
    
    bool Check() override {
        if(sides_count == 4 && (A + B + C + D == 360)) {
            return true;
        } else {
            return false;
        }
    }
    void PrintInfo() override {
        Figure::PrintInfo();
        std::cout << "Стороны: " << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "d=" << d << std::endl;
        std::cout << "Углы: " << "A=" << A << " " << "B=" << B << " " << "C=" << C << " " << "D=" << D << std::endl;
    }
};
class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Quadrilateral(20, 30, 30, 40) {
        c = a; d = b;
        C = A; D = B;
    }
    Parallelogram(int a, int A, int B, std::string name) : Quadrilateral() {
        this->a = a;
        this->A = A; this->B = B;
        this->name = name;
    }
    Parallelogram(int a, int b, std::string name) : Quadrilateral() {
        this->a = a; this->b = b;
        this->name = name;
    }
    Parallelogram(int a, std::string name) : Quadrilateral() {
        this->a = a;
        this->name = name;
    }
};
class Rhombus : public Parallelogram {
public:
    Rhombus() : Parallelogram(30, 30, 40, "Ромб") {
        b = c = d = a;
        C = A; D = B;
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle() : Parallelogram(10, 20, "Прямоугольник") {
        c = a; d = b;
        A = B = C = D = 90;
    }
};
class Square : public Parallelogram {
public:
    Square() : Parallelogram(20, "Квадрат") {
        d = c = b = a;
        A = B = C = D = 90;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Figure figure;
    figure.PrintInfo();
    std::cout << std::endl;
    
    Triangle triangle;
    triangle.PrintInfo();
    std::cout << std::endl;
    
    RigthTriangle right_triangle;
    right_triangle.PrintInfo();
    std::cout << std::endl;
    
    IsoscelesTriangle isosceles_triangle;
    isosceles_triangle.PrintInfo();
    std::cout << std::endl;
    
    EquilateralTriangle equilateral_triangle;
    equilateral_triangle.PrintInfo();
    std::cout << std::endl;
    
    Quadrilateral quadrilateral;
    quadrilateral.PrintInfo();
    std::cout << std::endl;
    
    Parallelogram parallelogram;
    parallelogram.PrintInfo();
    std::cout << std::endl;
    
    Rhombus rhombus;
    rhombus.PrintInfo();
    std::cout << std::endl;
    
    Rectangle rectangle;
    rectangle.PrintInfo();
    std::cout << std::endl;
    
    Square square;
    square.PrintInfo();
    std::cout << std::endl;
    
    return 0;
}
