/*
Student Name: Surin Rao
Student Number: 20760312
Date: November 22nd 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab08
Exercise: 01
File name: lab08_library.cpp
Project: Lab08
Purpose: Books are Awesome

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.
*/
#include "lab08_book.hpp"
#include "lab08_library.hpp"
#include <vector>
#include <string>
#include <iostream>


using namespace std;

/*------------------Library::Library() : books({})----------------*/
Library::Library() : books({}) {
	//making empty one
} //Library::Library() : books({})

/*---------------Library::Library(vector<Book> new_books) : books(new_books)------------------*/
Library::Library(vector<Book> new_books) : books(new_books) {
}//Library::Library(vector<Book> new_books) : books(new_books)

/*---------------Library::insert_book(Book new_book)-------------------*/
bool Library::insert_book(Book new_book) {
    if (index_of(new_book) == -1) { //if the book isn't in the lib, (-1 from before)
        books.push_back(new_book);
        return true;
    }//if 

    else {
    	return false;
    }//else 
}//Library::insert_book(Book new_book)

/*---------------Library::insert_book(string new_title, string new_authors, string new_dop)-------------------*/
bool Library::insert_book(string new_title, string new_authors, string new_dop) {
    Book new_book(new_title, new_authors, new_dop);
    return insert_book(new_book);
}//Library::insert_book(string new_title, string new_authors, string new_dop)

/*---------------Library: remove book-------------------*/
bool Library::remove_book(Book current_book) {
    int cur_index= index_of(current_book);
    if (cur_index!= -1) { //does not equal -1, so it is there already 
        books.erase(books.begin() + cur_index); //to remove the book at that certain cur_index
        return true;
    }//if 

    else {
        return false;
    }//else 
}//Library::remove_book(Book current_book)

//cur_title, cur_authors, cur_dop same variables as used in the header, .hpp file 
/*---------------Library::remove_book(string cur_title, string cur_authors, string cur_dop)-------------------*/
bool Library::remove_book(string cur_title, string cur_authors, string cur_dop) { 
    Book current_book(cur_title, cur_authors, cur_dop);
    return remove_book(current_book);
}//Library::remove_book(string cur_title, string cur_authors, string cur_dop)

/*---------------Library::index_of(Book new_book)-------------------*/
int Library::index_of(Book new_book) {
    for (int i = 0; i < books.size(); i++) {
        Book existing_book = books[i]; //at this index, starting at 0 (start)
        bool same_name = (existing_book.get_title() == new_book.get_title());
        bool same_author = (existing_book.get_authors() == new_book.get_authors());
        bool same_date = (existing_book.get_dop() == new_book.get_dop());

        if (same_name && same_author && same_date) {
            return i; //if true 
        }//if
    }//for

    else {
    	return -1;
	}//else return this 
}//Library::index_of(Book new_book)
/*---------------Library::print()-------------------*/
void Library::print() {
    for (int i = 0; i < books.size(); i++) {
        cout << "Book " << i << ":\n";
        books[i].print();
    }//for 
}//Library::print() 

