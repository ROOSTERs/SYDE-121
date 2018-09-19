/*
Student Name: Surin Rao
Student Number: 20760312
Date: September 19th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab02
Exercise: 02
File name: lab02_02.cpp
Project: Lab02
Purpose: Population Estimate

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
1. Create variables for population and currentyear
2. Use the equation Population = 6.0 e ^ [0.02 (Current Year - 2000)]
3. Output the estimate population based off of the information provided

a. I tested the program for the values 2018, 2025, 2050, 2100 and got output 8.6, 9.9, 16.3, 44.3 in billions which was correct. 
b. I tested more values above 2000 and compared to my calculator and they all matched up. However, when I went to years below 2000, as expected the values got smaller. However when I
input 0 as the year, the population value was really really small, which was obviously not true. So the further back you go in the past (including BC, ie negative years), the more likely it is that your answer is false.
It still works for years close to 2000, but the further back you go, the more unrealistic the output becomes.
Another limitation is that I had to type in the value for E as a variable, meaning it is fairly accurate, but not the exact value.

*/

#include <iostream>
#include <math.h> //adding math library to do more complex math expressions
using namespace std;

int main () {

    /*------Variables---------*/
    //important to make these variables doubles because they need to include decimals
    double population; //allocates this variable for the population size
    int currentyear; //allocates this variable for what the year is
    double E = 2.71828; //value for e, used UPPER_CASE notation because of SYDE 121 guidelines

    /*-----------Precision Settings--------*/
    cout.setf(ios::fixed); //set to fixed precision
    cout.setf(ios::showpoint); // always show point
    cout.precision(4); //4 digit decimal precision

    /*----------2018--------*/
    currentyear = 2018;
    population = 6.0 * pow(E, (0.02 * (currentyear - 2000))); //math expression which will calculate what the population will be
                                                              //power formula is pow(base,exponent) (used google)
    cout << "The population in " << currentyear << " is " << population << " billion people" << endl;

    /*----------2025--------*/
    currentyear = 2025;
    population = 6.0 * pow(E, (0.02 * (currentyear - 2000)));
    cout << "The population in " << currentyear << " is " << population << " billion people" << endl;

    /*----------2050--------*/
    currentyear = 2050;
    population = 6.0 * pow(E, (0.02 * (currentyear - 2000)));
    cout << "The population in " << currentyear << " is " << population << " billion people"  << endl;

    /*----------2100--------*/
    currentyear = 2100;
    population = 6.0 * pow(E, (0.02 * (currentyear - 2000)));
    cout << "The population in " << currentyear << " is " << population << " billion people" << endl;



    return 0;

}//end int main()





