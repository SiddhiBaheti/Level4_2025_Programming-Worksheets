/* A cinema ticket booking system using arrays */

#include <iostream>
using namespace std;

int main(){

    //initializing a 5*5 2D Array for displaying the initial seating arrangement
    char seats[5][5] = {
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
    };
    char choice;

    cout<<"Welcome to the Cinema Ticket Booking System!"<<endl<<
    "Book your tickets for our latest show!"<<endl<<endl<<
    "The seating arrangement is as follows: "<<endl<<endl;

    //displaying the initial seating arrangement
    cout<<"    1 2 3 4 5"<<endl;
    cout<<"________________"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<i+1<<"|  ";
        for (int j = 0; j<5; j++){
           cout<<seats[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    //setting up a loop so that the user can book as many seats as they wish
    do{
        int user_row_choice, user_column_choice;

        //runs unless user chooses an available and valid seat
        while (true){
            cout<<"Please make your choice from the available seats: "<<endl;
            cout<<"Enter row number (1-5): ";
            cin>>user_row_choice;

            //validating the user's row input
            while (cin.fail() || user_row_choice < 0 || user_row_choice > 5 ){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Invalid row! Enter a correct row number (1-5): ";
                cin>>user_row_choice;
            }

            cout<<"Enter column number (1-5): ";
            cin>>user_column_choice;

            //validating the user's column input
            while (cin.fail() || user_column_choice < 0 || user_column_choice > 5){
                cin.clear();
                cin.ignore(100, '\n');
                cout<<"Invalid column! Enter a correct column number (1-5): ";
                cin>>user_column_choice;
            }

            //checking if the user's choice of seat is already booked or not
            if (seats[user_row_choice - 1][user_column_choice - 1] == 'X'){
                cout<<"The seat you have chosen is already booked!"<<endl;
            }
            else{
                seats[user_row_choice - 1][user_column_choice - 1] = 'X';
                break;
            }
        }

        //displaying the seat has been booked and the updated cinema seating arrangement
        cout<<endl<<"Your seat has been booked! Have a happy movie time :)"<<endl<<endl;
        cout<<"The updated seating arrangement!"<<endl;
        cout<<"    1 2 3 4 5"<<endl;
        cout<<"________________"<<endl;
        for (int i = 0; i < 5; i++){
            cout<<i+1<<"|  ";
            for (int j = 0; j<5; j++){
                cout<<seats[i][j]<<" ";
            }
            cout<<endl;
        }

        //asking if the user would like to book more tickets
        cout<<"Would you like to book more tickets? Press 'y' to continue."<<endl;
        cin>>choice;

    }while (choice == 'y' || choice == 'Y');

    cout<<endl<<"Thank you for using our ticket booking system!"<<endl;

    return 0;
}
