#include "dollars_and_cents.hpp" // must include the class declaration

int main() { // could be separated into one file (e.g., main.cpp)
             // in that case, create a project and include .cpp files
	DollarsAndCents dc1(4, 50);
	DollarsAndCents dc2(dc1); // copy constructor
	dc1.output_value();
	dc2.output_value();
	
	return 0;
}
