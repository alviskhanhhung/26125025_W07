#include "function.h"
bool nameDissecting(const std::string& fullName, std::string& firstName) {
    //Assume that first name is the first word of a space-normalized string, and last name is the rest.
    auto spacePos = fullName.find_first_of(' ');
    if (spacePos == std::string::npos) {
        firstName = fullName;
    }
    else {  
        firstName = fullName.substr(0, spacePos);
    }
    return true;
}
bool readDataFromFile(std::ifstream& fin, Course& course) {
    if (!fin) {
        return false;
    }
    if (!getline(fin, course.id, '|')) return false;
    getline(fin, course.name, '|');
    getline(fin, course.status, '|');
    std::string placeHolder;
    getline(fin, placeHolder, '|');
    course.maxStudent = std::stoi(placeHolder);
    getline(fin, placeHolder);
    course.minStudent = std::stoi(placeHolder);
    std::string line;
    while (getline(fin, line)) {
        if (line.empty()) {
            continue;
        }
        std::stringstream ss(line);
        Student student;
        std::string temp;
        getline(ss, temp, '|');
        student.id = std::stoi(temp);
        getline(ss, student.name, '|');
        getline(ss, temp, '|');
        student.gpa = std::stod(temp);
        getline(ss, temp, '/');
        student.DoB.day = std::stoi(temp);
        getline(ss, temp, '/');
        student.DoB.month = std::stoi(temp);
        getline(ss, temp);
        student.DoB.year = std::stoi(temp);
        course.students.push_back(student); 
    }
    return true;
}

bool writeDataToFile(std::ofstream& fout, Course& course) {
    if (!fout) {
        return false;
    }
    fout << course.id << '|' << course.name << '\n';
    for (int i = 0; i < course.students.getSize(); i++) {
        fout << course.students[i].id << '|' << course.students[i].name << '|' << course.students[i].gpa << '|' << course.students[i].DoB.day << '/' << course.students[i].DoB.month << '/' << course.students[i].DoB.year << '\n';
    }
    fout << '\n';
    return true;
}
bool addStudentToCourse(Course& course, Student& student) {
    if (course.students.getSize() >= course.maxStudent) {
        return false;
    }
    course.students.push_back(student);
    return true;
}
bool removeStudentFromCourse(Course& course, int studentID) {
    if (course.students.getSize() <= course.minStudent) {
        return false;
    }
    for (int i = 0; i < course.students.getSize(); i++) {
        if (course.students[i].id == studentID) {
            course.students.deleteID(i);
            return true;
        }
    }
    return false;
}
void sameMonthAsCurrent(Course& course) {
    Date currentDate;
    std::time_t now = std::time(nullptr); //time returns the current time to now AND write a copy of the time to the parameter pass to it, I passed null so it writes to nothing.
    std::tm* local_time = std::localtime(&now);
    int current_month = local_time->tm_mon + 1;
    std::cout << "Current month: " << current_month << '\n';
    for (int i = 0; i < course.students.getSize(); i++) {
        if (course.students[i].DoB.month == current_month) {
            std::cout << course.students[i].name << ' ';
        }
    }
}
void sameDateAsCurrent(Course& course) {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    int current_day = local_time->tm_mday;
    int current_month = local_time->tm_mon + 1;
    std::cout << "Current day: " << current_day << '\n';
    std::cout << "Current month: " << current_month << '\n';
    for (int i = 0; i < course.students.getSize(); i++) {
        if (course.students[i].DoB.day == current_day && course.students[i].DoB.month == current_month) {
           std::cout << course.students[i].name << ' ';
        }
    }
}
void isEighteen(Course& course) {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;
    for (int i = 0; i < course.students.getSize(); i++) {
        if (current_year - course.students[i].DoB.year > 18) {
            std::cout << course.students[i].name << ' ';
        }
        else if (current_year - course.students[i].DoB.year == 18) {
            if (current_month - course.students[i].DoB.month > 0) {
                std::cout << course.students[i].name << ' ';
            }
            else if (current_month - course.students[i].DoB.month == 0) {
                if (current_day - course.students[i].DoB.day >= 0) {
                    std::cout << course.students[i].name << ' ';
                }
            }
        }
    }
}
void findStudentFromClassK19(Course& course, std::ofstream& fout) {
    for (int i = 0; i < course.students.getSize(); i++) {
        if (course.students[i].id / 1000000 == 19) {
            fout << course.students[i].name << " is from class K19\n";
        }
    }
}
bool findStudentById(Course& course, int studentId, std::ofstream& fout) {
    for (int i = 0; i < course.students.getSize(); i++) {
        if (course.students[i].id == studentId) {
            std::cout << "Student found: " << course.students[i].name << '\n';
            fout << "Student found: " << course.students[i].name << '\n';
            return true;
        }
    }
    return false;
}
bool findStudentByName(Course& course, std::string name, std::ofstream& fout) {
    for (char c: name) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
        }
    }
    for (int i = 0; i < course.students.getSize(); i++) {
        std::string studentName = course.students[i].name;
        for (char& c: studentName) {
            if (std::isalpha(c)) {
                c = std::tolower(c);
            }
        }
        if (studentName.find(name) != std::string::npos) {
            fout << "Student with name include " << name << " found: " << course.students[i].name << '\n';
            return true;
        }
    }
    return false;
}

void sortById(Course& course) {
    for (int i = 1; i < course.students.getSize(); i++) {
        Student key = course.students[i];
        int j = i - 1;
        while (j >= 0 && course.students[j].id > key.id) {
            course.students[j+1] = course.students[j];
            j--;
        }
        course.students[j+1] = key;
    }
}
void sortByFirstName(Course& course) {
    for (int i = 1; i < course.students.getSize(); i++) {
        Student key = course.students[i];
        std::string firstNameKey;
        nameDissecting(key.name, firstNameKey);
        int j = i - 1;
        while (j >= 0) {
            std::string firstNameCurr;
            nameDissecting(course.students[j].name, firstNameCurr);
            if (firstNameCurr > firstNameKey) {
                course.students[j+1] = course.students[j];
                j--;
            } else {
                break;
            }
        }
        course.students[j+1] = key;
    }
}
void sortByGPA(Course& course) {
    for (int i = 1; i < course.students.getSize(); i++) {
        Student key = course.students[i];
        int j = i - 1;
        while (j >= 0 && course.students[j].gpa < key.gpa) { 
            course.students[j+1] = course.students[j];
            j--;
        }
       course.students[j+1] = key;
    }
}
bool compareByDoB(const Student& a, const Student& b) {
    if (a.DoB.year != b.DoB.year) {
        return a.DoB.year < b.DoB.year;
    }
    if (a.DoB.month != b.DoB.month) {
        return a.DoB.month < b.DoB.month;
    }
    return a.DoB.day < b.DoB.day;
}
void sortByDoB(Course& course) {
    for (int i = 1; i < course.students.getSize(); i++) {
        Student key = course.students[i];
        int j = i - 1;
        while (j >= 0 && compareByDoB(key, course.students[j])) {
            course.students[j + 1] = course.students[j];
            j--;
        }
        course.students[j + 1] = key;
    }
}