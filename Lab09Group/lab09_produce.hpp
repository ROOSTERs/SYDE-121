//*************************************************************
// Student Name: Arden White
// Student Number: 20786948
// Student Name: Surin Rao
// Student Number: 20760312
//
// SYDE 121 Lab: 08 Assignment: Exercise 1
// Filename: lab09_produce.hpp
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
#ifndef LAB_09_PRODUCE_HPP
#define LAB_09_PRODUCE_HPP
#include <iostream>
using namespace std;

// PURPOSE: Models a generic Produce item
class Produce {
	// PURPOSE: Models Date data type; helper struct
	struct Date {
		int day, month, year;
		// inlined constructor for private data type
		Date(int new_day, int new_month, int new_year) : 
		     day(new_day), month(new_month), year(new_year) {}
	};
	// private attributes
	string item_name;
	double item_weight;
	Date item_expiry;
public:
	// PURPOSE: Default/empty constructor
	Produce();
	// PURPOSE: Parametric constructor
	Produce(string new_iname, double new_iweight, int new_eday, 
			int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current Produce value
	void print();
	// PURPOSE: Overloaded operator== for the Produce object
	bool operator==(Produce& target) const;
};

// PURPOSE: Models a WinterProduce item
class WinterProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	WinterProduce();
	// PURPOSE: Parametric constructor
	WinterProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current WinterProduce values
	void print();
	// PURPOSE: Overloaded operator== for the WinterProduce object
	bool operator==(WinterProduce& target) const;
};

// PURPOSE: Models a SpringProduce item
class SpringProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	SpringProduce();
	// PURPOSE: Parametric constructor
	SpringProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current SpringProduce value
	void print();
	// PURPOSE: Overloaded operator== for the SpringProduce object
	bool operator==(SpringProduce& target) const;
};

// PURPOSE: Models a SummerProduce item
class SummerProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	SummerProduce();
	// PURPOSE: Parametric constructor
	SummerProduce(string new_iname, double new_iweight, int new_eday, 
			      int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current SummerProduce value
	void print();
	// PURPOSE: Overloaded operator== for the SummerProduce object
	bool operator==(SummerProduce& target) const;
};

// PURPOSE: Models a FallProduce item
class FallProduce : Produce { 
public:
	// PURPOSE: Default/empty constructor
	FallProduce();
	// PURPOSE: Parametric constructor
	FallProduce(string new_iname, double new_iweight, int new_eday, 
			    int new_emonth, int new_eyear);
	// PURPOSE: Prints out the current FallProduce value
	void print();
	// PURPOSE: Overloaded operator== for the FallProduce object
	bool operator==(FallProduce& target) const;
};
#endif
