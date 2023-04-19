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
    int GetCount() const {
        return sides_count;
    }
    std::string GetName() const {
        return name;
    }
    virtual void PrintInfo() const {
        std::cout << GetName() << ":" << std::endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c; //sides
    int A, B, C; //angles
private:
    int GetSideA() const { return a; }
    int GetSideB() const { return b; }
    int GetSideC() const { return c; }
    int GetAngleA() const { return A; }
    int GetAngleB() const { return B; }
    int GetAngleC() const { return C; }
public:
    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "Треугольник") {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    }
    Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Figure(3, name) {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    }
    Triangle(int a, int b, int A, int B, std::string name) : Figure(3, name) {
        this->a = c = a; this->b = b;
        this->A = C = A; this->B = B;
    }
    Triangle(int a, int A, std::string name) : Figure(3, name) {
        this->a = b = c = a;
        this->A = B = C = A;
    }
    void PrintInfo() const override {
        Figure::PrintInfo();
        std::cout << "Стороны: " << "a=" << GetSideA() << " " << "b=" << GetSideB() << " " << "c=" << GetSideC() << std::endl;
        std::cout << "Углы: " << "A=" << GetAngleA() << " " << "B=" << GetAngleB() << " " << "C=" << GetAngleC() << std::endl;
    }
};

class RigthTriangle : public Triangle {
public:
    RigthTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, A, B, "Равнобедренный треугольник") {}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, 60, "Равносторонний треугольник") {}
};


class Quadrilateral : public Figure {
protected:
    int a, b, c, d; //sides
    int A, B, C, D; //angles
private:
    int GetSideA() const { return a; }
    int GetSideB() const { return b; }
    int GetSideC() const { return c; }
    int GetSideD() const { return d; }
    int GetAngleA() const { return A; }
    int GetAngleB() const { return B; }
    int GetAngleC() const { return C; }
    int GetAngleD() const { return D; }
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4, "Четырехугольник") {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;
    }
    Quadrilateral(int a, int b, int A, int B, std::string name) : Figure(4, name) {
        this->a = c = a; this->b = d = b;
        this->A = C = A; this->B = D = B;
    }
    Quadrilateral(std::string name) : Figure(4, name) {}
    
    void PrintInfo() const override {
        Figure::PrintInfo();
        std::cout << "Стороны: " << "a=" << GetSideA() << " " << "b=" << GetSideB() << " " << "c=" << GetSideC() << " " << "d=" << GetSideD() << std::endl;
        std::cout << "Углы: " << "A=" << GetAngleA() << " " << "B=" << GetAngleB() << " " << "C=" << GetAngleC() << " " << "D=" << GetAngleD() << std::endl;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, A, B, "Параллелограмм") {}
    Parallelogram(int a, int A, int B, std::string name) : Quadrilateral(name) {
        this->a = b = c = d = a;
        this->A = C = A; this->B = D = B;
    }
    Parallelogram(std::string name, int a, int b, int A) : Quadrilateral(name) {
        this->a = c = a; this->b = d = b;
        this->A = B = C = D = A;
    }
    Parallelogram(int a, int A, std::string name) : Quadrilateral(name) {
        this->a = b = c = d = a;
        this->A = B = C = D = A;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B) : Parallelogram(a, A, B, "Ромб") {}
    Rhombus(int a, int A, std::string name) : Parallelogram(a, A, name) {}
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram("Прямоугольник", a, b, 90) {}
};

class Square : public Rhombus {
public:
    Square(int a) : Rhombus(a, 90, "Квадрат") {}
};

void PrintInfo(const Figure* f) {
    f->PrintInfo();
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70);
    PrintInfo(triangle);
    delete triangle;
    Figure* right_triangle = new RigthTriangle(10, 20, 30, 50, 60);
    PrintInfo(right_triangle);
    delete right_triangle;
    Figure* isosceles_triangle = new IsoscelesTriangle(10, 20, 50, 60);
    PrintInfo(isosceles_triangle);
    delete isosceles_triangle;
    Figure* equilateral_triangle = new EquilateralTriangle(30);
    PrintInfo(equilateral_triangle);
    delete equilateral_triangle;
    
    Figure* quadrilateral = new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    PrintInfo(quadrilateral);
    delete quadrilateral;
    Figure* parallelogram = new Parallelogram(20, 30, 30, 40);
    PrintInfo(parallelogram);
    delete parallelogram;
    Figure* rhombus = new Rhombus(30, 30, 40);
    PrintInfo(rhombus);
    delete rhombus;
    Figure* rectangle = new Rectangle(10, 20);
    PrintInfo(rectangle);
    delete rectangle;
    Figure* square = new Square(20);
    PrintInfo(square);
    delete square;
    
    return 0;
}
