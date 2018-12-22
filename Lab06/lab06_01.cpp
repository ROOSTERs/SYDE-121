/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 8th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab06
Exercise: 01
File name: lab06_01.cpp
Project: Lab06
Purpose: SVG

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline:
A
1. Create axis using 2 lines, remembering that 0,0 is in the top left corner
2. Making sure the graph is < 400, create rectangles starting at 400 - input value, since it draws down/left
3. Space the bars by setting the x coordinate slightly different each time 
4. When making functions, use one for input and one for output 
B
1. Practice using w3 schools to get familiar 
2. Create a logo function and mimic the output from part A (creating new variables etc)

A
I tested different lengths for the axis lines to try to find a good size, while still being < 400. I then tested the bar graph by chaning the values 
in the input.txt to make sure they would cout the new values and the bars would be adjusted. I added a new person since the lab said 5 people, and my
code ran with the extra person and showed a correct bar graph for their number too. I then reduced some values (ex 40 --> 20) to see if the bar graph size would
change, which it did, showing me my code works. 

B
I implemented my code and created new variables for my logo. I then tested to make sure my format was the same as from Part A, since they are both 
drawing objects. When I confirmed it was I ran it and my logo appeared correctly as I had pictured it (it isn't as complex as others, but it meets the necessary
criteria of the lab). I then changed a couple of values from different lines to see the effect it would have on my logo, and when I witnessed some lines shifting,
I new the chances were being implemented. 
*/

#include <iostream>
#include <fstream>
using namespace std;

/*--------------------------------Function prototyping--------------------*/
void input (int values[5]);
void output(int values[5]);
void logo();


/*-----------------------------------MAIN-----------------------------*/
int main() {
	//declaration and calling functions  
    int values[5];
	input(values);
	output(values);
	logo();

	cout << "<?xml version=\"1.0\"?>\n";
	cout << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
	cout << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	cout << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";
	cout << "<rect x=\"40\" y=\"40\" width=\"70\" height=\"250\" style=\"fill:blue;\"/>\n";
	cout << "<rect x=\"75\" y=\"100\" width=\"150\" height=\"50\" style=\"fill:rgb(0,255,0);\"/>\n";
	cout << "<line x1=\"0\" y1=\"0\" x2=\"300\" y2=\"300\" style=\"stroke:purple;stroke-width:2\"/>\n";
	cout << "</svg>\n";

return 0;
}//main

/*---------------------------------------INPUT-------------------------------------*/
void input (int values[5]) {

	// Variable initialize 
	string cur_pair, names[5];
	//IPO
	// Input: Handles file inputs
	ifstream my_ifstream; // create ifstream instance
	my_ifstream.open("input.txt"); // opening the input file

	//Processing: extract and print individual values
	for (int index = 0; index < 5; ++index) { // read (key,value) pairs
		getline(my_ifstream, cur_pair); // go through and read it one line at time
		// separate into tokens; skip comma and space
		names[index] = cur_pair.substr(0, cur_pair.find(',', 0));
		values[index] = atoi(cur_pair.substr(cur_pair.find(',', 0) + 2).c_str());
	}//for 
	// Values are outputted to the console
	for (int index = 0; index < 5; ++index) {
		cout << "Name: " << names[index] << "\t"
			 << "Value: " << values[index] << endl; //what is shown when cout, with the people's names and #s
	}//for names and values 

	// Output: close the file
	my_ifstream.close(); // close the output file
}//input 

/*-----------------------------------------OUTPUT-----------------------------*/
void output(int values[5]) {

    ofstream my_ofstream; // create ofstream instance
	my_ofstream.open("graph.svg"); // open the output file which is called graph.svg

	if(!my_ofstream.fail()) { // check for failure using .fail 
		my_ofstream << "<?xml version=\"1.0\"?>\n"; // output svg content to a specific file
		my_ofstream << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
		my_ofstream << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
		my_ofstream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"400\" height=\"400\">\n"; //400 because of requirements 

		//bars, each index is a person with their associated value 
		my_ofstream << "<rect x=\"25\" y=\"" << 300 - values[0] << "\" width=\"25\" height=\"" << values[0]<< "\" style=\"fill:rgb(0,255,0);\"/>\n"; //RGB = (R, G, B)
		my_ofstream << "<rect x=\"75\" y=\"" << 300 - values[1] << "\" width=\"25\" height=\"" << values[1]<< "\" style=\"fill:rgb(255,0,0);\"/>\n";
		my_ofstream << "<rect x=\"125\" y=\"" << 300 - values[2] << "\" width=\"25\" height=\"" << values[2]<< "\" style=\"fill:rgb(0,0,255);\"/>\n";
		my_ofstream << "<rect x=\"175\" y=\"" << 300 - values[3] << "\" width=\"25\" height=\"" << values[3]<< "\" style=\"fill:rgb(255,0,255);\"/>\n";
		my_ofstream << "<rect x=\"225\" y=\"" << 300 - values[4] << "\" width=\"25\" height=\"" << values[4]<< "\" style=\"fill:rgb(0,127,127);\"/>\n";

		//axis lines 
		my_ofstream << "<line x1=\"10\" y1=\"25\" x2=\"10\" y2=\"300\" style=\"stroke:black;stroke-width:2\"/>\n"; 
		my_ofstream << "<line x1=\"10\" y1=\"300\" x2=\"275\" y2=\"300\" style=\"stroke:black;stroke-width:2\"/>\n";
		my_ofstream << "</svg>\n";
		my_ofstream.close(); // close the output file
	}//if 
}//output
/*----------------------------------LOGO FUNCTION-----------------------------------*/
void logo() {

	ofstream my_logo; // create ofstream instance for my_logo
	my_logo.open("syde_logo_surin.svg"); // opening the output file
	my_logo << "<svg width=\"840\" height=\"585\" viewBox=\"0 0 840 585\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\">\n";
	my_logo << "<path d=\"M176 34L251 175L200 276L213 284L357 43L337 34L268 166L195 28L176 34Z\" stroke=\"#FF0303\"/>\n";
	my_logo << "<path d=\"M840 316.994H705V189.25M705 189.25V61.5066H840M705 189.25V170M11 400.761C132.6 403.274 79 523.967 37 584H136M457 28C621 38.052 654.667 145.971 651 198.674C582.2 296.681 493 318.39 457 316.994V28ZM264 422.75C198 513.846 200 584 264 584C328 584 344 511.751 340 486.621C336.8 466.518 288 435.664 264 422.75Z\" stroke=\"#1400FF\"/>\n";
	my_logo << "<path d=\"M468 295.006V42.6591C511.333 61.5066 601.2 104.227 614 124.331C630 149.461 632 191.345 626 203.91C620 216.475 468 296.053 468 295.006Z\" stroke=\"#05FF00\"/>\n";
	my_logo << "<path d=\"M839 61V84H722V170H839V188H722V297H839V316\" stroke=\"#A54F01\"/>\n";
	my_logo << "<path d=\"M59 65V118L87 142.5M28 142.5L1 167V237L59 284L115 237V167L87 142.5M28 142.5L59 182V227M28 142.5L1 118V46L59 1L115 39V118L87 142.5\" stroke=\"#F705FC\"/>\n";
	my_logo << "<path d=\"M465 425C540 427 558 442 565 474C570.6 499.6 500.667 557.333 465 583H585M691 435C716 432 766.8 427.8 770 435C774 444 862 467 803 474C755.8 479.6 734.667 481 730 481C732 482.333 745 486.2 781 491C817 495.8 830.667 532.333 833 550L720 566\" stroke=\"#2AA19A\"/>\n";
	my_logo << "<path d=\"M279 457L290.45 493.277H327.504L297.527 515.697L308.977 551.973L279 529.553L249.023 551.973L260.473 515.697L230.496 493.277H267.55L279 457Z\" fill=\"#8D9010\"/>\n";
	my_logo << "</svg>\n"; //code for my logo
	my_logo.close(); //making sure to close it after 
}//logo
