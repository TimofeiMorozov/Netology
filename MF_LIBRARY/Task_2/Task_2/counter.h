#pragma once

class Counter {
private:
    int counter;
public:
    Counter(std::string& choice);
    int IncreaseCounter();
    int DecreaseCounter();
    void ShowValue();
};
