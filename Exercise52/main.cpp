#include "function.h"
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    ifstream ans("CorrectAnswers.txt");
    ifstream stu("StudentAnswers.txt");
    int ansCount = 0;
    int stuCount = 0;
    char* ansArr = nullptr;
    char* stuArr = nullptr;
    if (!readDataFromFile(ans, ansCount, ansArr) || 
        !readDataFromFile(stu, stuCount, stuArr)) {
        cout << "Error reading input files.\n";
        delete[] ansArr;
        delete[] stuArr;
        return 1;
    }

    int missed = abs(ansCount - stuCount);
    if (missed > 0) {
        cout << "You did not answer the last " << missed << " answer\n";
        cout << "=============================================================\n";

    }
    for (int i = 0; i < max(ansCount, stuCount); i++) {
        if (ansArr[i] != stuArr[i]) {
            missed++;
            cout << "===========================================================\n";
            cout << "Question " << i + 1 << " is missed." << '\n';
            cout << "Your answer: " << stuArr[i] << '\n';
            cout << "Correct answer: " << ansArr[i] << '\n';
        }
    }
    cout << "=============================================================\n";
    cout << "Number of missed questions: " << missed << '\n';
    cout << fixed << setprecision(2) << "Percentage of question answered correctly: " << (100.0 * (ansCount - missed) / ansCount) << "%\n";

    delete[] ansArr;
    delete[] stuArr;
    return 0;
}


