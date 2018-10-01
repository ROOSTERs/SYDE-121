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
1. Have an condition making sure the user inputs a number greater than 0 (and account for 1)
2. Create required variables (boolean or counter for checking prime numbers and variables to check if palindrome)
3. Test the user input by dividing it, starting with 2 and going up to the number - 1 checking the remainder
4. If the remainder is 0 it means it is not a prime number
5. With those who passed this test, to check if it is odd, take the variables of each digit, add them together, and make sure the remainder is not 0
6. For checking if it is a palindrome check to see if each end digit (going from both sides) is equal. Also account for how many digits are in the number
7. Create the cases since it can be an odd sum, palindrome, and/or prime

*/

#include <iostream>
using namespace std;

int main() {

/*-------------------------------------- Variable declaration -------------------------------------------*/
int user_number;
int ten_thousands_place;
int thousands_place;
int hundreds_place;
int tens_place;
int ones_place;

/*-----------------------------------------------User input------------------------------------------------*/
cout << "Enter a number greater than 0: " <<endl;
cin >> user_number;

/*-------------------------------------------------Main Testing---------------------------------------------*/
if (user_number > 1) {
	for (int i = 2; i <= user_number; i++) { //setting i to 2 because it is the first number we check, then go up
    	bool is_prime = true; //setting the boolean to true and will hvae it change if it fails conditions

    	//this part will only execute if j < whatever i is at, so for 0, 1, and 2 it will not,
    	//meaning the expression stay true keeping it as a prime number
    	for (int j = 2; j < i; j++) {
    		if (i % j == 0) { //if whatever i is can be divided by j values (from 2 to the number - 1) then it won't be prime
    			is_prime = false;
    		}//if statement checking if j goes into i
    	}//j and i for loop

    //if it is prime, now we need to check for other conditions listed by the problem
    if (is_prime) {

        /*-------------------------------------From 10000 to 99999--------------------------------------------*/
    	if (i >= 10000 && i < 100000) {
            ten_thousands_place = i / 10000; //this will give the tens_placethousdan digit
            thousands_place = (i % 10000) / 1000; //whatever the remainder is, the thousands_placewill be it divided by 1000,
            hundreds_place = ((i % 10000) % 1000) / 100;
            tens_place = (((i % 10000) % 1000) % 100) / 10;
            ones_place = ((((i % 10000) % 1000) % 100) % 10);

            if ((ten_thousands_place + thousands_place + hundreds_place + tens_place + ones_place) % 2 == 0) { //if the sum is divisible by (no remainder), then it is even
                cout << i << " is just a prime number" << endl;
            }//testing if it will be a prime number and the sum is odd
            else {
                cout << i << " is a prime number and the digit sum is also odd!" << endl;
            }//else it is just a prime number
        }//testing for 100 000 - 10 000 ranges

        /*--------------------------------------------From 1000 to 9999--------------------------------------*/
		else if (i >= 1000 && i < 10000) {
            thousands_place = i / 1000;
            hundreds_place = (i % 1000) / 100;
            tens_place = ((i % 1000) % 100) / 10;
            ones_place = ((i % 1000) % 100) % 10;

            //now we want to see if the sum is odd by checking if the sum is divisible by 2 and if it is a pallindrome
            //a pallindrome is a number that is the same forwards and backwards (101, 4554)
            //so we need to check the ones_place digit with the thousand, and the tens_placewith the hundreds_place
            if ((thousands_place + hundreds_place + tens_place + ones_place) % 2 != 0 && thousands_place== ones_place && hundreds_place == tens_place) {
                cout << i << " is a prime number, the digit sum is odd, and it is also a palindrome." << endl;
            }
            //if it's not both, this will see if it is just a pallindrome
            else if (thousands_place == ones_place && hundreds_place == tens_place) {
                cout << i << " is a prime number and it is also a palindrome." << endl;
            }
            //this will just see if it is odd
            else if ((thousands_place + hundreds_place + tens_place + ones_place) % 2 != 0) {
                cout << i << " is a prime number and digit sum is also odd." << endl;
            }
            //otherwise it is just a prime number
            else {
                cout << i << " is just a prime number!" << endl;
            }//else if
        }//from 1000 - 9999

        /*----------------------------------------------From 100 to 999------------------------------------------*/
        else if (i >= 100 && i < 1000) {
            hundreds_place = i / 100;
            tens_place= (i % 100) / 10;
            ones_place = (i % 100) % 10;

            if ((hundreds_place + tens_place + ones_place) % 2 != 0 && hundreds_place == ones_place) {
                cout << i << " is a prime number, the digit sum is odd, and it is also a palindrome." << endl;
            }
            else if (hundreds_place == ones_place) {
                cout << i << " is a prime number and it is also a palindrome." << endl;
            }
            else if ((hundreds_place + tens_place + ones_place) % 2 != 0){
                cout << i << " is a prime number and digit sum is also odd." << endl;
            }
            else {
                cout << i << " is just a prime number!" << endl;
            }
        }// from 100 - 999

        /*----------------------------------------------From 10 to 99-----------------------------------------*/
        else if (i >= 10 && i < 100) {
            tens_place = i / 10;
            ones_place = i % 10;

            if ((tens_place + ones_place) % 2 != 0 && tens_place == ones_place) {
                cout << i << " is a prime number, the digit sum is odd, and it is also a palindrome." << endl;
            }
            else if (tens_place == ones_place) {
                cout << i << " is a prime number and it is also a palindrome." << endl;
            }
            else if ((tens_place + ones_place) % 2 != 0) {
                cout << i << " is a prime number and digit sum is also odd." << endl;
            }
            else {
                cout << i << " is just a prime number!" << endl;
            }
        }//from 10 - 99

        /*---------------------------------------------------From 2 to 9--------------------------------------*/
        else if (i <= 9 && i >= 2) { //between 9 - 2, so can't be a palindrome because only 1 digit
            cout << i << " is a prime nummber!" << endl;
        }// 9 - 2
    }//if is_prime is true
    }//for loop i, runs through all this before increasing i
}//if user_number > 0

/*----------------------------------------------------------Exceptions-------------------------------------------*/
//added this in case they enter 1, since it is technically not a prime number
else if (user_number == 1) {
	cout << "1 is not a prime number, but it is a special number." << endl;
}
else {
	cout << "Enter a number that is greater than zero" << endl;
}//else, they entered a number that is not above 0


return 0;
}//end main

