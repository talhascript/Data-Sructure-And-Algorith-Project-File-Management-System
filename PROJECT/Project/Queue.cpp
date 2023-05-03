#include <iostream>
#include "File.h"

using namespace std;

#define SIZE 3

class Queue
{
    public:
    File files[SIZE];
    int front, back;
    int size = SIZE;

    Queue()
    {
        front = 0;
        back = -1;
    }

    ~Queue() {}

    bool isEmpty() { return back < front; }

    bool isFull() { return (back == size - 1); }

    void enqueue(File *newFile)
    {
        // queue is full
        if (isFull())
            cout << "You cannot insert more files. You are allowed max 3 files at a time\n";
        else
        {
            // insert element at back
            back++;
            files[back] = *newFile;
        }
    }

    File dequeue()
    {
        File deletedItem = File("");

        if (!isEmpty())
        {
            deletedItem = files[front];
            front++;
        }
        return deletedItem;
    }

    void displayQueue()
    {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        else
        {
            for (int i = front; i <= back; i++)
            {
                cout << files[i].getName() << " ";
            }
        }
    }
};