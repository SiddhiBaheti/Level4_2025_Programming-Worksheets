/* Program that takes a positive integer as input and determines whether the number is
bouncy or not. */


#include <iostream>
using namespace std;

int main(){
    int num;

    //taking input
    cout<<"Enter a positive number: ";
    cin>>num;

    //checking if the input is a positive number
    while(cin.fail()|| num <= 0){
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Invalid entry! Enter a positive number: ";
        cin>>num;
    }

    bool increase = false;
    bool decrease = false;
    //preserving the original number input
    int temp = num;
    int last_digit, current_digit;

    //logic for checking if the number is bouncy or not
    last_digit = temp % 10;
    temp = temp / 10;

    //extracting digits one by one and checking if they are increasing or decreasing
    while (temp != 0){
        current_digit = temp % 10;
        if (current_digit < last_digit){
            increase = true;
        }
        if(current_digit > last_digit){
            decrease = true;
        }

        last_digit = current_digit;
        temp = temp / 10;
    }

    //displaying output as per our boolean values
    if (increase == true && decrease == true){
        cout<<num<<" is a BOUNCY number!"<<endl;
    }
    else{
        cout<<num<<" is not a BOUNCY number!"<<endl;
    }

    return 0;
}

