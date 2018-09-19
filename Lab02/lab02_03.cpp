/*
Student Name: Surin Rao
Student Number: 20760312
Date: September 19th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab02
Exercise: 03
File name: lab02_03.cpp
Project: Lab03
Purpose: Integer Sum

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
1. Create variables for n, a, and d
2. Set the equation with the correct variables
3. Set variable values
4. Add user input option

a. I tested the cases for 1 to 100, 1 to 3000, and 5 to 10000. I got 5050, 4501500, and 50045000. These were the correct answers, so the program works.
b. I added an input option where it would ask the user to input values for n and a (since d is always 1).
c. I did the math on my computer and got the same results as the ones my program got, proving to me that the program is right.
Some examples that I tested were 1 to 5 (15), 1 to 1000 (500500) which were correct. 
The range of values that are applicable are any integers, since it is just a sum calculator. 

*/

#include <iostream>
#include <math.h> //adding math library 
using namespace std;

int main () {

    /*------Variables---------*/
    int n; //number of integers to be added
    int a; //the first number
    int d = 1; //difference is always 1
    int sum;

    /*------Input and welcome----*/
    cout << "Welcome, user!" << endl; //opening welcome

    cout << "What n value (number of ints to be added) do you want? "; //asking the question
    cin >> n; //this will store the value they input
    cout << "What a value (starting/first int) do you want? ";
    cin >> a;

    /*-----Equation for getting the sum------*/
    sum = (n / 2) * (2 * a + (n - 1) * d);


    /*------------ Output-------------*/
    cout << sum << endl;


    return 0;

}//end int main()





