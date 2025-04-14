/* A linked list manipulation program which allows the user to:
- insert nodes at start/end/position
- detect and remove loops
- find nth node from end
- reverse list in groups of K nodes
*/

#include <iostream>
using namespace std;

class LinkedList {

    struct Node {
        int data; //stores the data value of the node
        Node* next; //pointer to the next node in the linked list
    };

    Node* head; //pointer to the first node in the linked list

public:
    //default constructor to initialize the list as empty
    LinkedList() {
        head = nullptr; //list is empty at the beginning
    }

    //Function to get data from the user
    int getDataValue(){
        int value;
        cout<<"Enter a number: ";
        cin>>value;

        while (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Try Again! Enter a number: ";
            cin>>value;
        }

        return value;
    }

    //Function to insert data at the beginning of the linked list
    void insertAtStart() {
        Node* newNode = new Node(); //creating a new node
        newNode->data = getDataValue(); //storing data value in the new node
        newNode->next = head; //linking it to the current first node
        head = newNode; //making the new node the first node
        cout<<"Value added successfully!"<<endl;
        display();
    }

    //Function to insert data at the ending of the linked list
    void insertAtEnd() {
        Node* newNode = new Node();
        newNode->data = getDataValue();
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        //finding the last node
        while (temp->next != nullptr){
            temp = temp->next;
        }
        //inserting the new node at the end
        temp->next = newNode;
        cout<<"Value added successfully!"<<endl;
        display();
    }

    //Function to get position of insertion from the user
    int getPosition(){
        int position;

        cout<<"Enter position where you wish to insert the value: ";
        cin>>position;

        while(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter an integer value of position: ";
            cin>>position;
        }

        return position;
    }

    //Function to insert data at user specified position
    void insertAtPosition() {
        int position = getPosition();

        //inserting the node at the beginning, if the position given by the user is 1
        if (position == 1) {
            insertAtStart();
            return;
        }

        Node* newNode = new Node();
        newNode->data = getDataValue();

        //traversing to the node before the desired position
        Node* temp = head;
        for (int i = 1; (i < position - 1 && temp != nullptr); i++){
            temp = temp->next;
        }

        //if the position is out of bounds
        if (temp == nullptr) {
            cout << "Position out of range.\n"<<endl;
            return;
        }

        //inserting the new node at the specified position
        newNode->next = temp->next;
        temp->next = newNode;
        cout<<"Value added successfully!"<<endl;
        display();
    }

    //Function to get n from user
    int getN(){
        int n;

        cout<<"Enter the position (n) from the end: ";
        cin>>n;

        while (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter an integer value of position: ";
            cin>>n;
        }

        return n;
    }

    //Function to find the nth node from end
    void findNthFromEnd() {
        int n = getN();
        int length = 0;
        Node* temp = head;

        //calculating the length of the linked list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        //checking if the n given by the user is greater than the length of list
        if (n > length) {
            cout << "Not enough nodes.\n";
            return;
        }

        temp = head;
        for (int i = 0; i < length - n; i++){
            temp = temp->next;
        }

        //printing the value of the nth node from the end
        cout << n << "th node from end is: " << temp->data << endl;
    }

    //Function to get value of k
    int getK(){
        int k;
        cout<<"Enter value of K: ";
        cin>> k;

        while (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Enter an integer value of K: ";
            cin>>k;
        }

        return k;
    }


    void reverseK() {
        int k = getK();
        head = reverseInGroups(head, k);
    }

    //Function to reverse list in groups of K-nodes
    Node* reverseInGroups(Node* node, int k) {
        Node* current = node;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr)
            node->next = reverseInGroups(next, k);

        return prev;
    }

    //Function to detect and remove loop
    void detectAndRemoveLoop() {
        Node* slow = head;
        Node* fast = head;

        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                removeLoop(slow);
                cout << "Loop detected and removed.\n";
                return;
            }
        }
        cout << "No loop found.\n";
    }

    void removeLoop(Node* loopNode) {
        Node* start = head;
        while (start->next != loopNode->next) {
            start = start->next;
            loopNode = loopNode->next;
        }
        loopNode->next = nullptr;
    }


    //Function to display the linked list
    void display() {
        cout<<endl;
        cout<<"Displaying the Linked List!"<<endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    //function to show menu options to the user
    void startMenu(){
        int choice;
        do{
            cout<<"\nWelcome to Linked List Menu!"<<endl;
            cout<<"1. Insert node at the beginning"<<endl<<
            "2. Insert node at the end"<<endl<<
            "3. Insert node at specific position"<<endl<<
            "4. Find the nth node from end"<<endl<<
            "5. Reverse lists in groups of K nodes"<<endl<<
            "6. Detect and remove loops"<<endl<<
            "7. Display the linked list"<<endl<<
            "8. Exit"<<endl<<
            "Enter your choice: ";
            cin>>choice;

            while (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Enter a valid number (1-7): ";
                cin>>choice;
            }

            switch(choice){
            case 1:
                insertAtStart();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                findNthFromEnd();
                break;
            case 5:
                reverseK();
                break;
            case 6:
                detectAndRemoveLoop();
                break;
            case 7:
                display();
                break;
            case 8:
                cout<<"Thank you for using our system!"<<endl;
                break;
            default:
                cout<<"Enter valid menu choice (1-7)!" <<endl;
                break;
            }
        }while (choice != 8);
    }
};

int main() {
    LinkedList l;
    l.startMenu();

    return 0;
}

