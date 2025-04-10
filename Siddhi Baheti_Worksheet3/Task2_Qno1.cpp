/* A program that stores data (registration number, color, number of seats and engine capacity)
of vehicles in different files using inheritance and method overriding. */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle{
protected:
    string registration_number;
    string color;
public:
    //function that gets input from the user
    virtual void getData(){
        cout<<"Enter registration number: ";
        getline(cin, registration_number);

        cout<<"Enter color: ";
        getline(cin, color);
    }

    //function to write the information to a file
    virtual void write_to_file(){

        //opening file in append mode
        ofstream file("Vehicle.txt", ios::app);

        //checking if the file opens correctly or not
        if (file.is_open()){
            file <<"Vehicle"<<endl;
            file <<"Vehicle Registration Number: "<<registration_number<<endl;
            file <<"Vehicle Color: "<<color<<endl;
            file <<"-----------------------------------------"<<endl;

            cout<<"Vehicle details written to the file successfully."<<endl;
        }
        else{
            cout<<"File not found. Error opening the file!"<<endl;
            return;
        }

        file.close();
    }

    //function to read information from the file
    virtual void read_from_file(){
        //opening file in read mode
        ifstream file("Vehicle.txt");

        if (!file){
            cout<<"File not found!"<<endl;
        }

        string line;
        cout<<"\n ------------------Vehicle Details------------------ \n";
        while (!file.eof()){
            getline(file, line);
            cout<<line<<endl;
        }

        file.close();
    }
};

class Car: public Vehicle{
protected:
    int no_of_seats;
public:
    //function that gets input from the user
    void getData() override{
        Vehicle::getData();

        no_of_seats = validateData();
    }

    //function to check if the input given by the user is numeric or not
    int validateData(){
        cout<<"Enter the number of seats in car: ";
        cin>>no_of_seats;

        while (cin.fail()){ //looping until user enters a valid numeric input
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter a valid numeric value: ";
            cin>>no_of_seats;
        }

        cin.ignore();
        return no_of_seats;
    }

    //function to write the information to a file
    void write_to_file() override{

        //opening file in append mode
        ofstream file("Car.txt", ios::app);

        if (file.is_open()){
            file << "Car "<<endl;
            file << "Registration Number: "<<registration_number<<endl;
            file << "Color: "<<color<<endl;
            file << "Number of Seats: "<<no_of_seats<<endl;
            file << "-----------------------------------------"<<endl;
            cout<<"Car details written to the file successfully!"<<endl;
        }
        else{
            cout<<"File not found. Error opening the file!"<<endl;
            return;
        }

        file.close();
    }

    //function to read information from the file
    void read_from_file() override{
        //opening file in read mode
        ifstream file("Car.txt");

        if (!file){
            cout<<"File not found!"<<endl;
        }

        string line;
        cout<<"\n ------------------Car Details------------------ \n";
        while (!file.eof()){
            getline(file, line);
            cout<<line<<endl;
        }

        file.close();
    }

};

class Bike: public Vehicle{
    protected:
    int engine_capacity;
public:
    //function that gets input from the user
    void getData() override{
        Vehicle::getData();

        engine_capacity = validateData();
    }

    //function to check if the input given by the user is numeric or not
    int validateData(){
        cout<<"Enter engine capacity of bike (in cc): ";
        cin>>engine_capacity;

        while (cin.fail()){ //looping until user enters a valid numeric input
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter a valid numeric value for engine capacity: ";
            cin>>engine_capacity;
        }

        cin.ignore();

        return engine_capacity;
    }

    //function to write the information to a file
    void write_to_file() override{

        //opening file in append mode
        ofstream file("Bike.txt", ios::app);

        if (file.is_open()){
            file << "Bike "<<endl;
            file << "Registration Number: "<<registration_number<<endl;
            file << "Color: "<<color<<endl;
            file << "Engine Capacity (in cc): "<<engine_capacity<<endl;
            file << "-----------------------------------------"<<endl;
            cout<<"Bike details written to the file successfully!"<<endl;
        }
        else{
            cout<<"File not found. Error opening the file!"<<endl;
            return;
        }

        file.close();
    }

    //function to read information from the file
    void read_from_file() override{
        //opening file in read mode
        ifstream file("Bike.txt");

        if (!file){
            cout<<"File not found!"<<endl;
        }

        string line;
        cout<<"\n ------------------Bike Details------------------ \n";
        while (!file.eof()){
            getline(file, line);
            cout<<line<<endl;
        }

        file.close();
    }
};


int main(){
    int choice;
    do {
        //displaying menu to the user
        cout<<"\n ----------------Vehicle Management System----------------\n";
        cout<<"1. Add Vehicle" <<endl<<
         "2. Add Car"<<endl<<
         "3. Add Bike"<<endl<<
         "4. View Vehicles"<<endl<<
         "5. View Cars"<<endl<<
         "6. View Bike"<<endl<<
         "7. Exit"<<endl;
        cout<<"How would you like to move forward? \nEnter your choice: ";
        cin>>choice;

        while (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter a numeric value (1-4): ";
            cin>>choice;
        }

        switch (choice){
        case 1:{
            Vehicle v;
            cin.ignore();
            v.getData();
            v.write_to_file();
            break;
        }
        case 2:{
            Car c;
            cin.ignore();
            c.getData();
            c.write_to_file();
            break;
        }
        case 3:{
            Bike b;
            cin.ignore();
            b.getData();
            b.write_to_file();
            break;
        }
        case 4:{
            Vehicle v;
            v.read_from_file();
            break;
        }
        case 5:{
            Car c;
            c.read_from_file();
            break;
        }
        case 6:{
            Bike b;
            b.read_from_file();
            break;
        }
        case 7:
            cout<<"Thank you for using our system! Come back soon. "<<endl;
            break;

        default:
            cout<<"We are looking for a choice here (1, 2, 3 or 4)!"<<endl;
            break;
        }

    }while (choice != 7);

    return 0;
}
