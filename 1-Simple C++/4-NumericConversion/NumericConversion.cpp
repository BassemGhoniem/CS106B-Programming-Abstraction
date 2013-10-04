/*
 * File: NumericConversion.cpp
 * ---------------------------
 * This program implements numeric conversions integers to strings and
 * digit strings to integers using recursion
 */

#include <iostream>
#include <string>
#include <cmath>
#include "console.h"
#include "error.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
string positiveIntToString(int n);
int stringToInt(string str);
int stringToPositiveInt(string str);

/* Main program */

int main() {
	int n ;
	string value;
	cout << "enter number to convert to string: " ;
	cin >> n;
	cout << intToString(n) << endl;
	cout << "enter digit string to convert to number: " ;
	cin >> value;
	cout << stringToInt(value) << endl;
	return 0;
}
/*
 * intToString function returns string digits from an integer and defines 
 * tow special cases 
 *	when the integer is 0 retuen the "0" string;
 *	when the integer is version make the conversion as if it's positive
 *	 and then attach the '-' character to it
 */
string intToString(int n){
	if( n == 0)return "0";
	if( n <  0)return "-" + positiveIntToString(-n);
	else return positiveIntToString(n);
}



string positiveIntToString(int n){
	if(n == 0)return string() ;
	else return positiveIntToString(n / 10) + char(n % 10 + '0');
}


int stringToInt(string str){
	if(str[0] == '-')return - stringToPositiveInt(str.substr(1));
	else return stringToPositiveInt(str);
}

/* stringToPositiveInt functon first examine if the first char is digit
 * or not. if the char is not digit char then the program terminates
 * and show error message otherwise the function make the conversion 
 * int to string recursively using the one digit char string as a base
 * case returning the value of the char by computing it's distance from
 * the '0' digit char.
 */


int stringToPositiveInt(string str){
	int strLength = str.length();
	int value = 0;
	char ch = str[0];


	if(isdigit(ch)){

		if(strLength == 1){
			return value = ch - '0';
		}else{
			int mostSignificant = pow(10,strLength - 1) * stringToPositiveInt(str.substr(0, 1));
			int lessSignificant = stringToPositiveInt(str.substr(1));
			return mostSignificant + lessSignificant;	
		} 

	}else{
		error("stringToInteger: Illegal integer format (" + str + ")");
	}
}
