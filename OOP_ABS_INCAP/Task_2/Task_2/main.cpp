#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int ADDRESS_VARIABLES = 4;
class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;
    std::vector<std::string> full_address;
    
    void SetCity(std::string city) {
        this->city = city;
    }
    void SetStreet(std::string street) {
        this->street = street;
    }
    void SetHouse(int house) {
        this->house = house;
    }
    void SetApartment(int apartment) {
        this->apartment = apartment;
    }

public:
    std::vector<std::vector<std::string>> addresses;
    std::vector<std::string> SetFullAddress(std::string t_city, std::string t_street, int t_house, int t_apartment) {
        full_address.clear();
        SetCity(t_city);
        SetStreet(t_street);
        SetHouse(t_house);
        SetApartment(t_apartment);
        full_address.push_back(city);
        full_address.push_back(street);
        full_address.push_back(std::to_string(house));
        full_address.push_back(std::to_string(apartment));
        return full_address;
    }
    
    void GetFullAddress(const std::vector<std::vector<std::string>>& addresses, int N) {
        std::ofstream outFile("out.txt");
        outFile << N << "\n";
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < ADDRESS_VARIABLES - 1; ++j) {
                outFile << addresses[i][j] << ", ";
            }
            outFile << addresses[i][ADDRESS_VARIABLES - 1] << "\n";
        }
        outFile.close();
    }
};

int main() {
    int N = 0;
    std::ifstream inFile("in.txt");
    if(inFile.is_open()) {
        inFile >> N;
    } else {
        std::cout << "Please check your file or it's name" << std::endl;
        return 0;
    }
    
    Address address;
    std::string city = " ";
    std::string street = " ";
    int house = 0;
    int apartment = 0;
    
    for (int i = 1; i <= N; ++i) {
            inFile >> city >> street >> house >> apartment;
        address.addresses.push_back(address.SetFullAddress(city, street, house, apartment));
    }
    //Sort data by first column
    sort(address.addresses.begin(), address.addresses.end(),
         [](const std::vector<std::string>& lhs, const std::vector<std::string>& rhs) {
        return lhs[0] < rhs[0];
    });
    
    address.GetFullAddress(address.addresses, N);
    
    inFile.close();
    return 0;
}
