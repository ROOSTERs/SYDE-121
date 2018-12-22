#include <iostream>
using namespace std;

// Canadian Dollars to Japenese Yen (JPY)
// Average conversion rate on Nov 16th 2018
const double CDN_TO_JPY = 85.9108;
const char YEN_SYMBOL = static_cast<char>(190);

// Canadian Dollars to New Zealand Dollars (NZD)
// Average conversion rate on Nov 16th 2018
const double CDN_TO_NZD = 1.1121;

// PURPOSE: Models a non-negative value in Canadian (CDN) dollars
class CurrencyAmountCDN {
	// private attributes
	// dollars stores the dollar amount
	// cents stores the cents amount
	int dollars, cents;

	// HELPER FUNCTIONS
	
	// PURPOSE: Increments the current value of CurrencyAmountCDN object
	//     INPUTS: add_dollars, add_cents - the values by which the object
	//             should be incremented
	//     RETURNS: nothing
	void increment(int add_dollars, int add_cents) {
		int new_cents_value = (dollars + add_dollars) * 100 + (cents + add_cents);
		if (new_cents_value <= 0) {
			dollars = 0, cents = 0;
		} else {
			dollars = new_cents_value / 100;
			cents = new_cents_value % 100;
		}		
	}

public:
	// CONSTRUCTORS
	// PURPOSE: Default/empty constructor for CurrencyAmountCDN
	CurrencyAmountCDN() : dollars(0), cents(0) {
	}
	
	// PURPOSE: Parametric constructor for CurrencyAmountCDN
	CurrencyAmountCDN(double value) {
		if (value <= 0) {
			dollars = 0, cents = 0;
	
		} else {
			dollars = value;
			cents = (value - dollars + 0.005) * 100; /* round up to next value */		
		}
	}

	// SERVICE FUNCTIONS	

	// PURPOSE: Increments the current value of CurrencyAmountCDN object
	//     INPUTS: add_value - the value by which the object should be incremented
	//     RETURNS: nothing	
	void add(CurrencyAmountCDN add_amount) {
		increment(add_amount.dollars, add_amount.cents);
	} 
	
	// PURPOSE: Decrements the current value of CurrencyAmountCDN object
	//     INPUTS: sub_value - the value by which the object should be decremented
	//     RETURNS: nothing	
	void sub(CurrencyAmountCDN sub_amount) {
		increment(-sub_amount.dollars, -sub_amount.cents);
	}
	
	// PURPOSE: Outputs the current value of CurrencyAmountCDN object			
	void print() {
		cout << "$" << dollars << ".";
		cout.fill('0'); cout.width(2); /* demonstrates how to use fill function */
		cout << cents << " CDN" << endl;
	}
	
	// PURPOSE: Outputs the current value in Japenese Yen (JPY)
	void print_as_JPY() {
		int cents_value = dollars * 100 + cents;
		int value_in_jpy = CDN_TO_JPY * cents_value + 50; /* round up to next value */
		
		cout << YEN_SYMBOL << value_in_jpy / 100 << endl; /* sens not used */
			
	}
	
	// PURPOSE: Outputs the current value in New Zealand Dollars (NZD)
	void print_as_NZD() {
		int cents_value = dollars * 100 + cents;
		int value_in_nzd = CDN_TO_NZD * cents_value + 0.5; /* round up to next value */
		
		cout << "$" << value_in_nzd / 100 << ".";
		cout.fill('0'); cout.width(2); /* demonstrates how to use fill function */
		cout << value_in_nzd % 100 << " NZD" << endl;
	}
};

// driver function used to test the CurrencyAmountCDN class
void test_CurrencyAmountCDN() {
	CurrencyAmountCDN ca0, ca1(55.45), ca2(25.56), ca3(18.0);
	ca0.print();

	ca1.add(ca2);
	ca1.print();
	ca1.print_as_JPY();
	ca1.print_as_NZD();
	
	ca2.sub(ca1);
	ca2.print();
	ca2.print_as_JPY();
	ca2.print_as_NZD();

	ca3.print();
	ca3.add(ca3);
	ca3.sub(CurrencyAmountCDN(18.0));
	ca3.print_as_JPY();
	ca3.print_as_NZD();	
}

int main() {
	test_CurrencyAmountCDN();
}
