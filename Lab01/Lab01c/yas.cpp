#include <iostream>

using namespace std; //if you don't have you would have to do std:: to show they are derived from that namespace, using saves time


int main() {

    int uw_id, age, date_of_birth; //allocates space for 3 pieces of data
                                    // format for DOB is DDMMYYYY

    string name;


    //accept as input UW Id, age and date of birth
    //print all 3 in a cohesively formatted sequence
    cout << "Welcome, user!" << endl;

    cout << "What is your name? \n";
    cin >> name;

    cout << "What is your UW ID? \n";
    cin >> uw_id;

    cout << "What is your age? \n";
    cin >> age;

    cout << "What is your date of birth (format DDMMYYYY)? "<< endl;
    cin >> date_of_birth;

    cout << "Hello " << name <<
        "! Your UWID is " << uw_id << ", your age is "
        << age <<" and your DOB is " << date_of_birth << endl;

    return 0; //terminates the program

}




