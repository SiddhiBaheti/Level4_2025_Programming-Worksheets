/* Stack Problem:
This program implements a stack using a fixed size array of 10 elements and performs the following:
- Push and pop operations
- Finds the middle element
- Reverse only bottom half of the stack
- Displays all the elements
*/

#include <iostream>
using namespace std;

class Stack{
    int stackOfIntegers[10]; //creating a fixed size array of 10 elements
    int top;

public:
    //default constructor to initialize top to -1 (empty stack)
    Stack(){
        top = -1;
    }

    //function to get values from user
    int getValue(){
        int value;

        //getting input from user
        cout<<"Enter a number: ";
        cin>>value;

        //checking if the value entered is numeric
        while (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Try Again! Enter a number: ";
            cin>>value;
        }

        return value;
    }

    //function to push element into the stack
    void push(){
        if (top >= 9){
            cout<<"Stack Overflow! Only 10 elements can be taken."<<endl;
            return;
        }
        else{
            int value = getValue();
            top++;
            stackOfIntegers[top] = value;
            cout<<"Value added successfully!"<<endl;
        }
    }

    //function to check if the stack is empty
    bool stackEmpty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    //function to pop elements from the stack
    void pop(){
        if (stackEmpty()){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        else{
            cout<<"Value "<<stackOfIntegers[top]<<" deleted successfully!"<<endl;
            top--;
        }
    }

    //function to find the middle element of the stack
    void findMiddle(){
        if(stackEmpty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        else{
            int mid = top/2;

            cout<<"Middle element of the stack: "<<stackOfIntegers[mid]<<endl;
        }
    }

    //function to reverse the bottom half of the stack
    void reverseBottomHalf(){
        if (stackEmpty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }

        int middle = (top + 1)/2; //finding the number of elements in the bottom half

        //swapping the bottom half numbers
        for (int i = 0; i < middle / 2; i++){
            swap(stackOfIntegers[i], stackOfIntegers[middle - i - 1]);
        }

        cout<<"Bottom half elements reversed successfully!"<<endl;

        char choice;
        //asking user if they want to view the changes made
        cout<<"Do you want to view the changes? Press 'y' to continue. "<<endl;
        cin>>choice;

        if (choice == 'y' || choice == 'Y'){
            displayStack();
        }
    }

    //function to display the entire stack
    void displayStack(){

        if (stackEmpty()){
            cout<<"Stack is empty!"<<endl;
            return;
        }

        else{
            cout<<"Displaying Stack Elements!"<<endl;

            for(int i = top; i >= 0; i--){ //displaying elements from bottom to top
                cout<<stackOfIntegers[i]<<" ";
            }
            cout<<endl;
        }
    }

    //function to display the options to the user
    void startMenu(){
        int choice;
        do{
            //displaying menu to the users
            cout<<"\nWelcome to Stack Manipulation Menu!"<<endl;
            cout<<"1. Push elements into stack"<<endl<<
            "2. Pop elements into stack"<<endl<<
            "3. Find the middle element"<<endl<<
            "4. Reverse the bottom half of the stack"<<endl<<
            "5. Display all stack elements"<<endl<<
            "6. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            //validating choice for numeric input
            while (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Enter a numeric choice (1-6): ";
                cin>>choice;
            }

            switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                findMiddle();
                break;
            case 4:
                reverseBottomHalf();
                break;
            case 5:
                displayStack();
                break;
            case 6:
                cout<<"Thank you for using our system!"<<endl;
                break;
            default:
                cout<<"Enter a valid choice!"<<endl;
                break;
            }
        }while (choice != 6);
    }
};

int main() {
    Stack s1;
    s1.startMenu();
    return 0;
}
