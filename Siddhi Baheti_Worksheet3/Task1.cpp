/* A program that has a time class that stores hours and minutes and overloads the + operator to add two Time objects
and > operator to compare two Time Objects. */

#include <iostream>
using namespace std;

class Time{
private:
    int hour, minute;
public:
    //default constructor to initialize hour and minute
    Time(){
        hour = 0;
        minute = 0;
    }

    Time(int h, int m){
        //handling invalid time exceptions
        if (h < 0 || h > 24 || m < 0 ||m > 60){
            throw 1;
        }

        hour = h;
        minute = m;
    }

    //overloading the + operator to add two time objects
    Time operator +(Time T){
        Time temp;
        temp.minute = minute + T.minute;
        int m = temp.minute/60;
        temp.minute = temp.minute % 60;
        temp.hour = hour + T.hour + m;
        return temp;
    }

    //overloading the > operator to compare two time objects
    bool operator >(Time T){
        if (hour > T.hour){
            return true;
        }
        else if (hour == T.hour && minute > T.minute){ //if the hour is same comparing minutes
            return true;
        }
        else{
            return false;
        }
    }

    //displaying the time in hours and minutes
    void display(){
        cout<<hour<<" Hr "<<((minute < 10) ? "0" : "")<<minute<<" Min"<<endl;
    }
};

int main(){
    int h1, m1, h2, m2;

    try{
        //taking user input for first time
        cout<<"Enter the first time, hours and minutes: ";
        cin>>h1>>m1;
        Time t1(h1, m1);

        //taking user input for second time
        cout<<"Enter the second time, hours and minutes: ";
        cin>>h2>>m2;
        Time t2(h2, m2);

        //displaying systematically
        cout<<"\nFirst Time: ";
        t1.display();

        cout<<"Second Time: ";
        t2.display();

        Time t3 = t1 + t2;
        cout<<"Sum of the times: ";
        t3.display();

        if (t1 > t2){
            cout<<"The first time is greater than the second time." <<endl;
        }
        else{
            cout<<"The second time is greater than or equal to the first time." <<endl;
        }
    }
    catch (int a){
        cout<<"ERROR! Hours should be between 0 to 24 and Minutes should be between 0 to 60."<<endl;
    }

    return 0;
}

