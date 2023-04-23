#include <iostream>
#include "figure.h"
#include <string>

Figure::Figure() {
    sides_count = 0;
    name = "Фигура";
}

Figure::Figure(int sides_count, std::string name) {
    this->sides_count = sides_count;
    this->name = name;
}

int Figure::GetCount() const {
    return sides_count;
}

std::string Figure::GetName() const {
    return name;
}

void Figure::PrintInfo() const {
    std::cout << GetName() << ":" << std::endl;
}
