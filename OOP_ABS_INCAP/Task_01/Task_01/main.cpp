#include <iostream>
#include <fstream>
#include <string>

const int COUNT_VARIABLES = 4;
class Address {
private:
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;
    
    template <typename T>
    void SetCity(T p_city) {
        city = p_city;
    }
    template <typename T>
    T GetCity(T p_city) {
        p_city = city;
        return p_city;
    }
    
    template <typename T>
    void SetStreet(T p_street) {
        street = p_street;
    }
    template <typename T>
    T GetStreet(T p_street) {
        p_street = street;
        return p_street;
    }
    
    template <typename T>
    void SetHouse(T p_house) {
        house = p_house;
    }
    template <typename T>
    T GetHouse(T p_house) {
        p_house = house;
        return p_house;
    }
    
    template <typename T>
    void SetApartment(T p_apartment) {
        apartment = p_apartment;
    }
    template <typename T>
    T GetApartment(T p_apartment) {
        p_apartment = apartment;
        return p_apartment;
    }
public:
    template <typename T>
    T Print(T temp, int index) {
        switch (index) {
            case 1:
                SetCity(temp);
                return GetCity(temp);
                break;
            case 2:
                SetStreet(temp);
                return GetStreet(temp);
                break;
            case 3:
                SetHouse(temp);
                return GetHouse(temp);
                break;
            case 4:
                SetApartment(temp);
                return GetApartment(temp);
                break;
        }
        return 0;
    }
};

int main() {
    int N = 0;
    
    std::ifstream inFile("in.txt");
    if(inFile.is_open()) {
        inFile >> N;
    } else {
        std::cout << "Please check your file or it's name" << std::endl;
    }
    
    std::ofstream outFile("out.txt");
    outFile << N << "\n";
    
    Address address;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= COUNT_VARIABLES; ++j) {
            //Хотелось бы узнать, можно ли как-то сделать более универсально здесь ?
            //Что бы можно было поставить числовые переменные как числовой тип. В этом месте так и не разобрался.
            std::string temp = " ";
            inFile >> temp;
            outFile << address.Print(temp, j) << ", ";
        }
        outFile << "\n";
    }
    
    inFile.close();
    outFile.close();
    
    return 0;
}
