#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int ADDRESSES_COUNT = 0;
int CLASS_OBJECT_COUNT = 4;
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
    std::string GetCity() {
        return city;
    }
    std::string GetStreet() {
        return street;
    }
    int GetHouse() {
        return house;
    }
    int GetApartment() {
        return apartment;
    }
};

void PrintOut (const std::vector<std::vector<std::string>>& addresses, std::ofstream& outFile) {
    for (int i = (ADDRESSES_COUNT - 1); i >= 0; --i) {
        for (int j = 0; j < (CLASS_OBJECT_COUNT - 1); ++j) {
            outFile << addresses[i][j] << ", ";
        }
        outFile << addresses[i][CLASS_OBJECT_COUNT - 1] << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Address address;
    std::vector<std::vector<std::string>> addresses;
    
    std::ifstream inFile("in.txt");
    std::ofstream outFile("out.txt");
    
    inFile >> ADDRESSES_COUNT;
    outFile << ADDRESSES_COUNT << "\n";
    for (int i = 0; i < ADDRESSES_COUNT; ++i) {
        std::vector<std::string> full_address;
        address.SetAddress(inFile);
        full_address = {address.GetCity(),
                        address.GetStreet(),
                        std::to_string(address.GetHouse()),
                        std::to_string(address.GetApartment())};
        addresses.push_back(full_address);
    }

    PrintOut(addresses, outFile);
    
    inFile.close();
    outFile.close();
    return 0;
}
