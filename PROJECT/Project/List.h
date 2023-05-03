#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "File.h"
using namespace std;

class List
{
private:
    File *head;
    int size;
public:
    List();
    bool isEmpty();
    void InsertFile(File*);
    void deleteFile(File*);
    File* SearchFile(string);
    void DisplayFiles();
    File* getFile(int);
    int getSize();
    File* getFirst();
    void operator=(List l) {
        head = l.head;
        size = l.size;
    }
};
#endif
