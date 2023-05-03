#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include "List.h"
using namespace std;

class Directory {
private:
    string name = "";
public:
    Directory();
    Directory(string);
    Directory *stackNext = NULL;
    Directory *treeLeft = NULL;
    Directory *treeRight = NULL;
    Directory *parent = NULL;
    List filesList = List();

    string getName();
    void setName(string);
    void setFilesList(List);
};
#endif