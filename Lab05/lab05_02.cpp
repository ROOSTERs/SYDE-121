/*
Student Name: Surin Rao
Student Number: 20760312
Date: October 21st 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab05
Exercise: 02
File name: lab05_02.cpp
Project: Lab05
Purpose: Array math

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline:
1. Create a base array which limits to,ax length 20
2. Get the equations for how to calculate the required values
3. Output all necessary info
4. Practice using a replace function
5. Ask the user to select the index and the new value
6. Reprint everything

I tested the combos: 1, 2, 3, 4 / 44.56, 5.7, 666 | 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35. All of these outputted the expected values
(I did it on a calculator too). These all proved true showing that the program works and also worked for doubles as well as simpler ints.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/*-------------------Entering the values for the array-------------*/
int enter_value(const int& max_size, double inputs[]) {
    int array_length = 0;
    for (int i = 0; i < max_size; i++) {
        string input;
        cout << "Enter a double value to put into the array. To exit type d/done: ";
        cin >> input; //taking user input

        if (input == "d" || input == "done") {
            break;
        }//if
        else {
            inputs[i] = stod(input); //string to double
            array_length++;
        }//else
    }//for
    return array_length;
}//enter value

/*-------------------Printing array---------------------*/
void print_stats (const int& array_length, double inputs[]) {
    //Variable def
    double sum = 0;
    double min = inputs[0]; //stating with the first term as true then going through the array and checking each element
    double max = inputs[0];

    cout << "ARRAY THAT WAS CREATED: {";

    for (int i = 0; i < array_length; i++) {
        double value = inputs[i]; //value at that index, will need for the calculations
        cout << value << ","; //seperates the index_position of each index in the array

        //calculate max
        for (int j = 0 ; j < array_length; j++) {
            if (inputs[j] > max) {
                max = inputs[j];
            }//if
        }//for

        //min
        for (int k = 0 ; k < array_length; k++) {
            if (inputs[k] < min) {
                min = inputs[k];
            }//if
        }//for

        sum = sum + value; //calculates the sum
    }//big for loop created the array format

    cout << "}" << endl;

    //Mean
    double mean = (sum / array_length);

    // Standard Deviation
    double sum_of_squared_differences = 0;
    for (int i = 0; i < array_length; i++) {
        double value = inputs[i];
        double away_from_avg = (value - mean);
        double squared_away_from_avg = away_from_avg * away_from_avg;
        sum_of_squared_differences += squared_away_from_avg;
    }//for
    double standard_deviation = sqrt(sum_of_squared_differences / array_length); //calc for standard deviation
    //got formula from https://revisionmaths.com/gcse-maths-revision/statistics-handling-data/standard-deviation

    //Stats
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Mean: " << mean << endl;
    cout << "Population Standard Deviation: " << standard_deviation << endl;
}//output stats

/*-------------Entering the values for the array-------------*/
void new_values(double inputs[], int array_length) {
    int element;
    string index_position;

    cout << endl;

    while (true) {
        cout << "State the index you wish to replace. To eixt type q/quit:  ";
        cin >> index_position;

        if (index_position == "q" || index_position == "quit") {
            break;
        }//if
        else {
            element = stoi(index_position); //stoi is string to int
        }//else

        bool index_is_valid = (element < array_length && 0 <= element);
        if (index_is_valid) {
            double new_value;

            cout << "New: ";
            cin >> new_value;

            inputs[element] = new_value;
            print_stats(array_length, inputs);
        } //index valid

        else {
            cout << "Invalid. Please try again and enter a valid response." << endl;
        }//else
    }//while loop
}//new values

/*-------------Entering the values for the array-------------*/
int main() {
    //variables
    const int max_size = 21;
    double inputs[max_size] = {};
    int array_length = enter_value(max_size, inputs);
    print_stats(array_length, inputs);
    new_values(inputs, array_length);
    return 0;
}
