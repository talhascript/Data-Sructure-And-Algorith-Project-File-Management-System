#include "File.h"

File::File() {}

File::File(string _name) : name(_name) {}

string File::getName() {
    return this->name;
}

void File::setName(string _name) {
    this->name = _name;
    cout << "File renamed successfully\n";
}