// Variable Practice on September 18th Tutorial
//Distance, miles to km
#include <iostream>
#include <string>
using namespace std;

int main() { //defines scope

  double temp_miles = 120;
  double temp_kilometers = 0; //put one space between operator and operand

  temp_kilometers = (temp_miles * 1.609344); //use brackets to enforce operator precedence

  cout.setf(ios::fixed); //set to fixed precision
  cout.setf(ios::showpoint); // always show point
  cout.precision(4); //4 digit decimal precision

  cout << temp_miles << " in miles equals "
  <<temp_kilometers << " in km \n";

  return 0;

}//close the scope




