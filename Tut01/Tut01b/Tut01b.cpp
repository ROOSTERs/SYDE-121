// Variable Practice on September 18th Tutorial
//Temperature, F to C
#include <iostream>
#include <string>
using namespace std;

int main() { //defines scope

  double temp_fahrenheit = 70;
  double temp_celcius = 0; //put one space between operator and operand

  temp_celcius = (temp_fahrenheit - 32) * 5 / 9; //use brackets to enforce operator precedence

  cout.setf(ios::fixed); //set to fixed precision
  cout.setf(ios::showpoint); // always show point
  cout.precision(2); //2 digit decimal precision

  cout << temp_fahrenheit << " in F equals "
  <<temp_celcius << " in C \n";

  return 0;

}//close the scope






