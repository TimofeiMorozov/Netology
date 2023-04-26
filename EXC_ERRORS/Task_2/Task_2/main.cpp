#include <iostream>
#include <string>
#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrilateral.h"
#include "parallelogram.h"
#include "rhombus.h"
#include "rectangle.h"
#include "square.h"

void PrintInfo(const Figure* f) {
    f->PrintInfo();
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    try {
        Figure* triangle = new Triangle(10, 20, 30, 50, 60, 70);
        PrintInfo(triangle);
        delete triangle;
        Figure* right_triangle = new RightTriangle(10, 20, 30, 40, 50);
        PrintInfo(right_triangle);
        delete right_triangle;
        Figure* isosceles_triangle = new IsoscelesTriangle(10, 20, 50, 80);
        PrintInfo(isosceles_triangle);
        delete isosceles_triangle;
        Figure* equilateral_triangle = new EquilateralTriangle(30);
        PrintInfo(equilateral_triangle);
        delete equilateral_triangle;
        
        Figure* quadrilateral = new Quadrilateral(10, 20, 30, 40, 90, 80, 90, 100);
        PrintInfo(quadrilateral);
        delete quadrilateral;
        Figure* parallelogram = new Parallelogram(20, 30, 90, 90);
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
    } catch (const std::exception& ex) {
        std::cout << "Ошибка создания фигуры. Причина: " << ex.what() << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}
