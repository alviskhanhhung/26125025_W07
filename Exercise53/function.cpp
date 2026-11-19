#include "function.h"
bool nameDissecting(const std::string& fullName, std::string& firstName, std::string& lastName) {
    //Assume that first name is the first word of a space-normalized string, and last name is the rest.
    auto spacePos = fullName.find_first_of(' ');
    if (spacePos == std::string::npos) {
        firstName = fullName;
        lastName = "";
    }
    else {  
        firstName = fullName.substr(0, spacePos);
        lastName = fullName.substr(spacePos + 1);
    }
    return true;
}
bool readDataFromFile(std::ifstream& fin, Course& course) {
    if (!fin) {
        return false;
    }
    getline(fin, course.id, '|');
    getline(fin, course.name, '|');
    getline(fin, course.status, '|');
    fin >> course.maxStudent;
    fin >> course.minStudent;
    std::string line;
    int i = 0;
    while (getline(fin, line)) {
        Student student;
    }
    return true;
}

bool writeDataToFile(std::ofstream& fout, const Course& course) {
    if (!fout) {
        return false;
    }
    fout << course.id << '|' << course.name << '|' << course.status << '|' << course.maxStudent << '|' << course.minStudent << '\n';
    
}