//Surin Rao Nov 13 PA 4

#include <iostream>
using namespace std;

//currency amount class
class CurrencyAmountCDN {
    int dollars, cents;

public: //public means can be accessed (not private) 
    CurrencyAmountCDN() : dollars(0), cents(0) {}

    CurrencyAmountCDN(double value) {
        if (value <= 0) {
            dollars = 0, cents = 0;
        }//if
        else {
            dollars = value;
            cents = (value - dollars + 0.005) * 100;
        }//else
    }//CurrencyAmountCDN

    void increment(int add_dollars, int add_cents) {
        int new_value = (dollars + add_dollars) * 100 + (cents + add_cents);

        if (new_value <= 0) {
            dollars = 0, cents = 0;
        }//if
        else {
            dollars = new_value / 100;
            cents = new_value % 100;
        }//else
    }//increment

    void add(CurrencyAmountCDN add_amount) {
        increment(add_amount.dollars, add_amount.cents);
    }//add

    void sub(CurrencyAmountCDN sub_amount) {
        increment(-sub_amount.dollars, -sub_amount.cents);
    }//sub

    void print() {
        cout << "$" << dollars << "." << cents << endl;
    }//print
}; //important to have the ; after

/*--------------MAIN-------------_*/
int main() {
    CurrencyAmountCDN ca1(55.44), ca2(25.56);
    ca1.print();
    ca1.add(ca2);
    ca1.print();
    ca1.sub(ca2);
    ca1.print();
    return 0;
}//main 