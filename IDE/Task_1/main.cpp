#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russia");
    int arr1_size = 0;
    int arr2_size = 0;


    std::ifstream inFile("in.txt");
    //Проверка существования файла с исходными данными
    if(!inFile.is_open()) {
        std::cout << "Please check that your file is exist and has correct name" << std::endl;
        return 0;
    }
    //Создание и заполнение первого массива
    inFile >> arr1_size;
    int *arr1 = new int[arr1_size]();
    for(int i = 0; i < arr1_size; ++i) {
        inFile >> arr1[i];
    }
    //Создание и заполнение второго массива
    inFile >> arr2_size;
    int *arr2 = new int[arr2_size]();
    for(int i = 0; i < arr2_size; ++i) {
        inFile >> arr2[i];
    }
    //Сдвиг влево данных в первом массиве
    int temp = arr1[0];
    for(int i = 0; i < (arr1_size - 1); ++i) {
        arr1[i] = arr1[i + 1];
    }
    arr1[arr1_size - 1] = temp;
    //Сдвиг вправо данных во втором массиве
    temp = arr2[arr2_size - 1];
    for(int i = (arr2_size - 1); i >= 0; --i) {
        arr2[i + 1] = arr2[i];
    }
    arr2[0] = temp;
    //Вывод в файл размера и значений из второго массива
    std::ofstream outFile("out.txt");
    outFile << arr2_size << std::endl;
    for(int i = 0; i < arr2_size; ++i) {
        outFile << arr2[i] << " ";
    }
    //Вывод в файл размера и значений из первого массива
    outFile << std::endl;
    outFile << arr1_size << std::endl;
    for(int i = 0; i < arr1_size; ++i) {
        outFile << arr1[i] << " ";
    }
    //Закрытие файлов
    inFile.close();
    outFile.close();
    //Освобождение памяти
    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;

    return 0;
}