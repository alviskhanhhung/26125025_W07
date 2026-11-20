#include "function.h"
using namespace std;
bool readStudentData(ifstream& in, Student student) {
    string temp;
    getline(in, temp, '|');
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
        return 1;
    }

    //3.add a student
        ifstream in("newStudent.txt");
        Student newStudent;
        readStudentData(in, newStudent);
        if (!addStudentToCourse(course, newStudent)) {
            cout << "Course has reached maximum attendance\n";
            return 1;
        }
        fout << "======Add student ("<< newStudent.id << ")======\n";
        writeDataToFile(fout, course);

    //4.remove a student
    int studentId = 26125076;
    if (!removeStudentFromCourse(course, studentId)) {
        cout << "Student not found or the course has reached minimum attendance\n";
    }
    fout << "======remove student ("<< studentId << ")======\n";
    writeDataToFile(fout, course);

    //5.Student born this month
    sameMonthAsCurrent(course);
    cout << '\n';

    //6.Student born this date
    sameDateAsCurrent(course);
    cout << '\n';

    //7.Student old enough to get driving license
    isEighteen(course);
    cout << '\n';

    //8.Student in K19
    findStudentFromClassK19(course) {
        
    }
    
}