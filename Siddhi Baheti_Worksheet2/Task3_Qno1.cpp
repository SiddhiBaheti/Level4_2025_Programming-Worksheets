/* A program that reads and stores the titles of 10 books in a binary file and allows users to search for their desired title */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Books{
    static const int maxTitles = 10;
    static const int maxCharacters = 150;
    char book_titles[maxTitles][maxCharacters];
    string fileName;

public:
    //function to get 10 book titles from user
    void getBookTitles(){
        cout<<"Enter 10 Book Titles:"<<endl;

        cin.ignore(); //ignoring any leftover newline characters in the input

        //loop to get 10 books titles
        for (int i = 0; i < maxTitles; i++){
            cout<<"Book Title "<<i+1<<" : ";
            cin.getline(book_titles[i], maxCharacters);

            //alerting user if the book title was longer than 150 charactes
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Your title was too long! Only up to 150 characters were read."<<endl;
            }
            else{
                cout<<"Book Title was added successfully!"<<endl;
            }
        }
    }

    //function to get file name from the user
    string getFileName(){
        string fileName;

        cout<<"Enter the file name (without extension): ";
        cin>>fileName;

        fileName = fileName + ".dat"; //adding the .dat extension for a binary file

        return fileName;
    }

    //function to write the book titles to the binary file
    void writeToFile(){
        fileName = getFileName(); //asking user for the filename to store the information

        //opening file in binary and append mode
        ofstream file(fileName, ios::binary);

        if (!file){
            cout<<"No file found! Error opening the file!"<<endl;
            return;
        }

        //writing all 10 book titles to the binary file
        for (int i = 0; i < maxTitles; i++ ){
            file.write(book_titles[i], maxCharacters);
        }

        file.close();
        cout<<"Book Titles have been written to the binary file successfully!"<<endl;
    }

    //function to display all the book titles from the binary file
    void readFromFile(){
        fileName = getFileName(); //asking from user about which file to read from

        //opening file in read and binary mode
        ifstream file(fileName, ios::in | ios::binary);

        if(!file){
            cout<<"No file found! Error opening the file!"<<endl;
            return;
        }

        //creating an array to store the titles read from the file
        char books[maxCharacters];

        //reading and displaying each book title from the file
        cout<<"------------ All Book Records ------------"<<endl;
        for(int i = 0; i < maxTitles; i++){
            file.read(books, maxCharacters);

            cout<<"Book Title "<< i + 1 <<" : "<< books <<endl;
        }

        file.close();
    }

    //function to search for user desired book title in the binary file
    void searchTitle(){
        fileName = getFileName();

        ifstream file (fileName, ios::in | ios::binary);

        if (!file){
            cout<<"No file found! Error opening the file!"<<endl;
            return;
        }

        char book_to_search[maxCharacters]; //array to store the book title to search

        cin.ignore();
        cout<<"Enter the title of the book you want to search: ";
        cin.getline(book_to_search, maxCharacters);

        char books[maxCharacters]; //array to store the book titles read from the file
        bool found = false;

        for (int i = 0; i < maxTitles; i++){
            file.read(books, maxCharacters);

            //checking to see if any book title from the file matches the searched title
            if (strcmp(books, book_to_search) == 0){
                cout<<"Book found in the list!"<<endl;
                found = true;
                break;
            }
        }

        if(!found){
            cout<<"Book not found in the list!"<<endl;
        }

        file.close();
    }

    //function to display the menu and handle the user input
    void startMenu(){
        int ch;

        do{
            //displaying menu options
            cout<<"Welcome to Books Collection! \n 1. Add Books to Collection \n 2. View Books in the Collection \n 3. Search Books in Collection \n 4. Exit \n";
            cout<<"Enter your choice: ";
            cin>>ch;

            //checking for valid numeric inputs
            while (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Enter a number (1-4)!";
                cin>>ch;
            }

            //handling users' choices
            switch (ch){
            case 1:
                getBookTitles();
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                searchTitle();
                break;
            case 4:
                cout<<"Signing off! Thank you, come back soon."<<endl;
                break;
            default:
                cout<<"Invalid choice! Choose from 1, 2, 3 or 4."<<endl;
                break;
            }

        }while (ch != 4); //repeating until user wishes to exit
    }
};

int main(){
    Books b1;
    b1.startMenu();
    return 0;
}
