/*
Student Name: Surin Rao
Student Number: 20760312
Date: September 26th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab03
Exercise: 02
File name: lab03_02.cpp
Project: Lab03
Purpose: Ball Drop

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
a.
1. Create variables for gravity (constant), time, distance and total distance. Make sure they are double and not int
2. Write down the equation for solving for distance
3. Make sure distance gets reset while total distance gets added every time
4. Output the distances every 1 second
b.
1. Modify the program to do 0.1s intervals
2. We have no need for total distance since we know it is being dropped from 15000
3. Don't let the program continue for distance above 15000 as the ball will have hit the ground

a. For a we used to have the for loop restricted using time, and saying time had to be less than or equal to 20 seconds.
This will have given us the distance and total distance up to 20s.
b. Now that we know the drop height, we have to restrict the for loop using distance and change the time interval to 0.1s.
We can't print any numbers above 15000m because that would mean the ball is going through the ground.
*/
#include <iostream>
using namespace std;

int main() {

/*----Variable Declaration------*/
double time = 0;
const double GRAVITY = 9.80665;
double distance;
double drop_height = 15000;
//double distance_input;
//double total_distance = 0; //used in part a to calculate total distance
//The formula that was used for a was: total_distance = total_distance + distance



/*-------Precision Settings---------*/
cout.setf(ios::fixed); //set to fixed precision
cout.setf(ios::showpoint); // always show point
cout.precision(3); //4 digit decimal precision

/*------------ Table Header ------------*/
cout << "Distance traveled (m)" << "\t\t\t\t\t" << "Time (s)" << endl;

/*---------Conditions for outputting time and distance-----------*/
    for(distance = 0; distance <= drop_height; time += 1) { //set distance <= 15000 because that is what the question specified,
        //we could use a variable (input_distance) if we wanted it to be applicable to all scenarios
        distance = (0.5) * (GRAVITY) * (time) * (time);

        if(distance < 1000) {
            cout << distance << "\t\t\t\t\t\t\t" << time << endl;
        }//if <1000

        else if(distance > 1000) {
            cout << distance << "\t\t\t\t\t\t" << time << endl;

            if (distance >= (drop_height - (drop_height / 15))) {
                cout << "\n \t\t It is getting closer to the ground!\n" << endl;

                for(distance = 0; distance <= drop_height; time += 0.1) {
                    distance = (0.5) * (GRAVITY) * (time) * (time);

                    if (distance < drop_height && distance > (drop_height - (drop_height / 15))) {
                        cout << distance << "\t\t\t\t\t\t" << time << endl;
                    }//if
                }//nested for the 0.1s part
            }//if >14000
        }// else if > 1000
    }//big for loop

    cout << "\t\t\tThe ball has hit the ground!" << endl;

return 0;
}//end main
