#include <iostream>
#include <fstream>
#include <string>

int ADDRESSES_COUNT = 0;
class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;
public:
    void SetAddress(std::ifstream& inFile) {
        inFile >> city >> street >> house >> apartment;
    }
    std::string GetCity() const {
        return city;
    }
    std::string GetStreet() const {
        return street;
    }
    int GetHouse() const {
        return house;
    }
    int GetApartment() const {
        return apartment;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");\
    
    std::ifstream inFile("in.txt");
    inFile >> ADDRESSES_COUNT;
    Address* address = new Address[ADDRESSES_COUNT];
    
    for (int i = 0; i < ADDRESSES_COUNT; ++i) {
        address[i].SetAddress(inFile);
    }
    
    std::sort(address, address + ADDRESSES_COUNT, [](const Address& lhs, const Address& rhs) {
        return lhs.GetCity() < rhs.GetCity();
    });
    
    std::ofstream outFile("out.txt");
    outFile << ADDRESSES_COUNT << "\n";
    for (int i = 0; i < ADDRESSES_COUNT; ++i) {
        outFile << address[i].GetCity() << ", ";
        outFile << address[i].GetStreet() << ", ";
        outFile << address[i].GetHouse() << ", ";
        outFile << address[i].GetApartment() << "\n";
    }
    
    inFile.close();
    outFile.close();
    delete[] address;
    return 0;
}
