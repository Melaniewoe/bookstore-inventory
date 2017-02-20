// File: Boookstore.cpp
// Melanie Woe

#include<iostream>
#include"functions.h"
using namespace std;

int main()
{
    const int MAX_SIZE = 100;
    book books[MAX_SIZE];
    int size = 0;
    int choice;
    
    
    do
    {
        cout << "Please select one choices from the menu" << endl;    //choices output for the users (menu)
        cout << "1: Read inventory from file" << endl;
        cout << "2: Add an entry" << endl;
        cout << "3: Delete an entry" << endl;
        cout << "4: Update an entry" << endl;
        cout << "5: Write inventory to file and exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;                                                  //input from the user
        
        switch(choice)
        {
            case 1:
                choice1(books, size, MAX_SIZE);
                break;
            case 2:
                choice2(books, size, MAX_SIZE);
                break;
            case 3:
                choice3(books, size);
                break;
            case 4:
                choice4(books, size);
                break;
            case 5:
                choice5(books, size);
                cout << "See You! " << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << endl;
    }while(choice != 7);
    
    
    return 0;
}

