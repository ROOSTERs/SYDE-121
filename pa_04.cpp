// Name:        Timmy Truong
// ID:          20772704
// Date:        November 13, 2018
// Course:      SYDE 121
// Lab room:    E5 6008
// Assignment:  Practice Activity #4
// Exercise:    Exercise #1
// File Name:   pa_04.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts. This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Practice Activity #4

#include <iostream>
using namespace std;

class CurrencyAmountCDN {
    int dollars, cents;

public:
    CurrencyAmountCDN() : dollars(0), cents(0) {}

    CurrencyAmountCDN(double value) {
        if (value <= 0) {
            dollars = 0, cents = 0;
        }
        else {
            dollars = value;
            cents = (value - dollars + 0.005) * 100;
        }
    }

    void increment(int add_dollars, int add_cents) {
        int new_value = (dollars + add_dollars) * 100 + (cents + add_cents);

        if (new_value <= 0) {
            dollars = 0, cents = 0;
        }
        else {
            dollars = new_value / 100;
            cents = new_value % 100;
        }
    }

    void add(CurrencyAmountCDN add_amount) {
        increment(add_amount.dollars, add_amount.cents);
    }

    void sub(CurrencyAmountCDN sub_amount) {
        increment(-sub_amount.dollars, -sub_amount.cents);
    }

    void print() {
        cout << "$" << dollars << "." << cents << endl;
    }
};

int main() {
    CurrencyAmountCDN ca1(55.44), ca2(25.56);
    ca1.print();
    ca1.add(ca2);
    ca1.print();
    ca1.sub(ca2);
    ca1.print();
    return 0;
}