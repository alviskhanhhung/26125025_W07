#include "function.h"
using namespace std;
/*
    INPUT                                              | OUTPUT
#TEST CASE 1: Base case - standard course operations (add, remove, search, sort)
CSC10001|Intro to Programming|open|30|2                | Status: open (3 students); K19: Tuan-Thanh Ho; Search "thanh": Tuan-Thanh Ho
19125001|Tuan-Thanh Ho|3.6|15/5/2001                   |
26125025|Khanh-Hung Lam|3.5|1/11/2000                  |
26125026|Minh-Duc Tran|3.8|1/2/2000                    |
Add: 26125075|Quynh-Thi Nguyen|3.7|20/3/2000           |
Remove ID: 26125025 | Search: "thanh"                  |

#TEST CASE 2: Edge case - removal below minStudent closes course & multi-match case-insensitive search
CSC10002|Data Structures|open|30|3                     | Status: close (2 students < min 3); Search "duc": Minh-Duc Tran, Trung-Duc Tran
26125026|Minh-Duc Tran|3.8|1/2/2000                    |
26125027|Trung-Duc Tran|3.9|1/4/2000                   |
26125028|An-Binh Le|3.4|10/8/2000                      |
Remove ID: 26125028 | Search: "duc"                    |

#TEST CASE 3: Edge case - empty input file
                                                       | Cannot read data from file
*/
bool readStudentData(ifstream& in, Student& student) {
    if (!in) {
        return false;
    }
    string temp;
    if (!getline(in, temp, '|')) return false;
    student.id = stoi(temp);
    getline(in, student.name, '|');
    getline(in, temp, '|');
    student.gpa = stod(temp);
    getline(in, temp, '/');
    student.DoB.day = stoi(temp);
    getline(in, temp, '/');
    student.DoB.month = stoi(temp);
    getline(in, temp);
    student.DoB.year = stoi(temp);
    return true;
}
int main() {
    string inFile = "course.txt";
    string outFile = "output.txt";
    Course course;
    
    //1. Input a course
    ifstream fin(inFile);
    if (!readDataFromFile(fin, course)) {
        cout << "Cannot read data from file\n";
        return 1;
    }
    fin.close();
    
    //2. Output a course
    ofstream fout(outFile);
    fout << "======Initial data======\n";
    if (!writeDataToFile(fout, course)) {
        cout << "Cannot write data to file\n";
    }

    //3.add a student
    ifstream in("newStudent.txt");
    Student newStudent;
    if (readStudentData(in, newStudent)) {
        if (!addStudentToCourse(course, newStudent)) {
            cout << "Course has reached maximum attendance\n";
        }
        fout << "======Add student (" << newStudent.id << ")======\n";
        writeDataToFile(fout, course);
    }
    in.close();

    //4.remove a student
    int studentId = 26125076;
    if (!removeStudentFromCourse(course, studentId)) {
        cout << "Student not found or the course has reached minimum attendance\n";
    }
    fout << "======remove student ("<< studentId << ")======\n";
    writeDataToFile(fout, course);

    //5.Student born this month
    sameMonthAsCurrent(course);
    cout << "\n\n";

    //6.Student born this date
    sameDateAsCurrent(course);
    cout << "\n\n";

    //7.Student old enough to get driving license
    isEighteen(course);
    cout << '\n';

    //8.Student in K19
    findStudentFromClassK19(course, fout);
    cout << '\n';

    //9. find student by id
    if (!findStudentById(course, 26125025, fout)) {
        cout << "Could not find student with id: 26125025\n";
    }

    //10. find student by name
    if (!findStudentByName(course, "thanh", fout)) {
        cout << "Could not find student with name: thanh\n";
    }

    //11. sort student by id
    sortById(course);
    fout << "======Student sorted by id======\n";
    writeDataToFile(fout, course);
    //12. sort student by first name
    sortByFirstName(course);
    fout << "======Student sorted by first name======\n";
    writeDataToFile(fout, course);

    //13. sort student by gpa
    sortByGPA(course);
    fout << "======Student sorted by gpa======\n";
    writeDataToFile(fout, course);

    //14. sort student by date of birth
    sortByDoB(course);
    fout << "======Student sorted by date of birth======\n";
    writeDataToFile(fout, course);
    
    fout.close();
    return 0;
}