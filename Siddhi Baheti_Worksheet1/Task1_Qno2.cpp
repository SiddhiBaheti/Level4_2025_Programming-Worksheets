/* A number guessing game with different difficulty levels where
1. Easy Level - Guess number between 1 - 8
2. Medium Level - Guess number between 1 - 30
3. Hard Level - Guess number between 1 - 50
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //Declaring variables
    int choice, guess, number_to_be_guessed, max_range;

    //Displaying Game Menu
    cout<<"Welcome to the Number Guessing Game! \n 1.Easy (1-8) \n 2.Medium (1-30) \n 3.Hard (1-50) \nChoose your level: ";
    cin>>choice;

    //Validating the input
    while (cin.fail() || (choice != 1 && choice != 2 && choice != 3)){
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Invalid Input! Choose 1, 2 or 3 as per your level choice: ";
        cin>>choice;
    }

    next:
    if (choice == 1){
        max_range = 8;
    }
    else if (choice == 2){
        max_range = 30;
    }
    else{
        max_range = 50;
    }

    //generating random number based on the user's choice of level
    srand(time(0)); //for the generation of new random number each time the program is run
    number_to_be_guessed = 1 + (rand() % max_range);

    cout<< "Enter a number between the range 1 to "<<max_range<<" : ";
    cin>> guess;
    int attempt = 1;

    //checking for non-numeric inputs
    while (cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Invalid input! Enter a valid number: ";
        cin>>guess;
    }

    //matching the user's guess with the randomly generated number
    while (guess != number_to_be_guessed){
        if (guess < 1 || guess > max_range){
            cout<<"Number is out of range."<<endl;
        }
        else if (guess < number_to_be_guessed){
            cout<<"Low guess! Aim higher!"<<endl;
        }
        else{
            cout<<"High guess! Little lower perhaps!"<<endl;
        }
        cout<<"Try Again, another guess: ";
        cin>>guess;

        //checking for non-numeric inputs
        while (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Invalid input! Enter a valid number: ";
            cin>>guess;
        }
        attempt = attempt + 1;
    }

    cout<<"Congratulations! Guessed it right!"<<endl;

    //Asking if the user wants to move on to higher levels
    char ch;
    if (choice < 3){
        cout<<"Do you want to proceed to next level? (y/n): "<<endl;
        cin>>ch;
        ch = tolower(ch);
        if (ch == 'y'){
            choice = choice + 1;
            goto next;
        }
        else{
            cout<<"Thank you for playing the game! Hope you enjoyed it."<<endl;
        }
    }
    else{
        cout<<endl<<"You have made history! Cracked the most difficult level in "<<attempt<<
        " attempts, kudos to you!"<<endl;
    }

    return 0;
}
