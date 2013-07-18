/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * program that simulate flipping a coin repeatedly 
 * and continues until three consecutive heads are tossed.
 * At this point the program displays the total number of
 * coin flips that were made.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
	int consHeads = 0;
	int  flipNums = 0;
    	string flipResult;
	while(consHeads != 3){
		flipResult = randomChance(0.5) ? "heads" : "tails";
		cout << flipResult << endl;
		flipNums++;
		if(flipResult == "heads")consHeads += 1;
		else consHeads = 0;
	}
	cout << "it take " << flipNums << " to get 3 consecutive heads." << endl;
	return 0;
}
