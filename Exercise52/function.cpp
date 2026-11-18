#include "function.h"
bool readDataFromFile(std::ifstream& in, int& n, char*& pArr) {
    if (!in.is_open() || !(in >> n) || n <= 0) {
        return false;
    }
    in.ignore();
    pArr = new char[n];
    for (int i = 0; i < n; i++) {
        if (!(in >> pArr[i])) {
            delete[] pArr;
            pArr = nullptr;
            return false;
        }
    }
    return true;
}
int* doubleSizeArray(int* arr, int& size) {
    int newSize = size * 2;
    int* newArr = new int[newSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
    return arr;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

}