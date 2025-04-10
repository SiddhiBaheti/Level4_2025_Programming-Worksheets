/*
A program that takes a temperature value from the user and as per the user's choice converts it to either Celsius (C) or
Fahrenheit (F), then displays the output.
*/
#include <iostream>
using namespace std;

int main(){
    //Declaring variables of appropriate data types
    float input_temp, output_temp;
    int choice;

    //Taking input of the temperature value from the user
    cout<<"Enter temperature:";
    cin>>input_temp;

    while (cin.fail())//the loop will run until a valid temperature input is received
    {
        cin.clear(); //clearing the error flags
        cin.ignore(100, '\n'); //ignoring up to 100 characters or until a new line character is read

        cout<<"Invalid input! \nEnter the temperature in number: ";
        cin>>input_temp;
    }

    //Displaying the conversion options to the user and getting their choice as input
    cout<<"Welcome to Conversion Menu! \n 1. Convert Celsius to Fahrenheit \n 2. Convert Fahrenheit to Celsius \nEnter your choice:";
    cin>>choice;

    while (cin.fail() || (choice != 1 && choice != 2))//checking to ensure valid input is received
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Invalid input! \nEnter your choice (either 1 or 2):";
        cin>>choice;
    }

    //Performing the conversion as per user's choice
    if (choice == 1){
        output_temp = (input_temp * 1.8) + 32;
        cout<<input_temp<<" degree Celsius is "<<output_temp<<" degree Fahrenheit."<<endl;
    }
    else{
        output_temp = ((input_temp - 32)*5)/9;
        cout<<input_temp<<" degree Fahrenheit is "<<output_temp<<" degree Celsius."<<endl;
    }

    return 0;
}
