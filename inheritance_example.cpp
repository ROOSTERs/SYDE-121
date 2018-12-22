#include <iostream>
using namespace std;

class Person {
	string first_name, last_name, date_of_birth; // private member variables
public:
	Person() {
	}
	
	Person(string new_fname, string new_lname, string new_dob) :
		first_name(new_fname), last_name(new_lname), date_of_birth(new_dob) {
	}
	
	void print();
};

class Student : public Person {
	string student_ID, faculty, major;
public:
	Student() { // invokes Person() automatically
	}
	
	Student(string new_ID, string new_faculty, string new_major, Person new_person) :
		Person(new_person), student_ID(new_ID), faculty(new_faculty), major(new_major) {
	}

	void print();
};

void Person::print() {
	cout << first_name << endl;
	cout << last_name << endl;
	cout << date_of_birth << endl;
}

void Student::print() {
	Person::print(); // calls Person::print()
	cout << student_ID << endl;
	cout << faculty << endl;
	cout << major << endl;
}	

int main() {
	Person p1("John", "Smith", "Jan 15 1985");
	Student s1("12345678", "Engineering", "Systems Design Engineering", p1);
	s1.print(); // calls Student::print()
	s1.Person::print(); // calls Person::print()
	return 0;
}

