/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 22nd 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab08
Exercise: 01
File name: lab08_main.cpp
Project: Lab08
Purpose: Books are Awesome

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.
*/
#include <iostream>
#include <vector>
#include "lab08_library.hpp"
#include "lab08_book.hpp"

using namespace std;

/*---------------Book creation-------------------*/
bool test_book_creation() {

    Book hp("Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", "July 8 1999");
    Book tcitr("The Catcher in the Rye", "J.D. Salinger");
    Book gone("Gone");
    Book empty;

    bool test_result = ((hp.get_title() == "Harry Potter and the Prisoner of Azkaban") && (hp.get_authors() == "J.K. Rowling") && (hp.get_dop() == "July 8 1999")
        && (tcitr.get_title() == "The Catcher in the Rye") && (tcitr.get_authors() == "J.D. Salinger") && (tcitr.get_dop() == "X/")
        & (gone.get_title() == "Gone") && (gone.get_authors() == "X") && (gone.get_dop() == "X")
		&& (empty.get_dop() == "X") && (empty.get_authors() == "X") && (empty.get_dop() == "X")
    );
   return test_result;
}//book creation
/*-----------Library creation-----------*/
bool test_library_creation() {
    Library lib1;
    vector<Book> books = {};
    Library lib2(books);
    bool test_result = true; 
    return test_result;
}//library creation 
/*---------------Book Insertion-------------------*/
bool test_book_insertion() {
	// Library test_library;
	// test_library.insert_book(...);
	Book hp("Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", "July 8 1999");
    Book tcitr("The Catcher in the Rye", "J.D. Salinger");
    Book gone("Gone");
    Book free;
    Library lib;

    bool test_result = (
    	// Insertion of book objects
        (lib.insert_book(hp) == true)
       	&& (lib.insert_book(hp) == false) 
        && (lib.insert_book(tcitr) == true)
        && (lib.insert_book(gone) == true)
        && (lib.insert_book(free) == true)

        // Insertion by string arguments
        && (lib.insert_book("title", "author", "dop") == true)
        && (lib.insert_book("title", "author", "dop") == false) 
        && (lib.insert_book("n/a", "n/a", "n/a") == false) 
    );
    return test_result;
}//book insertion
/*------------------Book Removal-------------------*/
bool test_book_removal() {
	// Library test_library;
	// test_library.remove_book(...);
	Book hp("Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", "July 8 1999");
    Book tcitr("The Catcher in the Rye", "J.D. Salinger");
    Book gone("Gone");
    Book free;
    vector<Book> books = {hp, gone, free}; 
    Library lib(books);

    bool test_result = ((lib.remove_book(hp) == true)
    	&& (lib.remove_book(hp) == false) 
        && (lib.remove_book(tcitr) == false) 
        && (lib.remove_book(gone) == true)
		&& (lib.remove_book("n/a", "n/a", "n/a") == true) 
        && (lib.remove_book("n/a", "n/a", "n/a") == false) 
    );
    return test_result;
}//book removal
/*------------------Run------------------------*/
bool run() {
	bool result = true;

	result = result && test_book_insertion();
	result = result && test_book_removal();

	return result;
}//run
/*---------------Main-------------------*/
int main() {
	Book my_book;
	my_book.print();

    bool book_creation  = test_book_creation();
    bool book_insertion = test_book_insertion();
    bool book_removal = test_book_removal();
    bool library_creation = test_library_creation();

	cout << (run() ? "All tests passed." : "Some tests failed."); //based on if run is true or false, left of colon true otherwise right of colon
	
    return 0;
}//main
