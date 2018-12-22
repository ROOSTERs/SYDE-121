#include <iostream>
#include "dollars_and_cents.hpp" // must include the class declaration

using namespace std;

DollarsAndCents::DollarsAndCents() {
    dollars = 0, cents = 0;	
}	

DollarsAndCents::DollarsAndCents(int new_dollars, int new_cents) :
        dollars(new_dollars), cents(new_cents) { 
} 
    
void DollarsAndCents::increment_value(int add_dollars, int add_cents) {	
    int new_cents_value = (dollars + add_dollars) * 100 
                          + (cents + add_cents);
    dollars = new_cents_value / 100;
    cents = new_cents_value % 100;
}

void DollarsAndCents::increment_value(DollarsAndCents add_value) {
    increment_value(add_value.dollars, add_value.cents);
}

void DollarsAndCents::decrement_value(int sub_dollars, int sub_cents) {
    increment_value(-sub_dollars, -sub_cents);
}    

void DollarsAndCents::decrement_value(DollarsAndCents sub_value) { 
    increment_value(-sub_value.dollars, -sub_value.cents);
}

void DollarsAndCents::output_value() {
    cout << "$" << dollars << "." << cents << endl;
}
