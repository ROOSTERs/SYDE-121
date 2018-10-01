/*
Student Name: Surin Rao
Student Number: 20760312
Date: September 26th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab03
Exercise: 01
File name: lab03_01.cpp
Project: Lab03
Purpose: Prime Numbers

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
1. Have a for loop setting an int to the number the user entered
2. Take that number and modulo it by itself, and all numbers going down (i--)
3. Have a counter variable keep track of how many times the % of the number == 0
4. At the end, if the counter is less than or equal to 2, then cout the number as prime
5. Else say that the number is not prime
*/
#include <iostream>
using namespace std;

int main() {
int number;
int counter;
bool tester;

cout << "Enter a positive number: " << endl;
cin >> number;


    for(int i = number; i >= 0; i--) {
            counter = 0;
        for(int j = number; j >= 1; j++) {
            if(number % j == 0) {
                counter++;

            if(counter <= 2) {
                cout << i << "is prime" <<endl;
            }//if
            else {
                cout << "false" <<endl;
            }
            }
        }//for inside


    if(counter <= 2) {

    }//if

    else {

    }//else

    }//for



  return 0;
}//end main
