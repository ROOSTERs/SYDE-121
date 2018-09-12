#include <iostream> //used to include library routines
                    //STL are included with the <...> brackets

 using namespace std; //"using" is used to extend known keywords
                    //"namespace" has access to specific sets of keywords

//create main function
int main() { //int means return type is integer
    int number_of_languages; // also can type it as numberOfLanguages
                            //int will allocate 4 bytes or 32 bits
                            //signed integer value, meaning it can be + or -
                            //int variable_name allocate space for that variable


    cout << "Hello, class! \n"  //cout = console out (system.print.out.ln),<< to print to console \n for new line
                                // alternative to "\n" is to use endl
        << "Welcome to C++! \n"; // "" are used to enclose string values

    //ask the user for the number of programming languages they used previously
    //output thenumber they entered
    cout <<"How many programming languages have you used before? ";
    //console input, also  reverse >. Calling on our previous function
    cin >> number_of_languages; //will accept inputf rom console and store into int variable\\

    cout << "The value you entered is " << number_of_languages << endl;

    return 0; //terminates the program

}



