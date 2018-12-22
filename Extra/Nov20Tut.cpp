#include <iostream>

using namespace std; 

class Page {
	string page_text; //not accessible except for functions of this class 
	int page_number;

public: 
	Page() : page_number(0); { //contructor --> initial value of page number 0 (just in case)
	} //empty constructor, just creating it
	Page(string new_ptext, int new_pnumber) : page_number(new_pnumber), page_text(new_ptext); {//parametric constructor //constructor can't return, exact spelling
	}

	string get_page_text() { //don't really need setters because we have parametric constructor 
		return page_text;
	}
	void set_page_text(string new_page_text) {
		page_text = new_ptext;
	}

	int get_page_number() { //getters for these attributers
		return page_number; 
	}
	void set_page_number(int new_pnumber) {
		page_number = new_pnumber; 
	}

}; //class Page 

class Book {
	Page pages[100]; //array
	vector<Page> my_pages; //vector 

	public: 
		Book() {
		}

		bool insert_page(string new_ptext, int new_pnumber) {
			bool is_inserted = false;
			if(new_pnumber <= 100 && new_pnumber >= 1) {
				pages[new_pnumber - 1] = Page(new_ptext, new_pnumber);
				is_inserted = true;
			}//if
			return is_inserted; 
		}//insert page 

		bool remove_page(int new_pnumber) {
			bool is_inserted = false;
			if(new_pnumber <= 100 && new_pnumber >= 1) {
				pages[new_pnumber - 1] = Page(); 
				is_inserted = true; 
			}//if
			return is_inserted; 
		}//remove page 

}; //class Book

int main() {
	Book b; //creates instance of book
	b.insert_page("Some Text", 5); 
	b.insert_page("More Text", 6);
	b.remove_page(5); 
	return 0;
}//main 