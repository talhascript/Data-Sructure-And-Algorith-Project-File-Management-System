// ### Directories and File Management System ###
#include <iostream>
#include <string>

#include "Tree.cpp"
#include "Queue.cpp"
#include "List.h"
#include "Stack.h"

using namespace std;

string starterMenu() {
    int option = 0;
    cout << "=== DIRECTORIES AND FILE MANAGEMENT SYSTEM ===" << endl;
    cout << "=== Welcome to the system ===" << endl;
    cout << " == Starter Menu ==\n" << endl
        << " What is your role? " << endl
        << "1. Admin" << endl
        << "2. User" << endl;

    do {
        cout << "\nEnter your role 1/2: ";
        cin >> option;

        if(option!=1 && option!=2) {
            cout << "Please Enter a valid option number: 1 or 2";
        }

    } while(option!=1 && option!=2);

    if(option == 2) {
        return "User";
    } else {
        return "Admin";
    }
}

void UserMenu(Tree &tree, Stack &s) {
    Directory* d, *currentDirectory = tree.getRoot();
    int option = 0;
    string buffer = "";

    // Normal User Functionalities
    do {
        cout << " == User Main Menu ==\n" << endl
            << "|| Current directory is => " << currentDirectory->getName() << endl
            << "1. Search for/Go to a directory" << endl
            << "2. Display the directories tree" << endl
            << "3. Go back to previous directory" << endl
            << "4. Add files to current directory" << endl
            << "5. Rename File" << endl
            << "6. Display Files of the current Directory" << endl
            << "0. Exit" << endl;
        do {
            cout << "\nEnter operation number: ";
            cin >> option;

            if(option < 0 || option > 6) {
                cout << "Please enter a valid option number";
            }
        } while(option < 0 || option > 6);

        if(option == 1) {
            system("CLS");
            cout << "Name of the directory you want to search for: ";
            cin.ignore();
            getline(cin, buffer);
            d = tree.searchDirectory(buffer, tree.getRoot());
            if (d) {
                cout << endl;
                cout << d->getName() << " was found in the tree." << endl
                    << "Do you want to move to that directory?\n1. Yes\n2. No"
                    << "\nEnter your option: ";
                cin >> option;
                if(option == 1) {
                    currentDirectory = d;
                    s.push(currentDirectory);
                }
            } else {
                cout << "Directory does not exist in the tree.";
            }
        } else if (option == 2) {
            system("CLS");
            tree.printTree(tree.getRoot());
        } else if (option == 3) {
            system("CLS");
            s.pop();
            currentDirectory = s.stackTop();
        } else if (option == 4) {
            system("CLS");
            Queue q;
            cout << "Fill in the queue with the files names that you want to add.\n"
                << "You are allowed to add up to 3 files at a time\n";
            do {
                cout << "\n1. Add file to creation queue\n"
                    << "2. Execute Creation of the files\n"
                    << "Enter your option: ";
                cin >> option;
                if(option == 1) {
                    cout << "Enter file name: ";
                    cin.ignore();
                    getline(cin, buffer);
                    q.enqueue(new File(buffer));
                }
            } while(option != 2);

            File f1 = q.dequeue();            
            File f2 = q.dequeue();            
            File f3 = q.dequeue();            
            if(f1.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f1);
            if(f2.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f2);
            if(f3.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f3);
        } else if (option == 5) {
            system("CLS");
            cout << "== Select the file to rename ==\n";
            File* f = NULL;
            
            cout << "Enter the name of the file you want to rename: ";
            cin.ignore();
            getline(cin, buffer);
            f = currentDirectory->filesList.SearchFile(buffer);
            if(f) {
                cout << "Enter the file's new name: ";
                getline(cin, buffer);
                f->setName(buffer);
            } else {
                cout << "File does not exist in this directory.\n";
            }
        } else if (option == 6) {
            system("CLS");
            cout << "Files in this directory: " << endl;
            currentDirectory->filesList.DisplayFiles();
        }
    } while(option!=0);
}

int AdminMenu(Tree &tree, Stack &s) {
    // Admin Functionalities
    Directory* d, *currentDirectory = tree.getRoot();
    int option = 0;
    string buffer = "";

    do {
        cout << "\n == Admin Main Menu ==\n" << endl
            << "|| Current directory is => " << currentDirectory->getName() << endl
            << "1. Search for/Go to a directory" << endl
            << "2. Display the directories tree" << endl
            << "3. Go back to previous directory" << endl
            << "4. Add files to current directory" << endl
            << "5. Add new Directory" << endl
            << "6. Delete File/Directory" << endl
            << "7. Rename File/Directory" << endl
            << "8. Display Files of the current Directory" << endl
            << "0. Exit" << endl;

        do {
            cout << "\nEnter operation number: ";
            cin >> option;

            if(option < 0 || option > 8) {
                cout << "Please enter a valid option number";
            }
        } while(option < 0 || option > 8);

        if(option == 1) {
            system("CLS");
            cout << "Name of the directory you want to search for: ";
            cin.ignore();
            getline(cin, buffer);
            d = tree.searchDirectory(buffer, tree.getRoot());
            if (d) {
                cout << endl;
                cout << d->getName() << " was found in the tree." << endl
                    << "Do you want to move to that directory?\n1. Yes\n2. No"
                    << "\nEnter your option: ";
                cin >> option;
                if(option == 1) {
                    currentDirectory = d;
                    s.push(currentDirectory);
                }
            } else {
                cout << "Directory does not exist in the tree.";
            }
        } else if (option == 2) {
            system("CLS");
            tree.printTree(tree.getRoot());
        } else if (option == 3) {
            system("CLS");
            s.pop();
            currentDirectory = s.stackTop();
        } else if (option == 4) {
            system("CLS");
            Queue q;
            cout << "Fill in the queue with the files names that you want to add.\n"
                << "You are allowed to add up to 3 files at a time\n";
            do {
                cout << "\n1. Add file to creation queue\n"
                    << "2. Execute Creation of the files\n"
                    << "Enter your option: ";
                cin >> option;
                if(option == 1) {
                    cout << "Enter file name: ";
                    cin.ignore();
                    getline(cin, buffer);
                    q.enqueue(new File(buffer));
                }
            } while(option != 2);

            File f1 = q.dequeue();            
            File f2 = q.dequeue();            
            File f3 = q.dequeue();            
            if(f1.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f1);
            if(f2.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f2);
            if(f3.getName().compare("") != 0) currentDirectory->filesList.InsertFile(&f3);
        } else if (option == 5) {
            system("CLS");
            cout << "Enter directory name: ";
            cin.ignore();
            getline(cin, buffer);
            tree.createChildDirectory(new Directory(buffer), currentDirectory);
        } else if (option == 6) {
            system("CLS");
            cout << "1. Delete the current Directory\n2. Delete Files in the current Directory"
                << "\nEnter your option: ";
            cin >> option;
            if (option == 1) {
                tree.deleteDirectory(currentDirectory);
                currentDirectory = tree.getRoot();
            } else if (option == 2) {
                cout << "Enter the name of the file you want to delete: ";
                cin.ignore();
                getline(cin, buffer);
                File* f = currentDirectory->filesList.SearchFile(buffer);
                currentDirectory->filesList.deleteFile(f);
            } else {
                cout << "Incorrect option: should choose either 1 or 2";
            }
        } else if (option == 7) {
            system("CLS");
            cout << "1. Rename the current Directory.\n2. Rename a file in the current directory"
                << "\nEnter your option: ";
            cin >> option;
            if (option == 1) {
                if(currentDirectory->getName().compare("root") == 0) {
                    cout << "\nYou cannot rename the root directory\n";
                } else {
                    do {
                        cout << "Enter the new name for the current directory: ";
                        cin.ignore();
                        getline(cin, buffer);
                        currentDirectory->setName(buffer);
                        if(buffer.compare("root") == 0) cout << "\nYou cannot name a directory as: root";
                    } while(buffer.compare("root") == 0);
                }
            } else if (option == 2) {
                cout << "== Select the file to rename ==\n";
                File* f = NULL;
            
                cout << "Enter the name of the file you want to rename: ";
                cin.ignore();
                getline(cin, buffer);
                f = currentDirectory->filesList.SearchFile(buffer);
                if(f) {
                    cout << "Enter the file's new name: ";
                    getline(cin, buffer);
                    f->setName(buffer);
                } else {
                    cout << "File does not exist in this directory.\n";
                }
            }
        } else if (option == 8) {
            system("CLS");
            cout << "Files in this directory: " << endl;
            currentDirectory->filesList.DisplayFiles();
        }

    } while(option!=0);
    
    return 0;
}

void buildStartingTree(Tree &tree) {
    tree.createChildDirectory(new Directory("directory1"), tree.getRoot());
    tree.createChildDirectory(new Directory("directory2"), tree.getRoot());


}

int main() {
    Tree tree;
    Stack s;
    Queue q;

    string role;
    int index = -1;

    buildStartingTree(tree);
    s.push(tree.getRoot());

    role = starterMenu();

    if(role.compare("Admin") == 0) {
        AdminMenu(tree, s);
    } else if(role.compare("User") == 0) {
        UserMenu(tree, s);
    }

    cout << endl;
    system("pause");
    return 0;
}