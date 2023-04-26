#pragma once
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;
    
public:
    Figure();
    Figure(int sides_count, std::string name);
    int GetCount() const;
    std::string GetName() const;
    virtual void PrintInfo() const;
};
