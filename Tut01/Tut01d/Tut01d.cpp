// Variable Practice on September 18th Tutorial
//Distance, km to miles
#include <iostream>
#include <string>
using namespace std;

int main() { //defines scope

  double temp_kilometers = 120;
  double temp_miles = 0; //put one space between operator and operand

  temp_miles = (temp_kilometers / 1.609344); //use brackets to enforce operator precedence

  cout.setf(ios::fixed); //set to fixed precision
  cout.setf(ios::showpoint); // always show point
  cout.precision(4); //4 digit decimal precision

  cout << temp_kilometers << " in km equals "
  <<temp_miles << " in miles \n";

  return 0;

}//close the scope





