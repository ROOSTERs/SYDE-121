/*
Student Name: Surin Rao
Student Number: 20760312
Date: September 19th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab02
Exercise: 01
File name: lab02_01.cpp
Project: Lab02
Purpose: Weight breakdown

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
1. Have an original weight
2. Create variables for each weight zone
3. Create a variable for the remainder left over after the divide
4. Divide the given weight by the biggest (150)
5. Also calculate the remainder
6. Repeat going down by weight zone until remainder is 0

a. I started by testing the original 1048 value, to make sure the output was the same answer as what I had calculated by hand. This was 6 (150lbs), 2 (50lbs) , 1 (30lbs), 1 (15lbs), 3 (1lbs)
Next I changed the value to numbers in the different ranges. This included 0, 2, 16, 31, 51, 151, 1050, 2048 to make sure it would output 0 for certain weight zones. 
The program works for all values above 0, but when I used a negative number (-1),it said I needed negative weights (which isn't possible). This is a limitation of the program.

b. This section tasked us with adding an option for the user to input a value. All I had to do was add a cin line and set the variable equal to the user input.

c. I tested the values I had put in by hand and they matched up, showing me that the math of the program was correct.
*/
#include <iostream>
using namespace std;

int main () {

    /*------Variable of the given weight-------*/
    int weight_given; //allocates this variable for input weight


    /*------Input and welcome----*/
    cout << "Welcome, user!" << endl; //opening welcome
    cout << "What is your weight \n"; //asking the question
    cin >> weight_given; //this will store the value they input


    /*------Calculations for defining other variables------------*/
    int weights150 = weight_given / 150; //I am creating a variable for the 150 zone, because that is the biggest possible weight
    int remainder = weight_given % 150; // I am setting the remainder equal to whatever is left over, so we can use smaller weight zones after
    									//This was done using the % modulo

    int weights50 = remainder / 50;
    remainder = remainder - (weights50 * 50);

    int weights30 = remainder / 30;
    remainder = remainder - (weights30 * 30);

    int weights15 = remainder / 15;
    remainder = remainder - (weights15 * 15);

    int weights1 = remainder / 1;
    remainder = weights1 - (weights1 * 1);


    /*------Output------------*/
    cout << "You'll need " << weights150 << " 150lbs weights " << weights50 << " 50lbs weights " << weights30 << " 30lbs weights " << weights15 << " 15lbs weights and " << weights1 << " 1lbs weights " << endl;
    

    return 0;

}//end int main()



