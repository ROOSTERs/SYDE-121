/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 14th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab07
Exercise: 01
File name: lab07_01.cpp
Project: Lab07
Purpose: Bowling

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline:
1. Create functions for printing the pins and the rows
2. It has to be a diamond formation, so make sure recursion increments/decrements
3. Add user input so they can enter the number of pin rows 

To test this code, I went through the numbers 1- 10 to see the pattern that was outputted, and to make sure it was correct.
It was correct, so I then tried to do tougher numbers. When I inputted 0, it printed out nothing like expected. I then tried 42 which
outputted a giant diamond, which was still correct. This showed me that bigger numbers still worked, even if they were hard to see in my
terminal window. I then inputted -4 to see how it would react to anegative number, which broke my code and it kept printing
*. This is why I added in an if statement, to make sure the user puts in a valid + number. I then entered 1111111111, a very large
number, which also broke my code. I then tested 100, which still produced a pretty clear diamond shape still, so this showed me 
that bigger numbers still worked, but very very big numbres just make a bad shape, which is why I limited the max to under 100 (so it
still look a bit nice and like the desired pattern).
*/
#include <iostream>

using namespace std;

/*-----------------------Function Prototyping------------------------*/
void pins(int i);
void pins(int i, int current_line);
void printing(int i, int line);

/*-----------------------Main------------------------*/
int main() {
    //Variable declaration and user input
    int pin_pattern;
    cout << "Please enter the number of pin rows you want (0-100)" << endl;
    cin >> pin_pattern;
    cout << endl;

    if (pin_pattern < 0 || pin_pattern > 100) {
        cout << "Please select a valid number" << endl;
    }//if, testing for validity
    else {
    pins(pin_pattern);
    }//else run it 

    return 0;
}//main

/*-----------------------Print_row------------------------*/
void printing(int i, int line) {

    int num_spaces = (i - line + 1);

    for (int x = 1; x <= num_spaces; x++) {
        cout << " ";
    }//for loop space 

    for (int x = 1; x <= ((2 * line) - 1); x++) {
        if (x % 2 == 0) {
            cout << " ";
        }//printing space
        else if (x % 2 != 0) { //alternating so it will do space then star then space...
            cout << "*";
        }//printing star 
    }//for 

cout << endl;
}//printing 

/*-----------------------Pins------------------------*/
void pins(int i) {
    pins(i, 1);
}//pins, calling next pins function (with current line 1)

/*-----------------------Pins------------------------*/
void pins(int i, int current_line) {
    if (current_line == i) {
        printing(i, current_line);
    }//if
    else {
        printing(i, current_line);
        pins(i, current_line + 1);
        printing(i, current_line);
    }//else
}//pins 
