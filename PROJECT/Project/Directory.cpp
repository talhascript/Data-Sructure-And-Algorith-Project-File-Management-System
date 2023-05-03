#include "Directory.h"

Directory::Directory() {}

Directory::Directory(string _name) : name(_name) {}

string Directory::getName() {
    return this->name;
}

void Directory::setName(string _name) {
    this->name = _name;
}

void Directory::setFilesList(List l) {
    this->filesList = l;
}
