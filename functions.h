// File: Functions.h
// Melanie Woe

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// data type
struct book
{
    int ISBN;
    string Author;
    string Publisher;
    int Quantity;
    double price;
};

// first choice
void choice1(book books[], int& size, int MAX_SIZE)
{
    ifstream inFile;                //to read the file
    inFile.open("inventory.dat");   //open the file
    string str;
    
    while(inFile && size < MAX_SIZE)
    {
        getline(inFile, str);
        books[size].ISBN = atoi(str.c_str());           //to read the isbn
        
        getline(inFile, books[size].Author);            //to read the autor
        
        getline(inFile, books[size].Publisher);         //to read the publisher
        
        getline(inFile, str);
        books[size].Quantity = atoi(str.c_str());       //to read the quantity
        
        getline(inFile, str);
        books[size].price = atoi(str.c_str());          //to read the price
        
        size++;
    }
    
   
    
    cout << "You have successfully read the file." << endl;
    inFile.close();
}

// choice 2 adding a new book entry
void choice2(book books[], int& size, int MAX_SIZE)
{
    
    if(size < MAX_SIZE)
    {
        string str;
        
        cout << "\nEnter the book ISBN: ";
        cin >> books[size].ISBN;
        
        cout << "Enter the author name: ";
        cin >> books[size].Author;
        getline (cin, str);
        
        cout << "Enter the book publisher: ";
        cin >> books[size].Publisher;
        getline (cin, str);
        
        cout << "Enter the books quantity: ";
        cin >> books[size].Quantity;
        
        cout << "Enter the book price: $";
        cin >> books[size].price;
        
        size++;
        cout << "You have successfully add a new entry." << endl;
    }
    else
        cout << "Array is empty. Read the data first. " << endl;
    
}

// choice 3 deleting an entry
void choice3(book books[], int& size)
{
    if(size == 0)
        cout << "Array is empty. Read the data first." << endl;
    else
    {
        int ISBN;
        
        cout << "\nEnter the ISBN of the book: ";
        cin >> ISBN;
        
        for(int index = 0; index < size; index++)
        {
            if(books[index].ISBN == ISBN)
            {
                int nextbook = index;
                while(nextbook < size - 1)
                {
                    books[nextbook] = books[nextbook + 1];
                    nextbook++;
                }
                
                size--;
                break;
            }
        }
        
        cout << "You have successfully deleted an entry." << endl;
    }
}

// choice 4 changing the quantity
void choice4(book books[], int size)
{
    if(size == 0)
        cout << "Array is empty. Read the data first." << endl;
    else
    {
        int ISBN;
        int choice;
        int quantity;
        
        cout << "\nEnter the ISBN of the book: ";
        cin >> ISBN;
        
        cout << "1. Increment" << endl;
        cout << "2. Decrement" << endl;
        cout << "3. A new value of quantity" << endl;
        cout << "Enter your option: ";
        cin >> choice;
        
        cout << "Enter the quantity: ";
        cin >> quantity;
        
        for(int index = 0; index < size; index++)
        {
            if(books[index].ISBN == ISBN)
            {
                if(choice == 1)
                    books[index].Quantity += quantity;      //adding or increment
                else if(choice == 2)
                {
                    books[index].Quantity -= quantity;      //substraction or decrement
                    
                    if(books[index].Quantity)
                        books[index].Quantity = 0;
                }
                else if(choice == 3)
                    books[index].Quantity = quantity;        //new value
                
                break;
            }
        }
        
        cout << "You have successfully updated the array." << endl;
    }
}



// choice 5 read the inventory out
void choice5(book books[], int size)
{
    ofstream outFile;                   //write the inventory out to inventory.dat file
    outFile.open("inventory.dat");
    
    cout << fixed << setprecision(2);
    
    for(int index = 0; index < size; index++)
    {
        outFile << "Book number: " << (index+1) << endl;
        outFile << "ISBN: " << books[index].ISBN << endl;
        outFile << "Author: " << books[index].Author << endl;
        outFile << "Publisher: " << books[index].Publisher << endl;
        outFile << "Quantity: " << books[index].Quantity << endl;
        outFile << "Price: $" << books[index].price << endl << endl;
    }
    
    if(size != 0)
        cout << "You have successfully printed the array." << endl;
    else
        cout << "Array is empty. Read the file first." << endl;
    
    outFile.close();
}

