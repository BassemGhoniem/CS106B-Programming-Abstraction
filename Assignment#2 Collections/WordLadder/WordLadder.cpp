/*
 * File: WordLadder.cpp
 * --------------------
 * Word ladder finds the shotest ladder between two words
 * Author : Bassem 20/9/2013
 */

#include <iostream>
#include <string>
#include <sstream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include "strlib.h"

using namespace std;
string printLadder(Vector<string>& ladder);
string wordLadder(string start, string destination, Lexicon& english);
int main() {
	
	Lexicon english("EnglishWords.dat");
	while(true){
		string start = trim(toLowerCase(getLine("Enter start word (RETURN to quit) : ")));
		if(start == "")break;
		string destination = trim(toLowerCase(getLine("Enter destination word: ")));

		if(english.contains(start) && english.contains(destination))
			cout << wordLadder(start, destination, english)<< endl;
		else
			cout << "Please Enter English Words!" << endl; 

	}
		return 0;
}

string wordLadder(string start, string destination, Lexicon& english){
	Queue< Vector<string> > ladderQueue;
	Lexicon usedWords;
	Vector<string> ladder, newLadder;
	string lastWordInLadder, newWord;
	int n;
	
	ladder.add(start);
	usedWords.add(start);
	ladderQueue.enqueue(ladder); 	
 
	while(!ladderQueue.isEmpty()){
		ladder = ladderQueue.dequeue();
		lastWordInLadder = ladder[ladder.size() - 1];

		if(lastWordInLadder == destination)return printLadder(ladder);
		
		
		for( n = 0; n < lastWordInLadder.length(); n++){
			newWord = lastWordInLadder;


			for(char c = 'a'; c <= 'z'  ; c++){
				newWord[n] = c;
				if(english.contains(newWord) && !usedWords.contains(newWord)){
					newLadder = ladder;
					newLadder.add(newWord);
					usedWords.add(newWord);
					ladderQueue.enqueue(newLadder);
				}
			}

		}
	}
	return "No ladder found" ;
}

string printLadder(Vector<string>& ladder){
	ostringstream output;
	foreach(string word in ladder){
		output << word << " ";
	}
	
	return output.str();
}
