//*************************************************************
// Student Name: Arden White
// Student Number: 20786948
// Student Name: Surin Rao
// Student Number: 20760312
//
// SYDE 121 Lab: 08 Assignment: Exercise 1
// Filename: lab09_box_sample.cpp
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

// constants that define the files with produce names
const string FruitsAndVeggiesBox::WINTER_FILE = "winter.txt";
const string FruitsAndVeggiesBox::SPRING_FILE = "spring.txt";
const string FruitsAndVeggiesBox::SUMMER_FILE = "summer.txt";
const string FruitsAndVeggiesBox::FALL_FILE = "fall.txt";

// constants that define the generation parameters for produce attributes
const int FruitsAndVeggiesBox::MAX_WEIGHT = 100 /* in grams */, FruitsAndVeggiesBox::MAX_DAY = 31 /* not checking for Feb 31st */;
const int FruitsAndVeggiesBox::MAX_MONTH = 12, FruitsAndVeggiesBox::MAX_YEAR_DIFF = 2 /* 2019 and 2020 as valid */;
const int FruitsAndVeggiesBox::NEXT_YEAR = 2019;

FruitsAndVeggiesBox::FruitsAndVeggiesBox() : order_size(0) {}

FruitsAndVeggiesBox::FruitsAndVeggiesBox(int new_order_size) : 
	order_size(new_order_size) {}

void FruitsAndVeggiesBox::print() {
	// TODO: complete method definition here
		
	// print each vector separately by invoking class-specific print()
	for (int i = 0; i < winter_produce.size(); i++) {
		winter_produce[i].print();	
	}
	for (int i = 0; i < spring_produce.size(); i++) {
		spring_produce[i].print();	
	}
	for (int i = 0; i < summer_produce.size(); i++) {
		summer_produce[i].print();	
	}
	for (int i = 0; i < fall_produce.size(); i++) {
		fall_produce[i].print();	
	}
}

int FruitsAndVeggiesBox::size() {
	int cur_size = 0;

	// TODO: complete method definition here
	
	// add the number of items already inserted
	
	cur_size = (winter_produce.size()) + (spring_produce.size()) + (summer_produce.size()) + (fall_produce.size());
	
	return cur_size;
}

void FruitsAndVeggiesBox::empty_the_box() {
	// TODO: complete method definition here
	
	// empty the box if some items already inserted
	
	winter_produce.clear();
	spring_produce.clear();
	summer_produce.clear();
	fall_produce.clear();
}

void FruitsAndVeggiesBox::file_to_vector(vector<string>& return_vector, string file_name) {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	ifstream file_conversion;
	// step1. open the corresponding file	
	file_conversion.open(file_name.c_str());
	// step2. load the values from the file
	if (!file_conversion.fail()) {
		while (!(file_conversion.eof())) {
			string place_holder;
			getline(file_conversion, place_holder);
			if (place_holder.length() > 0)
				return_vector.push_back(place_holder);
		}		
	}
	// step3. close the file
	file_conversion.close();
}


void FruitsAndVeggiesBox::load_up_produce_names() {
	// TODO: complete method definition here
	
	// load up the four files one at a time
	file_to_vector(winter_produce_names, WINTER_FILE);
	file_to_vector(spring_produce_names, SPRING_FILE);
	file_to_vector(summer_produce_names, SUMMER_FILE);
	file_to_vector(fall_produce_names, FALL_FILE);	
	
	// Check what names were loaded
	print_loaded_names();  
}

void FruitsAndVeggiesBox::print_loaded_names() {
	// TODO: complete method definition here
	
	// print each vector separately by listing each group of names separately
	cout << "Current fruits and veggies in the box: " << endl;	
	
	for (int i = 0; i < winter_produce_names.size(); i++) {
		cout << winter_produce_names[i] << endl;
	}
	for (int i = 0; i < spring_produce_names.size(); i++) {
		cout << spring_produce_names[i] << endl;
	}
	for (int i = 0; i < summer_produce_names.size(); i++) {
		cout << summer_produce_names[i] << endl;
	}
	for (int i = 0; i < fall_produce_names.size(); i++) {
		cout << fall_produce_names[i] << endl;
	}
}

void FruitsAndVeggiesBox::assign_seasons(int current_month) {
	// remove previously set seasons
	produce_seasons.clear(); 
	// insert corresponding seasons based on specified rules
	switch (current_month) {
		case JAN:
			produce_seasons.push_back(WINTER);
			break;
		case FEB:
			produce_seasons.push_back(WINTER);
			produce_seasons.push_back(SPRING);
			break;
		case MAR:
			produce_seasons.push_back(WINTER);
			produce_seasons.push_back(SPRING);
			break;
		case APR:
			produce_seasons.push_back(SPRING);
			break;
		case MAY:
			produce_seasons.push_back(SPRING);
			produce_seasons.push_back(SUMMER);
			break;
		case JUN:
			produce_seasons.push_back(SPRING);
			produce_seasons.push_back(SUMMER);
			break;
		case JUL:
			produce_seasons.push_back(SUMMER);
			break;
		case AUG:
			produce_seasons.push_back(SUMMER);
			produce_seasons.push_back(FALL);
			break;
		case SEP:
			produce_seasons.push_back(SUMMER);
			produce_seasons.push_back(FALL);
			break;
		case OCT:
			produce_seasons.push_back(FALL);
			break;
		case NOV:
			produce_seasons.push_back(FALL);
			produce_seasons.push_back(WINTER);
			break;
		case DEC:
			produce_seasons.push_back(FALL);
			produce_seasons.push_back(WINTER);
			break;
	}
}

void FruitsAndVeggiesBox::generate_random_value(int vector_size) {
	// generate random values for the current produce item
	rand_item = rand() % vector_size; // random item name
	rand_weight = rand() % MAX_WEIGHT + 1; rand_day = rand() % MAX_DAY + 1;
	rand_month = rand() % MAX_MONTH + 1; rand_year = rand() % MAX_YEAR_DIFF + NEXT_YEAR;
}

void FruitsAndVeggiesBox::handle_winter_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	int vector_size = winter_produce_names.size();
	bool is_unique = true;
	// step1. keep repeating this until a unique item is generated
	do{
		// step1.1. generate random values for the winter produce item
		generate_random_value(vector_size);
		// step1.2. create a new WinterProduce instance with the matching values
		WinterProduce new_object = WinterProduce(rand_item, rand_weight, rand_day, rand_month, rand_year);
		// step1.3. iterate through the winter produce vector to check if the item is unique
		for (int index = 0; index < winter_produce.size(); index++) {
			is_unique = !(winter_produce[i] == new_object);
		}	
	// step2. once a unique item is generated, store it into the vector
	} while (!is_unique);
	winter_produce.push_back(new_object);
}

void FruitsAndVeggiesBox::handle_spring_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	int vector_size = spring_produce_names.size();
	bool is_unique = true;
	// step1. keep repeating this until a unique item is generated
	do{
		// step1.1. generate random values for the winter produce item
		generate_random_value(vector_size);
		// step1.2. create a new WinterProduce instance with the matching values
		SpringProduce new_object = SpringProduce(rand_item, rand_weight, rand_day, rand_month, rand_year);
		// step1.3. iterate through the winter produce vector to check if the item is unique
		for (int index = 0; index < spring_produce.size(); index++) {
			is_unique = !(spring_produce[i] == new_object);
		}	
	// step2. once a unique item is generated, store it into the vector
	} while (!is_unique);
	spring_produce.push_back(new_object);
}

void FruitsAndVeggiesBox::handle_summer_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	int vector_size = summer_produce_names.size();
	bool is_unique = true;
	// step1. keep repeating this until a unique item is generated
	do{
		// step1.1. generate random values for the winter produce item
		generate_random_value(vector_size);
		// step1.2. create a new WinterProduce instance with the matching values
		SummerProduce new_object = SummerProduce(rand_item, rand_weight, rand_day, rand_month, rand_year);
		// step1.3. iterate through the winter produce vector to check if the item is unique
		for (int index = 0; index < summer_produce.size(); index++) {
			is_unique = !(summer_produce[i] == new_object);
		}	
	// step2. once a unique item is generated, store it into the vector
	} while (!is_unique);
	summer_produce.push_back(new_object);
}

void FruitsAndVeggiesBox::handle_fall_item() {
	// TODO: complete method definition here
	
	// step0. initialize corresponding variables
	int vector_size = fall_produce_names.size();
	bool is_unique = true;
	// step1. keep repeating this until a unique item is generated
	do{
		// step1.1. generate random values for the winter produce item
		generate_random_value(vector_size);
		// step1.2. create a new WinterProduce instance with the matching values
		FallProduce new_object = FallProduce(rand_item, rand_weight, rand_day, rand_month, rand_year);
		// step1.3. iterate through the winter produce vector to check if the item is unique
		for (int index = 0; index < fall_produce.size(); index++) {
			is_unique = !(fall_produce[i] == new_object);
		}	
	// step2. once a unique item is generated, store it into the vector
	} while (!is_unique);
	fall_produce.push_back(new_object);
}

void FruitsAndVeggiesBox::insert_unique_item() {
	// TODO: complete method definition here
	
	// step1. randomly generate a unique produce item
	// step1.1. randomly select a season from available seasons
	rand_season = rand() % produce_seasons.size();
	// step1.2. insert a new unique item with random values into the box
	switch (produce_seasons[rand_season]) {
		case WINTER:
			// step1.3a. insert winter produce item
			handle_winter_item();
			break;			
			
		case SPRING:
			// step1.3b. insert spring produce item
			handle_spring_item();
			break;
			
		case SUMMER:
			// step1.3c. insert summer produce item
			handle_summer_item();
			break;
			
		case FALL:
			// step1.3d. insert fall produce item
			handle_fall_item();
			break;
	}
}

void FruitsAndVeggiesBox::fill_the_box(int current_month) {
	// TODO: complete method definition here
	
	// step0. set the randomization seed
	srand(time(0));
	// step1. remove all items if some already inserted
	empty_the_box();
	// step2. load up produce names
	load_up_produce_names();
	// step3. decide which seasons are current
	assign_seasons(int current_month);
	// step4. insert matching unique items based on the current seasons
	for (int m = 0; m < order_size; m++){
		insert_unique_item();
	}
}
