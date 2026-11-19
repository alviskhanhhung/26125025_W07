#pragma once
#include <iostream>
#include <fstream>
#include <string>
template <typename T>
class DynamicArray {
    private:
        T* data;
        int size;
        int capacity;
        void reallocate() {
            capacity *= 2;
            newData = new T[capacity];
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
bool nameDissecting(const std::string& fullName, std::string& firstName, std::string& lastName);
bool readDataFromFile(std::ifstream& fin, Course& course);
bool writeDataToFile(std::ofstream& fout, const Course& course);