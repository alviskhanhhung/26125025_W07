#include "function.h"
using namespace std;

// Hàm phụ đọc 1 sinh viên từ file newStudent.txt để test chức năng thêm sinh viên
bool readSingleStudent(const string& filename, Student& st) {
    ifstream fin(filename);
    if (!fin) return false;

    string temp;
    if (!getline(fin, temp, '|')) return false;
    st.id = stoi(temp);
    getline(fin, st.name, '|');
    getline(fin, temp, '|');
    st.gpa = stod(temp);
    getline(fin, temp, '/');
    st.DoB.day = stoi(temp);
    getline(fin, temp, '/');
    st.DoB.month = stoi(temp);
    getline(fin, temp);
    st.DoB.year = stoi(temp);

    fin.close();
    return true;
}

int main() {
    string inFile = "course.txt";
    string outFile = "output.txt";
    Course course;

    // 1. Đọc dữ liệu khóa học từ file
    ifstream fin(inFile);
    if (!fin || !readDataFromFile(fin, course)) {
        cout << "Cannot read data from " << inFile << '\n';
        return 1;
    }
    fin.close();

    ofstream fout(outFile);
    if (!fout) {
        cout << "Cannot open " << outFile << '\n';
        return 1;
    }

    // 2. Xuất thông tin khóa học ban đầu ra file
    fout << "=== 1. INITIAL COURSE DATA ===\n";
    writeDataToFile(fout, course);

    // 3. Thêm sinh viên mới (đọc từ newStudent.txt) và kiểm tra maxStudent
    Student newStu;
    if (readSingleStudent("newStudent.txt", newStu)) {
        fout << "=== 2. ADD STUDENT (" << newStu.id << ") ===\n";
        if (addStudentToCourse(course, newStu)) {
            cout << "Added student " << newStu.name << " successfully.\n";
        } else {
            cout << "Course is full! Cannot add student.\n";
        }
        writeDataToFile(fout, course);
    }

    // 4. Xóa sinh viên theo ID và kiểm tra điều kiện minStudent
    int removeId = 26125026;
    fout << "=== 3. REMOVE STUDENT (" << removeId << ") ===\n";
    if (removeStudentFromCourse(course, removeId)) {
        cout << "Removed student ID " << removeId << " successfully.\n";
    } else {
        cout << "Cannot remove student ID " << removeId
             << " (not found or size <= minStudent).\n";
    }
    writeDataToFile(fout, course);

    // 5. Tìm sinh viên sinh trong tháng hiện tại (in ra console)
    cout << "\n--- Born in current month ---\n";
    sameMonthAsCurrent(course);
    cout << '\n';

    // 6. Tìm sinh viên sinh đúng ngày hiện tại (in ra console)
    cout << "\n--- Born on current date ---\n";
    sameDateAsCurrent(course);
    cout << '\n';

    // 7. Tìm sinh viên đủ 18 tuổi trở lên (in ra console)
    cout << "\n--- Eligible for driving licence (>= 18) ---\n";
    isEighteen(course);
    cout << "\n\n";

    // 8. Tìm sinh viên thuộc khóa K19 (chờ bổ sung hàm)
    // fout << "=== 4. STUDENTS IN K19 ===\n";
    // findStudentsInK19(course, fout);

    // 9. Tìm sinh viên theo ID (ghi ra file)
    fout << "=== 5. FIND BY ID ===\n";
    if (!findStudentById(course, 26125025, fout)) {
        fout << "Student ID 26125025 not found.\n";
    }
    fout << '\n';

    // 10. Tìm sinh viên theo tên (ghi ra file)
    fout << "=== 6. FIND BY NAME ===\n";
    if (!findStudentByName(course, "Duc", fout)) {
        fout << "No student matching 'Duc' found.\n";
    }
    fout << '\n';

    // 11. Sắp xếp theo ID -> ghi ra file
    fout << "=== 7. SORT BY ID ===\n";
    sortById(course);
    writeDataToFile(fout, course);

    // 12. Sắp xếp theo First Name -> ghi ra file
    fout << "=== 8. SORT BY FIRST NAME ===\n";
    sortByFirstName(course);
    writeDataToFile(fout, course);

    // 13. Sắp xếp theo GPA giảm dần -> ghi ra file
    fout << "=== 9. SORT BY GPA ===\n";
    sortByGPA(course);
    writeDataToFile(fout, course);

    // 14. Sắp xếp theo ngày sinh -> ghi ra file
    fout << "=== 10. SORT BY DOB ===\n";
    sortByDoB(course);
    writeDataToFile(fout, course);

    fout.close();
    cout << "All tests completed. Check " << outFile << " for file outputs.\n";
    return 0;
}