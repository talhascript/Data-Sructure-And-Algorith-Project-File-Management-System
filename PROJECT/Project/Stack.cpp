#include "Stack.h"

Stack::Stack(){
	top = NULL;
}

bool Stack::isEmpty(){ return (top== NULL); }

void Stack::push(Directory *d){
	d->stackNext = top;
	top = d;
}

Directory* Stack::pop(){
	Directory* popped = NULL;
	if (top->getName().compare("root") == 0){
		cout<<"\nYou are in the root directory. Cannot go back more\n";
	} else {
		popped = top;
		top = top->stackNext;
	}
	return popped;
}

Directory* Stack::stackTop(){
	if (isEmpty()){
		cout<<"\nEmpty stack. There is no top.";
		return NULL;
	}
	return top;
}