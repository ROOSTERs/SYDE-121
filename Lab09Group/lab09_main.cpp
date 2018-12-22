//*************************************************************
// Student Name: Arden White
// Student Number: 20786948
// Student Name: Surin Rao
// Student Number: 20760312
//
// SYDE 121 Lab: 08 Assignment: Exercise 1
// Filename: lab09_main.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution had
// not been plagiarized from other sources and has not knowingly
// plagiarized by others.
//
// Project: Let's Be Healthy and Make a Box of Fruits and Veggies
// Purpose: To use a Produce .hpp file, Box .hpp file and also their .cpp files to make a box of fruits
// and veggies.
// Due Date: Thursday, November 29, 2018
//***************************************************************
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <ctime>
#include "lab09_box.hpp"
#include "lab09_produce.hpp"

using namespace std;

void test_fill_the_box() {
    FruitsAndVeggiesBox box1(5); // smallest size of box

    box1.fill_the_box(11); // month of November (winter and fall seasons)
    box1.print();

    FruitsAndVeggiesBox box2(10); // medium size of box
    box2.fill_the_box(6); // month of June (spring and summer seasons)
    box2.print();

    FruitsAndVeggiesBox box3(15); // largest size of box
    box3.fill_the_box(3); // month of March (winter and spring seasons)
    box3.print();   
}

void test_produce() {
	Produce chickpeas; // default constructor for Produce class
	Produce watermelon (watermelon, 9200, 25, 12, 2018); // parametric constructor for Produce class
	chickpeas.print(); // Produce print member function for default
	watermelon.print(); // Produce print member function for parametric
}

void run() {
	test_fill_the_box(); // visually test that the correct answers print out when testing FruitsAndVeggiesBox class
	test_produce(); // visually test that the correct answers print out when testing Produce class
}

int main () {
	run();
	return 0;
}
