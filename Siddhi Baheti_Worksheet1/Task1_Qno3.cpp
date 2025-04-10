/* A program that reads an array of integer numbers from the user and sorts
the numbers in ascending order. */

#include <iostream>
using namespace std;

int main(){
    int n;
    //Asking the user for the total number of integers they want to sort
    cout<<"Enter the number of integers you want to sort: ";
    cin>> n;

    //Taking input of the numbers to be sorted from the user
    int numbers[n], temp;
    for (int i=0; i<n; i++){
        cout<<"Enter "<<i+1<<" value: ";
        cin>>numbers[i];
    }

    //Displaying the unsorted array
    cout<<"Your unsorted numbers: ";
    for (int i = 0; i<n; i++){
        cout<<numbers[i]<<"  ";
    }

    //Sorting the numbers
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++ ){
            if (numbers[i] > numbers[j]){
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    //Displaying the sorted array
    cout<<endl<<"Your sorted numbers: ";
    for (int i = 0; i<n; i++){
        cout<<numbers[i]<<"  ";
    }

    return 0;
}
