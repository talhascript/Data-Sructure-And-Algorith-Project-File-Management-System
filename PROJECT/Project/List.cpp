#include "List.h"

List::List()
{
    head = NULL;
    size = 0;
}

bool List::isEmpty()
{
    return head == NULL;
}

void List::InsertFile(File *f)
{
    File *currNode = head;

    while (currNode && currNode->next)
    {
        currNode = currNode->next;
    }

    if (!currNode)
    { // if list empty
        head = f;
    }
    else
    {
        currNode->next = f;
    }
    this->size++;
}

void List::deleteFile(File *f)
{
    File *currNode = head;
    File *prevNode = NULL;

    while (currNode != f)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (!currNode)
    {
        cout << "Cannot delete the file: " << f->getName() << ". It does not exist in this directory.";
        return;
    }

    if (prevNode)
    {
        prevNode->next = currNode->next;
        delete currNode;
    }
    else
    { // prevNode doesnt exist meaning only 1 node in list
        head = currNode->next;
        delete currNode;
    }
    this->size++;
}

File* List::SearchFile(string name)
{
    File *currNode = head;

    while (currNode)
    {
        if(currNode->getName().compare(name) == 0) return currNode;
        currNode = currNode->next;
    }
    return NULL;
}

void List::DisplayFiles()
{
    File *currNode = head;
    if(!currNode) cout << "No file. Empty Directory\n";

    while (currNode)
    {
        cout << currNode->getName() << endl;
        currNode = currNode->next;
    }
}

File *List::getFile(int index)
{
    File *currNode = head;

    for (int i = 1; i < index; i++)
    {
        currNode = currNode->next;
    }
    return currNode;
}

int List::getSize() {
    return this->size;
}

File* List::getFirst() {
    return this->head;
}
