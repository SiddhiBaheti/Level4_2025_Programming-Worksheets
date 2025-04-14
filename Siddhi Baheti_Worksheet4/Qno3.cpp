/* Queue Problem:
This program implements a queue using a fixed size array of 10 elements and performs the following:
- Basic enqueue and dequeue operations
- Reverses the first K elements
- Interleaves first half with second half
- Handles queue overflow/underflow
*/

#include <iostream>
using namespace std;

class Queue{
    int queueOfIntegers[10];
    int frontP, rear;

public:
    Queue(){
        frontP = -1;
        rear = -1;
    }

    //function to get value from the user
    int getValue(){
        int value;

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

    //function to insert values into the queue
    void enqueue(){
        //ensuring that the queue has space
        if (rear == 9){
            cout<<"Queue overflow!"<<endl;
        }
        else{
            //changing the front pointer
            if (frontP == -1){
                frontP = 0;
            }

            rear++;
            queueOfIntegers[rear] = getValue();
            cout<<"Value added successfully!"<<endl;
        }
    }

    //function to remove values from the queue
    void dequeue(){
        if (frontP == -1 || frontP > rear){ //checking if the queue is empty
            cout<<"Queue underflow!"<<endl;
        }
        else{
            cout<<queueOfIntegers[frontP]<<" is deleted from the queue."<<endl;
            frontP++;
        }
    }

    //function to reverse the queue up to first k elements
    void reverseQueue(){
        if (frontP == -1){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        int k;

        cout<<"Enter up to where you wish to reverse the elements: ";
        cin>>k;

        //validating the value of k
        while (cin.fail() || k <= 0 || k > (rear - frontP + 1) ){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Invalid input! Enter valid k (1 to "<<(rear - frontP + 1)<<"): ";
            cin>>k;
        }

        int start = frontP; //setting start pointer to the front of the queue
        int endP = frontP + k - 1; //setting end pointer to the k-th element

        while (start < endP){
            //swapping values
            swap(queueOfIntegers[start], queueOfIntegers[endP]);
            start++;
            endP--;
        }

        cout<<"Queue reversed up to "<<k<<" successfully!"<<endl;

        char choice;
        //asking user if they want to view the changes made
        cout<<"Do you want to view the changes? Press 'y' to continue. "<<endl;
        cin>>choice;

        if (choice == 'y' || choice == 'Y'){
            display();
        }
    }

    //function to interleave elements of the queue
    void interleave(){
        if (frontP == -1 || frontP > rear){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        int total = rear - frontP + 1;

        if(total % 2 != 0){
            cout<<"Interleaving elements requires an even number of elements!"<<endl;
            return;
        }
        else{
            int half = total/2;

            //creating a temporary queue
            int temp[10];
            int i = frontP; //pointer at the start of the first half
            int j = frontP + half; //pointer at the start of second half

            int index = 0;
            while (index < total){
                temp[index++] = queueOfIntegers[i++];
                temp[index++] = queueOfIntegers[j++];
            }

            //copying the interleaved queue to the original queue
            for (int m = 0; m < total; m++){
                queueOfIntegers[frontP + m] = temp[m];
            }

            cout<<"Queue interleaved successfully!"<<endl;

            char choice;
            //asking user if they want to view the changes made
            cout<<"Do you want to view the changes? Press 'y' to continue. "<<endl;
            cin>>choice;

            if (choice == 'y' || choice == 'Y'){
                display();
            }

        }
    }

    //function to display queue elements
    void display(){
        if (frontP == -1){
            cout<<"Queue is empty!"<<endl;
        }
        else{
            cout<<"\nDisplaying the elements of the queue!\n";
            for (int i = frontP; i <= rear; i++){
                cout<<queueOfIntegers[i]<<" ";
            }
            cout<<endl;
        }
    }

    //function to display the menu options to the user
    void startMenu(){
        int choice;

        do{
            //displaying menu to the users
            cout<<"\nWelcome to Queue Manipulation Menu!"<<endl;
            cout<<"1. Insert elements into queue (Enqueue)"<<endl<<
            "2. Remove elements from queue (Dequeue)"<<endl<<
            "3. Reverse the first k elements"<<endl<<
            "4. Interleave the queue"<<endl<<
            "5. Display all queue elements"<<endl<<
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
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                reverseQueue();
                break;
            case 4:
                interleave();
                break;
            case 5:
                display();
                break;
            case 6:
                cout<<"Thank you for using our system!"<<endl;
                break;
            default:
                cout<<"Enter a valid choice!"<<endl;
                break;
            }

        }while(choice != 6);
    }

};

int main(){
    Queue q;
    q.startMenu();

    return 0;
}
