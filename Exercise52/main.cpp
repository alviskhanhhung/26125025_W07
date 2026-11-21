#include "function.h"
#include <iomanip>
#include <cmath>
using namespace std;
/*
    INPUT                              | OUTPUT
#TEST CASE 1: Base case - 20 questions, 4 missed (80.00% - Passed)
CorrectAnswers.txt: 20 (A B C D ...)   | =============================================================
StudentAnswers.txt: 20 (4 mismatches)  | Question 2 is missed.
                                       | Your answer: A
                                       | Correct answer: B
                                       | ... (4 missed questions listed)
                                       | =============================================================
                                       | Number of missed questions: 4
                                       | Percentage of question answered correctly: 80.00%
                                       | The student passed the exam.

#TEST CASE 2: Edge case 1 - Fewer student answers than total (unanswered trailing questions, < 70% Failed)
CorrectAnswers.txt: 5 (A B C D A)      | You did not answer the last 2 question(s).
StudentAnswers.txt: 3 (A C C)          | =============================================================
                                       | Question 2 is missed.
                                       | Your answer: C
                                       | Correct answer: B
                                       | (Questions 4, 5 unanswered)
                                       | =============================================================
                                       | Number of missed questions: 3
                                       | Percentage of question answered correctly: 40.00%
                                       | The student failed the exam.

#TEST CASE 3: Edge case 2 - Exact 70.00% passing threshold (20 questions, 6 missed)
CorrectAnswers.txt: 20 (all A)         | =============================================================
StudentAnswers.txt: 20 (14 A, 6 B)     | ... (6 missed questions listed)
                                       | =============================================================
                                       | Number of missed questions: 6
                                       | Percentage of question answered correctly: 70.00%
                                       | The student passed the exam.
*/
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
    for (int i = 0; i < min(ansCount, stuCount); i++) {
        if (ansArr[i] != stuArr[i]) {
            missed++;
            cout << "===========================================================\n";
            cout << "Question " << i + 1 << " is missed." << '\n';
            cout << "Your answer: " << stuArr[i] << '\n';
            cout << "Correct answer: " << ansArr[i] << '\n';
        }
    }
    if (stuCount < ansCount) {
    cout << "You did not answer the last " << (ansCount - stuCount) << " question(s).\n";
    for (int i = stuCount; i < ansCount; i++) {
        missed++;
        cout << "===========================================================\n";
        cout << "Question " << i + 1 << " is missed (unanswered).\n";
        cout << "Correct answer: " << ansArr[i] << '\n';
    }
}
    cout << "=============================================================\n";
    cout << "Number of missed questions: " << missed << '\n';
    double percentage = (100.0 * (ansCount - missed) / ansCount);
    cout << fixed << setprecision(2) << "Percentage of question answered correctly: " << percentage << "%\n";
    if (percentage >= 70.0) {
        cout << "passed\n";
    } else {
        cout << "failed\n";
    }
    delete[] ansArr;
    delete[] stuArr;
    return 0;
}


