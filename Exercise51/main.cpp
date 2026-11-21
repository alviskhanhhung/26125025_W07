#include "function.h"
using namespace std;
/*
    INPUT        | OUTPUT
#TEST CASE 1: Base case - distinct positive integers, max in the middle
5                | Input number of element: 10 20 40 30 15
10 20 40 30 15   | sum: 115
                 | max value: 40
                 | 10 20 30 15
                 | 10 5 20 30 15
                 | 15 30 20 5 10

#TEST CASE 2: Edge case 1 - duplicate maximum values and negative integers
4                | Input number of element: -5 8 2 8
-5 8 2 8         | sum: 13
                 | max value: 8
                 | -5 2 8
                 | -5 5 2 8
                 | 8 2 5 -5

#TEST CASE 3: Edge case 2 - all identical elements (deletes index 0 boundary)
4                | Input number of element: 7 7 7 7
7 7 7 7          | sum: 28
                 | max value: 7
                 | 7 7 7
                 | 7 5 7 7
                 | 7 7 5 7
*/
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
    cout << '\n';
    reverseArray(n, pArr);
    outputArray(n, pArr);
    delete[] pArr;
    return 0;
}