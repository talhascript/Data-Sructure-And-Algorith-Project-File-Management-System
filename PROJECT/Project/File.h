#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
using namespace std;

class File {
private:
    string name = "";
public:
    File *next = NULL;
    File();
    File(string);
    string getName();
    void setName(string);
};
#endif