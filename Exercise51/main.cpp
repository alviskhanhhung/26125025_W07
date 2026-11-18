#include "function.h"
using namespace std;
int main() {
    int maxValue = 0;
    int sum = 0;
    int val = 5;
    int pos = 2;
    int n{};
    cout << "Input number of element: ";
    cin >> n;
    int* pArr = nullptr;
    if (!inputArray(n, pArr)) {
        return 0;
    }
    outputArray(n, pArr);
    cout << '\n';
    arrayManipulation(n, pArr, sum, maxValue);
    cout << "sum: " << sum << '\n';
    cout << "max value: " << maxValue << '\n';
    outputArray(n, pArr);
    cout << '\n';
    insertValueToKthPosition(n, pArr, pos, val);
    outputArray(n, pArr);
    delete[] pArr;
    return 0;
}