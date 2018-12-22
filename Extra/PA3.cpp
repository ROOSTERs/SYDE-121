
/*
PA #3 Nov 5, Surin Rao
*/
#include <iostream>

using namespace std; 

void reverse_digits(int value);
//PURPOSE: Reverses and prints the digits of the inputted value
//INPUTS: value - the input that needs to be reversed
//OUTPUTS: nothing

void space_digits(int value);
//PURPOSE: the digits of the inputted value are one per line 
//INPUTS: value - the value that needs to be printed
//OUTPUTS: nothing

string dec2bin(int value);
//PURPOSE: convert the given decimal value into binary representation 
//INPUTS: value - the value that needs to be convereted
//OUTPUTS: returns the corresponding binary string

int main() {
	space_digits(4);
	reverse_digits(143);
	cout << endl;
	cout << dec2bin(256) <<endl;

}//main

string dec2bin(int value) {
	if (value == 0) {
		return "0";
	}
	else if (value == 1) {
		return "1";
	}
	else {
		return dec2bin(value / 2) + dec2bin(value % 2);
	}
}

void space_digits(int value) {
	if (value < 10) {
		cout << value << endl;
	}
	else {
		space_digits(value / 10);
		cout << value % 10 << endl;
	}
}

void reverse_digits(int value) {

	if (value < 0) {
		cout << "_" ;
		reverse_digits(-1 * value); //could also write -value 
	}
	else if (value < 10) {
		cout << value; 
	}
	else {
		cout << (value % 10);
		reverse_digits(value / 10);
	}
} 