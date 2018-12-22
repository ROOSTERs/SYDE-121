#ifndef DOLLARS_AND_CENTS // compiler directive that ensures that
#define DOLLARS_AND_CENTS // this file is compiled only once

// PURPOSE: Models CDN and USD currency
class DollarsAndCents { 
	// private attributes
	// dollars stores the dollar amount
	// cents stores the cents amount
    int dollars, cents; 

public: // start of public methods; only method signatures here
	// constructors
	// PURPOSE: Defaulty/empty constructor for DollarsAndCents
    DollarsAndCents();
	// PURPOSE: Parametric constructor for DollarsAndCents
	DollarsAndCents(int new_dollars, int new_cents);

	// service functions	
	// PURPOSE: Increments the current value of DollarsAndCents object
	//     INPUTS: add_dollars, add_cents - the values by which the object
	//             should be incremented
	//     RETURNS: nothing
	void increment_value(int add_dollars, int add_cents);
	// PURPOSE: Increments the current value of DollarsAndCents object
	//     INPUTS: add_value - the value by which the object should be incremented
	//     RETURNS: nothing
	void increment_value(DollarsAndCents add_value);
	// PURPOSE: Decrements the current value of DollarsAndCents object
	//     INPUTS: sub_dollars, sub_cents - the values by which the object
	//             should be decremented
	//     RETURNS: nothing
	void decrement_value(int sub_dollars, int sub_cents);
	// PURPOSE: Decrements the current value of DollarsAndCents object
	//     INPUTS: sub_value - the value by which the object should be decremented
	//     RETURNS: nothing
	void decrement_value(DollarsAndCents sub_value);
	// PURPOSE: Outputs the current value of DollarsAndCents object
	void output_value();
};

#endif // must include this to complete the compiler directive
