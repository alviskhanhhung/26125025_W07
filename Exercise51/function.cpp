#include "function.h"

bool inputArray(int n, int*&pArr){
    if (n <= 0) {
        pArr = nullptr;
        return false;
    }
    pArr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> *(pArr+i);
    }
    return true;
}

void outputArray(int n, int* pArr) {
    if (n <= 0 || pArr == nullptr) {
        return;
    }
    for (int i = 0; i < n; i++) {
        std::cout<<*(pArr+i) << " ";
    }
}

bool arrayManipulation(int& n, int*&pArr, int& sum, int& maxValue) {
    if (n <= 0 || pArr == nullptr) {
        return false;
    }
    sum = 0; maxValue = *pArr;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        sum += *(pArr+i);
        if (*(pArr+i) > maxValue) {
            maxValue = *(pArr+i);
            pos = i;
        }
    }
    for (int i = pos; i < n-1; i++) {
        *(pArr+i) = *(pArr+i+1);
    }
    n--;
    return true;
}

bool insertValueToKthPosition(int& n, int *&pArr, int pos, int val) {
    if (n < 0 || pos < 1 || pos > n + 1 || (n > 0 && pArr == nullptr)) {
        return false;
    }
    int* temp = new int[n + 1];
    for (int i = 0; i < n; i++) {
        *(temp+i) = *(pArr+i);
    }
    delete[] pArr;
    pArr = temp;

    for (int i = n; i >= pos; i--) {
        *(pArr+i) = *(pArr+i-1);
    }
    *(pArr+pos-1) = val;
    n++;
    return true;
}