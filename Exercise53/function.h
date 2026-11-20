#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
template <typename T>
class DynamicArray {
    private:
        T* data;
        int size;
        int capacity;
        void reallocate() {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            newData = nullptr;
        }
    public:
        DynamicArray() : size(0), capacity(4) {
            data = new T[capacity];
        }
        ~DynamicArray() {
            delete[] data;
        }
        int getCapacity() {
            return capacity;
        }
        int getSize() {
            return size;
        }
        T& operator[](int id) {
            return data[id];
        }
        void push_back(T value) {
            if (size == capacity) {
                reallocate();
            }
            data[size++] = value;
        }
        void deleteID(int id) {
            for (int i = id; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }

};
struct Date {
    int day;
    int month;
    int year;
};
struct Student {
    int id;
    std::string name;
    double gpa;
    Date DoB;
};
struct Course {
    std::string id;
    std::string name;
    DynamicArray<Student> students;
    std::string status;
    int maxStudent;
    int minStudent;
};
bool nameDissecting(const std::string& fullName, std::string& firstName);
bool readDataFromFile(std::ifstream& fin, Course& course);
bool writeDataToFile(std::ofstream& fout, Course& course); 
bool addStudentToCourse(Course& course, Student& student);
bool removeStudentFromCourse(Course& course, int studentID);
void sameMonthAsCurrent(Course& course);
void sameDateAsCurrent(Course& course);
void isEighteen(Course& course);
/*
void findStudentFromClass(DynamicArray<Course> courses, int studentId);
For the function to check which students are from class K19, I am really 
confuse about the "class" thing here, how do we check it? 
*/
void findStudentFromClassK19(Course course, int studentId);
bool findStudentById(Course& course, int studentId, std::ofstream& fout);
//What kind of "result" are we trying to achieve here? full name? first name? gpa? all of them?
bool findStudentByName(Course& course, std::string fullName, std::ofstream& fout);
void sortById(Course& course);
void sortByFirstName(Course& course);
void sortByGPA(Course& course);
void sortByDoB(Course& course);