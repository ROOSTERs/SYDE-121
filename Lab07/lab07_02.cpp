/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 14th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab07
Exercise: 02
File name: lab07_02.cpp
Project: Lab07
Purpose: I love C++

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline:
1. Create functions for check_if_contains (using lab specs signature) and another for character match
2. Make sure to include recursion
3. Include minimal code in main
4. After, add a user input option for the sentences and substrings they wish to test

I tested used a base sentence (I love c++) for when I first starting testing it. I then switched the substring everytime to words that were in the sentence, partially in and not at
all in to make sure it would correctly say true or false. I then tested to see if it would reply true/false if the word case was changed (upper vs lower). Since
HELLO is different than hello, it should return false, which it did. I then wrote some other sentences (longer and shorter) and tested other substrings to make sure it would
correctly output true or false, which it did.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*---------------Function Declaration--------------------*/
bool run_simulation();
bool check_if_contains(vector <char> target, vector <char> substr, unsigned long int main_size, unsigned long int sub_size, int index_one, int index_two);
bool char_match(vector <char> target, vector <char> substr, unsigned long int sub_size, int index_one, int index_two);

/*-------------Main-------------*/
int main() {
    run_simulation();
    return 0;
}//main

/*----------------Check_if_contains--------------*/
//Checking the main string (target) for substring's first letter
bool check_if_contains(vector <char> target, vector <char> substr, unsigned long int main_size, unsigned long int sub_size, int index_one, int index_two) {
    if (target[index_two] == target[main_size - 1]) {
        return false;
    }//if goes through vector and no first letter that matches
    else if (main_size < sub_size) {
        return false;
    }//else if the main size is less than substring
    else if (main_size == 0) {
        return true;
    }//else if the main_size = 0
    else if (sub_size == 0) {
        return false;
    }//else if the substring size is 0
    else if (substr[index_one] == target[index_two]) {
        return char_match(target, substr, sub_size, index_one, index_two);
        //Calls the char_match function to check if the match continues throughout the entire subtring and the main target
    }//else if the substring's first letter matches any of the ones in the main target
    else {
        return check_if_contains(target, substr, main_size, sub_size, index_one, index_two + 1);
    }//else: checks the first letter of the substring with the next character in main
}//check_if_contains

/*-------------Character_match------------------*/
//Checking the main string (target) for more matches
bool char_match(vector <char> target, vector <char> substr, unsigned long int sub_size, int index_one, int index_two) {
    if (substr[index_one] == substr[sub_size - 1]) {
        return true;
    }//if gets to the last element (size-1) in the vector, will return true because match complete
    else if (substr[index_one] == target[index_two]) {
        return char_match(target, substr, sub_size, index_one + 1, index_two + 1); //recursion here to check the next char in each of the vectors
    }//else if checks if the substring's next char matches the main string's next char
    else {
        return false;
    }//else it will be false
}//char_match

/*---------------Run simulation-------------------*/
bool run_simulation() {
    //Variable Declaration
    vector <char> target;
    vector <char> substr;
    char main_string;
    char substring;
    int index_one = 0; //Index Variables
    int index_two = 0;

    cout << "Please enter the main string (target). Write dash (-) when you are complete. "; //use - when complete, write - so it can move on
    while (main_string != '-') {
        cin >> main_string; //main string/sentence that is going to be used
        target.push_back(main_string); //pushing into main_string vector
    }//while loop going while main string doesn't equal the dash -

    cout << "Please enter the substring (substr). Write dash (-) when you are complete. ";
    while (substring != '-') { //end when there is no -
        cin >> substring; //substring that is going to be checked
        substr.push_back(substring); //pushing into vector substring
    }//while

    target.pop_back(); //removes the last element in the vector, effectively reducing the container size by one
    substr.pop_back();

    unsigned long int main_size = target.size(); //taking vector sizes
    unsigned long int sub_size = substr.size();

    // calling the checking functions to see if the substring matches the target anywhere
    if (check_if_contains(target, substr, main_size, sub_size, index_one, index_two)) {
        cout << "True! The string is a substring in the target string!" << endl;
    }//if there is a match
    else {
        cout << "False! The string is not a substring in the target string1" << endl;
    }//else no match
    return true;
}//run_simulation

