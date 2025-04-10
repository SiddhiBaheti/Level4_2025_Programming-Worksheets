/* A program that uses friend function to compare two circle objects and find the larger area */

#include <iostream>
using namespace std;

class Circle{
private:
    //declaring private variables
    float radius;
public:
    //constructor to initialize radius
    Circle(float r){
        radius = r;
    }

    //function to calculate area of the circle
    float Area(){
        area = 3.14 * radius * radius;
        return area;
    }

    //friend function declaration
    friend void compareTwoCircles(Circle &x, Circle &y);
};

//friend function to compare the area of two circle objects
void compareTwoCircles(Circle &x, Circle &y){
    //calculating the area for both circles using Area() function of Circle Class
    float area1 = x.Area();
    float area2 = y.Area();

    //comparing the areas and printing the circle with larger area
    if (area1 > area2){
        cout<<"Circle with radius "<<x.radius<<" has a larger area which is "<<area1<<endl;
    }
    else if (area1 < area2){
        cout<<"Circle with radius "<<y.radius<<" has a larger area which is "<<area2<<endl;
    }
    else{
        cout<<"Equal area of the two circles!"<<endl;
    }
}

int main(){
    float radius1, radius2;

    //getting radius for first circle
    cout<<"Enter radius for circle 1: ";
    cin>>radius1;
    Circle c1(radius1);

    //getting radius for second circle
    cout<<"Enter radius for circle 2: ";
    cin>>radius2;
    Circle c2(radius2);

    //comparing the two circle by passing objects
    compareTwoCircles(c1, c2);

    return 0;
}
