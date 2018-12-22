//Nov 6, Lecture 11 practice with classes and structs, SUrin Rao 
#include <iostream>

using namespace std;

struct Person { //be specific with naming and only put things that relate to each other inside the structure 
	string first_name;
	string last_name;
	string dob;  
};// <- VERY IMPORTANT

struct Date {
public: //public, can be accessed by the entire "world" (everything in this file) 
	int day;
	int month;
	int year;
};

void print_date (const Date& new_date) { //const param
	cout << "DAY: " << new_date.day << endl;
	cout << "MONTH: " << new_date.month << endl;
	cout << "YEAR: " << new_date.year << endl;
}

Person initialize_person() { //returns Person instance
	Person new_person; //

	cin >> new_person.first_name;
	cin >> new_person.last_name;
	cin >> new_person.dob;

	return new_person;
}//initialize person

class VIP { //declare VIP class
	//classes are private, meaning they are only available inside that class
private:
	string first_name; //private member variable
	string last_name; //private member variable
	string dob; //private member variable

}

int main() {

	Date my_date;
	my_date.day = 6;
	my_date.month = 11;
	my_date.year = 2018;

	print_date(my_date);



	//Person p = initialize_person(); //assign
	//cout << p.first_name << endl;

/*
//	string my_string; <- use this format
	Person my_person; //allocating space for Person instance
	//calling default contructors for each string element 
	Person my_person2; 

	my_person.first_name = "ZHUWE"; //accessing member variables and
	my_person.last_name = "MAMA"; //changing their values 
	my_person.dob = "November 6th 2018";

	my_person2 = my_person; // = sign is an assignment operator, it will take all the data from my_person and copy them 1 at a time to my_person2
	my_person2.first_name = "JOHNNY"; //independent of my_person, won't affect their values 
	my_person.last_name = "LOYAL"; 

	cout << my_person.first_name << endl;
	cout << my_person.last_name << endl;

	cout << my_person2.first_name << endl;
	cout << my_person2.last_name << endl;
*/
}







