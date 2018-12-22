//loonies and toonies
#include <iostream>

using namespace std;

int compute_value_in_cents(int toonies, int loonies, int quarters); //the above function is

//ptupse a function to cpmute the value in cents
// inputs are toonies, loonies, and quarters asa integer values representing currency amounts
//retunrs an integer value representing the combined value in cents

int main() {

    int toonies = 0, loonies = 0, quarters = 0, sum = 0;

    // step 2 allows the users to enter values

    cout << "toonies?";
    cin >> toonies;
    cout << "loonies?";
    cin >> loonies;
    cout << "quarters?";
    cin >> quarters;

//function call or invocation
    sum = compute_value_in_cents(toonies, loonies, quarters); //inside brackets is the parameters for the function

    cout << "The amount enterd is $";
    cout << sum / 100 << "." << sum % 100 << endl;

return 0;

}

int compute_value_in_cents(int toonies, int loonies, int quarters) {

//step 1

    const int TOONIES_VALUE = 200;
    const int LOONIES_VALUE = 100; //local variables (inside the function)
    const int QUARTERS_VALUE = 25;
    int sum = 0;


//step 2 nothing to do for now

    sum += toonies * TOONIES_VALUE;
    sum += loonies * LOONIES_VALUE;
    sum += quarters * QUARTERS_VALUE;

    return sum;

}
