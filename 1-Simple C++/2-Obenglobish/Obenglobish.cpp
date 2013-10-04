/*
 * File: Obenglobish.java
 * ----------------------
 * This program translate English word to Obenglobish
 * in which words are created by adding the letters ob
 * before the vowels (a, e, i, o, and u) in an English word.
 * 
 * Except
 * • Vowels that follow other vowels
 * • An e that occurs at the end of the word
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

string obenglobish(string word);
bool isVowel(char ch);


/* Main program */

int main() {
	while (true) {
		string word = getLine("Enter a word: ");
		if (word == "") break;
		string trans = obenglobish(word);
		cout << word << " -> " << trans << endl;
	}
	return 0;
}

string obenglobish(string word){
	string result ="";
	bool successiveVowel = false;


	for(int i = 0; i < word.length()-1; i++){
		if(isVowel(word[i]) && !successiveVowel){ 
			result += "ob";
			result += word[i];
			successiveVowel = true;
		}else if(!isVowel(word[i])){
			result += word[i];
			successiveVowel = false;
		}else result += word[i];				
	}

	//check the last char in the word if it vowel and not 'e' and don't has adjacent vowel
	if(isVowel(word[word.length()-1]) && word[word.length()-1] != 'e' && !successiveVowel ){ 
		result += "ob";
		result += word[word.length()-1];
		successiveVowel = true;
	}else result += word[word.length()-1];
		
	return result;
}

bool isVowel(char ch){
	switch(ch){
		case 'A':case 'E':case 'I':case 'O':case 'U':
		case 'a':case 'e':case 'i':case 'o':case 'u':
			return true;
		default:
			return false;
	}
}
