/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 22nd 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab08
Exercise: 01
File name: lab08_book.hpp
Project: Lab08
Purpose: Books are Awesome

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.
*/
#ifndef SYDE121_LAB08_BOOK
#define SYDE121_LAB08_BOOK

#include <iostream>
using namespace std;

// PURPOSE: Models information about a book
class Book {
	// corresponding information for a Book instance
	string title, authors, date_of_publication;
	
public:
	// PURPOSE: default/empty constructor
	Book();		

	// PURPOSE: parametric constructor that takes
	//          one string as parameter value
	Book(string new_title);	

	// PURPOSE: parametric constructor that takes
	//          two strings as parameter values
	Book(string new_title, 
	     string new_authors);
		
	// PURPOSE: parametric constructor that takes
	//          three strings as parameter values
	Book(string new_title, 
	     string new_authors, 
	     string new_dop);
	     
	// PURPOSE: getters for individual attribute values
	string get_title();
	string get_authors();
	string get_dop();

	// PURPOSE: prints out the contents of the book objects
	void print();	
};
#endif
