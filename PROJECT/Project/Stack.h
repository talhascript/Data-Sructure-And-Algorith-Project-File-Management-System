#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "Directory.h"
using namespace std;

class Stack{
	public:
		Stack();
		void push(Directory*);
		Directory* pop();
		bool isEmpty();
		Directory* stackTop();
	
	private:
		Directory *top;
};

#endif