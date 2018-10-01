/*
Student Name: Surin Rao
Student Number: 20760312
day: September 26th 2018
Course: SYDE 121
Lab Room: WEEF LAB
Assignment: Lab03
Exercise: 03
File name: lab03_03.cpp
Project: Lab03
Purpose: Zodiac Signs

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Outline Steps:
1. Define variables for each zodiac sign
2. Define input for the user to enter, so the date and month of their birthday
3. Do a test to make sure the the day/month is within the reasonable range 
4. When creating the ranges for each sign, make sure to take into account that the user can enter a date such as March 32nd, so we need to set a range for the values accepted for that sign.
5. Output the horoscope of the date they entered.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

/*----Variable Declaration----*/
	int day;
	int month;
//got the information below from this website: http://www.astrology-zodiac-signs.com/
	string Aquarius = "You are an Aquarius. Your main quality is that you are fixed. One of your strengths is that you are original. You are compatible with Leo and Sagittarius. The element associated is Air, which is the element that connects all other elements even though it might seem less relevant, invisible as it is.";
	string Pisces = "You are a Pisces. Your main quality is that you are very mutable. One of your strengths is that you are wise. You are compatible with Virgo and Taurus. The element associated is Water, which is the element of constant movement, but slow and steady, swirling inside each of us and holding on to its mystery.";
	string Aries = "You are a Aries. Your main quality is that you are cardinal. One of your strengths is that you courageous. You are compatible with Libra and Leo. The element associated is Fire which is the only element that shines";
	string Taurus = "You are a Taurus. Your main quality is that you are fixed. One of your strengths is that you are reliable. You are compatible with Scorpio and Cancer. The element associated is Earth, which is the sole purpose of all elements, since it represents a basis for each of them, for our existence, and something we all want to accomplish – materialization of our desires.";
	string Gemini = "You are a Gemini. Your main quality is that you are mutable. One of your strengths is that you are gentle. You are compatible with Aquarius and Sagittarius. The element associated is Air, which is the element that connects all other elements";
	string Cancer = "You are a Cancer. Your main quality is that you are cardinal. One of your strengths is that you are tenacious. You are compatible with Capricorn and Taurus. The element associated is Water, which is the element of constant movement, but slow and steady, swirling inside each of us and holding on to its mystery.";
	string Leo = "You are a Leo. Your main quality is that you are fixed. One of your strengths is that you are creative. You are compatible with Aquarius and Gemini. The element associated is Fire which is the only element that shines";
	string Virgo = "You are a Virgo. Your main quality is that you are mutable. One of your strengths is that you are loyal. You are compatible with Pisces and Cancer. The element associated is Earth, which is the sole purpose of all elements, since it represents a basis for each of them, for our existence, and something we all want to accomplish – materialization of our desires.";
	string Libra = "You are a Libra. Your main quality is that you are cardinal. One of your strengths is that you are cooperative. You are compatible with Aries and Sagittarius. The element associated is Air, which is the element that connects all other elements";
	string Scorpio = "You are a Scorpio. Your main quality is that you are fixed. One of your strengths is that you are resourceful. You are compatible with Taurus and Cancer. The element associated is Water, which is the element of constant movement, but slow and steady, swirling inside each of us and holding on to its mystery.";
	string Sagittarius = "You are a Sagittarius. Your main quality is that you are mutable. One of your strengths is that you are generous. You are compatible with Gemini and Aries. The element associated is Fire which is the only element that shines";
	string Capricorn = "You are a Capricorn. Your main quality is that you are cardinal. One of your strengths is that you are responsible. You are compatible with Taurus and Cancer. The element associated is Earth, which is the sole purpose of all elements, since it represents a basis for each of them, for our existence, and something we all want to accomplish – materialization of our desires.";

	/*------User Questions and Input--------------*/
	cout << "What is the day of your birthday? " << endl;
	cin >> day;

	cout << "What is the month of your birthday? " << endl;
	cin >> month;

	/*------Conditions dictating your zodiac sign--------*/
		if (day > 31 || month < 1 || day < 1 || month > 12) {
		    cout << "Enter a valid day/month combo" << endl;
		}//this is if you enter a date like 13/44
		else if ((month == 1 && day >= 20 && day <= 31) ||(month == 2 && day <= 18)) { //Jan 20 - Feb 18
		    cout << Aquarius << endl;
		}
		else if ((month == 2 && day >= 19 && day <= 29) ||(month == 3 && day <= 20)) { //Feb 19 - Mar 20
		    cout << Pisces << endl;
		}
		else if ((month == 3 && day >= 21 && day <= 31) ||(month == 4 && day <= 19)) { //Mar 21 - Apr 19
		    cout << Aries << endl;
		}
		else if ((month == 4 && day >= 20 && day <= 30) ||(month == 5 && day <= 20)) { //Apr 20 - May 20
		    cout << Taurus << endl;
		}
		else if ((month == 5 && day >= 21 && day <= 31) ||(month == 6 && day <= 20)) { //May 21 - June 20
		    cout << Gemini << endl;
		}
		else if ((month == 6 && day >= 21 && day <= 30) ||(month == 7 && day <= 22)) { //June 21 - Jul 22
		    cout << Cancer << endl;
		}
		else if ((month == 7 && day >= 23 && day <= 31) ||(month == 8 && day <= 22)) { //Jul 23 - Aug 22
		    cout << Leo << endl;
		}
		else if ((month == 8 && day >= 23 && day <= 31) ||(month == 9 && day <= 22)) { //Aug 23 - Sept 22
		    cout << Virgo << endl;
		}
		else if ((month == 9 && day >= 23 && day <= 30) ||(month == 10 && day <= 22)) { //Sept 23 - Oct 22
		    cout << Libra << endl;
		}
		else if ((month == 10 && day >= 23 && day <= 31) ||(month == 11 && day <= 21)) { //Oct 23 - Nov 21
		    cout << Scorpio << endl;
		}
		else if ((month == 11 && day >= 22 && day <= 30) ||(month == 12 && day <= 21)) { //Nov 22 - Dec 21
		    cout << Sagittarius << endl;
		}
		else if ((month == 12 && day >= 22 && day <= 31) ||(month == 1 && day <= 19)) { //Dec 22 - Jan 19
		    cout << Capricorn << endl;
		}
		else {
			cout << "That day/month combo does not exist " << endl;
		}//this is if you enter a date like Feb 30th 

return 0;
}//close main