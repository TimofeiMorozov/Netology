#include <iostream>
#include <string>

class Figure {
private:
    int GetCount() {
        return sides_count;
    }
    std::string GetName() {
        return name;
    }
    
protected:
    int sides_count = 0;
    std::string name = "Фигура";
    
public:
    Figure() {}
    
    Figure(int sides_count, std::string name) {
        this->sides_count = sides_count;
        this->name = name;
    }
    
    void Print() {
        std::cout << GetName() << ": " << GetCount() << std::endl;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() : Figure(4, "Четырехугольник") {}
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;
    
    std::cout << "Количество сторон:" << std::endl;
    figure.Print();
    triangle.Print();
    quadrilateral.Print();
    
    return 0;
}
