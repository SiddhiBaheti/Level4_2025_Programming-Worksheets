/* A basic student grading system prototype
The program manages a simple student grade calculator.*/

#include <iostream>
#include <string>
using namespace std;

class Student{
    string student_name;
    int maths_marks, science_marks, english_marks;

public:
    //a function to get input from user
    void getStudentInfo(){
        cout<<"Enter Student Name: ";
        getline(cin, student_name); //done to take space characters as input

        //calling another function to validate marks
        maths_marks = validateMarks("Mathematics");
        science_marks = validateMarks("Science");
        english_marks = validateMarks("English");
    }

    //function to check if the marks input is integer and within the 0-100 range
    int validateMarks(string subject){
        int marks;
        cout<<"Enter marks for "<<subject<<" (0-100) : ";
        cin>>marks;

        while (cin.fail() || marks < 0 || marks > 100){
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"Marks way out of range!Try Again!"<<endl;
            cout<<"Enter marks for "<<subject<<" (0-100) : ";
            cin>>marks;
        }

        return marks;
    }

    //calculating the total marks
    int totalMarks(){
        int total = maths_marks + science_marks + english_marks;
        return total;
    }

    //calculating average marks of the student
    float averageMarks(){
        float average = float(totalMarks())/3;
        return average;
    }

    //calculating the grade as per the range
    char gradeCalculator(){
        int marks = averageMarks();
        if (marks >= 90 and marks <= 100){
            return 'A';
        }
        else if (marks >= 80 && marks <90){
            return 'B';
        }
        else if (marks >= 70 && marks < 80){
            return 'C';
        }
        else if (marks >= 60 && marks < 70){
            return 'D';
        }
        else{
            return 'F';
        }
    }

    //displaying all the details and calculations to the user
    void displayInfo(){
        cout<<endl<<"Calculating Result Information of "<<student_name<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"Total Obtainable Marks: 300"<<endl;
        cout<<"Obtained Marks: "<<totalMarks()<<endl;
        cout<<"Average Marks obtained: "<<averageMarks()<<endl;
        cout<<"Obtained Overall Grade: "<<gradeCalculator()<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<endl<<"Thank you for using our Student Grade Calculator system!"<<endl;
    }
};

int main(){
    cout<<"Welcome to Student Grade Calculator!"<<endl;

    Student s1;
    s1.getStudentInfo();
    s1.displayInfo();

    return 0;
}
