#include "Directory.h"

class Tree
{
private:
    Directory *root;
    int size;

public:
    Tree()
    {
        root = new Directory("root");
        size = 0;
    }

    ~Tree() { Destroy(root); }

    void Destroy(Directory *&tree)
    {
        if (tree)
        {
            Destroy(tree->treeLeft);
            Destroy(tree->treeRight);
            delete tree;
        }
    }

    bool isEmpty() { return root == NULL; }

    Directory* getRoot() { return this->root; }

    void createChildDirectory(Directory *newDirectory, Directory *parentDirectory)
    {
        Directory *temp = searchDirectory("root", this->getRoot());
        if(temp && newDirectory->getName().compare("root") == 0) {
            cout << "\nYou cannot have two root directories.\n";
            return;
        }
        if (!parentDirectory->treeLeft)
        {
            parentDirectory->treeLeft = newDirectory;
        }
        else if (!parentDirectory->treeRight)
        {
            parentDirectory->treeRight = newDirectory;
        }
        else
        {
            cout << "\nThis directory cannot have more sub-directories." << endl;
        }
        newDirectory->parent = parentDirectory;
    }

    // deleting a directory will delete all its files and subdirectories
    void deleteDirectory(Directory *d)
    {
        if(d->getName().compare("root") == 0) {
            cout << "\nYou cannot delete the root directory" << endl;
            return;
        }
        if(d->parent->treeLeft == d) {
            d->parent->treeLeft = NULL;
        } else {
            d->parent->treeRight = NULL;
        }
        Destroy(d);
    }

    int numberOfDirectories(Directory *tree)
    {
        int i = 0;
        if (!tree) return 0;

        i += numberOfDirectories(tree->treeLeft);
        i += numberOfDirectories(tree->treeRight);
        return i;
    }

    Directory *searchDirectory(string name, Directory *root)
    {
        if (!root)
            return NULL;
        if (root->getName().compare(name) == 0)
            return root;

        Directory *leftSearch = searchDirectory(name, root->treeLeft);
        if (leftSearch)
            return leftSearch;

        Directory *rightSearch = searchDirectory(name, root->treeRight);
        return rightSearch;
    }

    void printTree(Directory *root, string prefix = "", bool isLeft = 0)
    {
        if (root)
        {
            cout << prefix << "|--";
            cout << root->getName() << endl;
            printTree(root->treeLeft, prefix + (isLeft ? "|   " : "    "), 1);
            printTree(root->treeRight, prefix + (isLeft ? "|   " : "    "), 0);
        }
    }
};