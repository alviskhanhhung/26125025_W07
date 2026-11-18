#pragma once
#include <iostream>
#include <fstream>

bool readDataFromFile(std::ifstream& in, int& n, char*& pArr);
int* doubleSizeArray(int* arr, int& size);
void printArray(int* arr, int size);