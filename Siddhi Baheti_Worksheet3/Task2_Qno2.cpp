/* A program that manages student's records (Name, Roll no, Marks) */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student{
    int roll_no;
    float total_marks;
    string name;

public:
    //function to get name from the user
    void getName(){
        while(true){
            cout<<"Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            if (name.empty()){ //ensuring that the name is not empty
                cout<<"Student Name cannot be empty!"<<endl;
            }
            else{
                break;
            }
        }
    }

    //function to get a valid roll number from the user
    void getRollNo(){
        while (true){
            cout<<"Enter Roll No: ";
            cin>>roll_no;
            //validating that the roll number is an integer
            if (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Invalid input! Roll number must be an integer!"<<endl;
            }
            else{
                //ensuring the roll number is unique
                if (!uniqueRollNo(roll_no)){
                    cout<<"Roll number already exists! Enter unique!"<<endl;
                }
                else{
                    break;
                }
            }
        }
    }

    //function to check if the roll number or not by reading from file
    bool uniqueRollNo(int roll_no){
        ifstream file("Students.txt");

        //skipping the top two lines of the file, as they are headers
        string skipline;
        getline(file, skipline);
        getline(file, skipline);

        int r;
        string n;
        float m;
        string line;

        //checking each record of the file to see if the roll number already exists
        while (file >> r){

            getline(file, line); //ignoring rest of the information in the line

            if (r == roll_no){ //if the roll number entered by the user already exists returns false
                file.close();
                return false;
            }
        }

        file.close();
        return true; //if not found, the roll number is unique - returns true
    }

    //function to get valid marks from the user
    void getMarks(){
        total_marks = validateMarks();
    }


    //function to validate marks
    float validateMarks(){
        float a;
        while (true){
            cout<<"Enter Total Marks (0-100): ";
            cin>>a;

            try{
                if (cin.fail()){ //checking if the entered marks in numeric or not
                    throw 1;
                }
                if (a < 0 || a > 100){ //checking if the entered marks is within the range 0 - 100
                    throw a;
                }

                return a; //returns the valid marks
            }

            catch(int error){
                cout<<"Invalid input! Not a number!"<<endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            catch (float b){
                cout<<"Marks should be in the range of (0-100)!"<<endl<<b<<" is out of range!"<<endl;
            }
        }
    }

    //function to get the size of the file to handle file headers
    streampos get_file_size(){
        fstream file;
        file.open("Students.txt", ios::in); //Opening the file in read mode

        if (!file){
            cout<<"Error opening the file!"<<endl;
        }

        file.seekg(0, ios::end);  //Moving to the end of the file
        streampos fileSize = file.tellg(); //Getting the file size

        file.close();
        return fileSize;
    }

    //function to write the student data to the file
    void write_to_file(){
        ofstream my_file("Students.txt", ios::app); //opening file in append mode

        if (!my_file){
            cout<<"Error opening the file!"<<endl;
        }

        streampos Size = get_file_size();

        if (Size == 0){ //Ensuring a header is made when the file is newly created
            my_file <<left<<setw(10)<<"Roll No."<<setw(20)<<"Name"<<setw(10)<<"Total Marks"<<endl;
            my_file <<"-----------------------------------------------------\n";
        }

        //ensuring the data is aligned properly
        my_file <<left<<setw(10)<<roll_no <<setw(20)<<name <<setw(10)<<total_marks<<endl;
        my_file.close();

        cout<<endl<<"Student Record has been added successfully!"<<endl;
    }

    //function to read data from the file and display the student records
    void display(){
        ifstream my_file("Students.txt");

        if (!my_file){
            cout<<"Error opening the file!"<<endl;
        }

        streampos Size = get_file_size();
        //displaying the file is empty if no records have been added
        if (Size == 0){
            cout<<"Empty File! No records to show!"<<endl<<endl;
        }
        else{
            string line;

            cout<<endl<<"---------------- All Student Records ----------------"<<endl;
            while (!my_file.eof()){
                getline (my_file, line);
                cout<<line<<endl;
            }
        }

        my_file.close();
    }

    //menu function for the user to make their choice
    void startMenu(){
        int ch;
        //the menu is run unless the user wants to exit
        do{
            cout<<"Welcome to Student Record System! \n 1. Add a Student Record \n 2. Display all Student Records \n 3. Exit"<<endl;
            cout<<"Enter your choice (1-3): ";
            cin>>ch;

            //handling invalid non-numeric inputs
            while (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Make a valid choice (1-3): ";
                cin>> ch;
            }

            switch (ch){
            case 1:
                getRollNo();
                getName();
                getMarks();
                write_to_file();
                break;

            case 2:
                display();
                break;

            case 3:
                cout<<"Thank you for using our system! Come back soon!"<<endl;
                break;

            default:
                cout<<"Invalid choice of number! Choose from 1, 2 or 3."<<endl;
                break;
            }

        }while (ch != 3);
    }
};

int main(){
    Student s1;
    s1.startMenu();

    return 0;
}
