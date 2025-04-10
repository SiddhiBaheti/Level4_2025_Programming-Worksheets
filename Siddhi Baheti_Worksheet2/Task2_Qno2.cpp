/* A program that uses overloaded function to find maximum between different numbers */

#include <iostream>
using namespace std;

//function that finds maximum between two integers and returns it
int findMax(int a, int b){
    if (a > b){
        return a;
    }
    else if (b > a){
        return b;
    }
    else{
        cout<<"The numbers are equal!"<<endl;
    }
}

//function that finds maximum between two floating-point numbers and returns it
float findMax(float a, float b){
    if (a > b){
        return a;
    }
    else if(b > a){
        return b;
    }
    else{
        cout<<"The numbers are equal!"<<endl;
    }
}

//function that finds maximum between three integers and returns it
int findMax(int a, int b, int c){
    if (a > b && a > c){
        return a;
    }
    else if (b > a && b > c){
        return b;
    }
    else if (c > a && c > b){
        return c;
    }
    else{
        cout<<"The numbers are equal!"<<endl;
    }
}

//function that finds maximum between one integer and one floating point number
float findMax(int a, float b){
    if (float(a) > b){
        return float(a);
    }
    else{
        return b;
    }
}

/*
void getNumbers(){
    int ch;
    cout<<"Find the Maximum in Numbers!"<<endl;
    cout<<"1. Maximum between two integers" <<endl<<
    "2. Maximum between two decimal numbers"<<endl<<
    "3. Maximum among three integers"<<endl<<
    "4. Maximum between one decimal and one integer number"<<endl<<
    "Press the number as you wish to continue."<<endl<<
    "Enter your choice: ";
    cin>>ch;

    switch (ch){
    case 1:{
        int num1, num2, maximum;
        cout<<"Enter first integer: ";
        cin>>num1;
        cout<<"Enter second integer: ";
        cin>>num2;
        maximum = findMax(num1, num2);
        cout<<"Maximum number = "<<maximum;
        break;
    }
    case 2:{
        float num1, num2, maximum;
        cout<<"Enter first decimal number: ";
        cin>>num1;
        cout<<"Enter second decimal number: ";
        cin>>num2;
        maximum = findMax(num1, num2);
        cout<<"Maximum number = "<<maximum;
        break;
    }
    case 3:{
        int num1, num2, num3, maximum;
        cout<<"Enter first integer: ";
        cin>>num1;
        cout<<"Enter second integer: ";
        cin>>num2;
        cout<<"Enter third integer: ";
        cin>>num3;
        maximum = findMax(num1, num2, num3);
        cout<<"Maximum number = "<<maximum;
        break;
    }
    case 4:{
        int num1;
        float num2, maximum;
        cout<<"Enter an integer: ";
        cin>>num1;
        cout<<"Enter a decimal number: ";
        cin>>num2;
        maximum = findMax(num1, num2);
        cout<<"Maximum number = "<<maximum;
        break;
    }
    default:{
        cout<<"Invalid choice!"<<endl;
        getNumbers();
        break;
    }
    }
}
*/

int main(){
    //calling functions as per needed
    cout<<"The maximum between the two integers 265 and 125: "<<findMax(265, 125)<<endl;
    cout<<"The maximum between the two floating-point numbers 14.5 and 13.1: "<<findMax(14.5f, 13.1f)<<endl;
    cout<<"The maximum between the three integers 445, 325 and 995: "<<findMax(445, 325, 995)<<endl;
    cout<<"The maximum between an integer 15 and a floating-point number 20.1: "<<findMax(15, 20.1f)<<endl;
    return 0;
}
