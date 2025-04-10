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

int main(){
    //calling functions as per needed
    cout<<"The maximum between the two integers 265 and 125: "<<findMax(265, 125)<<endl;
    cout<<"The maximum between the two floating-point numbers 14.5 and 13.1: "<<findMax(14.5f, 13.1f)<<endl;
    cout<<"The maximum between the three integers 445, 325 and 995: "<<findMax(445, 325, 995)<<endl;
    cout<<"The maximum between an integer 15 and a floating-point number 20.1: "<<findMax(15, 20.1f)<<endl;
    return 0;
}
