/* STL container practice program
A program that allows user to store name and age, find all people above certain age and
sort and display names alphabetically.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class People{
private:
    //declaring the data structures to store names and age
    vector <string> names;
    map <string, int> nameAgePair;
public:
    //function to add name and age
    void addNameAge(){
        string name;
        int age;

        cin.ignore(); //ignoring any other leftover input characters
        cout<<"Enter name: ";
        getline(cin, name); //reading space characters

        //changing the entered name to uppercase
        name = nameToCapital(name);

        age = validateAge();

        names.push_back(name);
        nameAgePair[name] = age;
    }

    //function to convert the name given by the user to capital letters
    string nameToCapital(string name){
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        return name;
    }

    //function to check that age is a positive integer
    int validateAge(){
        int age;

        cout<<"Enter age: ";
        cin>>age;

        //checking if the entered age is a positive number
        while (cin.fail() || age < 0){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Age is a positive number! Enter a reasonable age: ";
            cin>>age;
        }

        return age;
    }

    //function to find people above a certain age
    void findPeople(){
        int ageLimit;

        //asking user for the age limit
        cout<<"Enter age limit: ";
        cin>>ageLimit;

        cout<<"\nAll people older than "<<ageLimit<<" have been listed below. \n";
        cout<<"---------------------------------------------------------\n";

        bool found = false;
        int i = 1;

        for (const auto& [name, age] : nameAgePair){
            //comparing if the age is greater than agelimit
            if (age > ageLimit){
                //displaying values that meet the requirement
                cout<<i<<". Name: "<<name<<" | Age: "<<age<<endl;
                found = true;
                i++;
            }
        }

        if (!found){
            cout<<"No one found  above the age "<<ageLimit<<". \n";
        }
    }

    //function to sort and display names alphabetically
    void sortandDisplayNames(){
        if (names.empty()){
            cout<<"Records are empty! No names to display."<<endl;
            return;
        }

        vector<string> sortedNames = names; //creating a new vector variable to store the sorted names
        sort(sortedNames.begin(), sortedNames.end()); //sorting the names

        cout<<"\n All Names in alphabetical order\n";
        cout<<"---------------------------------------------------------\n";

        int i = 1;

        //displaying the names alphabetically along with their age
        for (const string& name: sortedNames){
            cout<<i<<". Name: "<<name<<" , Age: "<<nameAgePair[name]<<endl;
            i++;
        }
    }

    //function to display menu for the user
    void displayMenu(){
        int choice;
        do{
            cout<<"\n--------------- Welcome! ---------------\n";
            cout<<" 1. Add new name and age \n 2. Find all people above a certain age \n 3. Sort and Display names alphabetically \n 4. Exit \n";
            cout<<"Make a choice as to how you would like to move forward: ";
            cin>> choice;

            while (cin.fail()){ //checking for non-numeric input
                cin.clear();
                cin.ignore();
                cout<<"Enter a valid number choice (1-4): ";
                cin>>choice;
            }

            switch (choice){
            case 1:
                addNameAge();
                break;
            case 2:
                findPeople();
                break;
            case 3:
                sortandDisplayNames();
                break;
            case 4:
                cout<<"\nThank you for using our system!\n";
                break;
            default:
                cout<<"Make a valid choice (1-4)."<<endl;
                break;
            }
        }while (choice != 4);
    }
};

int main(){
    People p;
    p.displayMenu();

    return 0;
}
