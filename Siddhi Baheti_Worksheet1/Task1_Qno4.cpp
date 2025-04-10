/* A program that reads a number from the user and on the basis of the input, its says what day of the
week it is. */

#include <iostream>
using namespace std;

int main(){
    int num;

    //Getting user input
    cout<<"Enter the number between 1 - 7 to find the day of the week: ";
    cin>>num;

    //Using switch case to display the day of the week as per user input
    switch (num){
    case 1:
        cout<<"It's a SUNDAY!"<<endl;
        break;
    case 2:
        cout<<"It's a MONDAY!"<<endl;
        break;
    case 3:
        cout<<"It's a TUESDAY!"<<endl;
        break;
    case 4:
        cout<<"It's a WEDNESDAY!"<<endl;
        break;
    case 5:
        cout<<"It's a THURSDAY!"<<endl;
        break;
    case 6:
        cout<<"It's a FRIDAY!"<<endl;
        break;
    case 7:
        cout<<"It's a SATURDAY!"<<endl;
        break;
    default:
        cout<<"Invalid input! Enter a number between 1 - 7."<<endl;
        break;
    }

    return 0;
}
