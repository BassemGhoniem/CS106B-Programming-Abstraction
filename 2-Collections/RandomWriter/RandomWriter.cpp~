/*
 * File: RandomWriter.cpp
 * ------------------------------------------------------------------
 *  this program takes an text file as input and produce randomly 
 *  produced text simulates the input text
 *
 *  Bassem
 *  4 / 10 / 2013
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"
#include "filelib.h"
#include "simpio.h"
using namespace std;

void    readSeeds(Map<string, Vector<char> >& seeds,int order, istream& file);
string  findInitSeed(Map<string, Vector<char> >& seeds);
int     getModelOrder();
void    randomWriter(Map<string, Vector<char> >& seeds, string seed, int order);

// Specify the length of the randomly generated text in characters 
const int TEXT_LENGTH = 2000;

int main() {
	Map<string, Vector<char> > seeds;
  
	ifstream stream;	
	promptUserForFile(stream, "Please enter file name: ");
	
  int order = getModelOrder();

	readSeeds(seeds, order, stream);
	string initialSeed = findInitSeed(seeds);
  randomWriter(seeds, initialSeed, order);

	return 0;
}
/*
 * Function : getModelOrder()
 * Usage    : int x = getModelOrder()
 * ------------------------------------------------------------------
 *  accept an integer from the user between 2 and 10 inclusive 
 */

int getModelOrder(){
  int order;
	while(true) {
		order = getInteger("Model Order :");
		if (order > 1 && order < 11) return order;
		else cout << "Enter model between 1 and 10." << endl;
	}
}
/*
 * Function : readSeeds
 * usage :  readSeeds(map, order, streama);
 * -------------------------------------------------------------------
 * forming seeds from text file with the specified length
 */

void readSeeds(Map<string, Vector<char> >& seeds,int order, istream& file){
  string seed;
  char ch;

  // forming the first seed with length equals to model order 
  for(int i = 0; i < order; i++){
    if(file.get(ch)) seed += ch;
  }
  
  //extract the seeds from the file each seed differs by one char from 
  //the previous one, and keeping track for following character.
  while(file.get(ch)){
    if (seeds.containsKey(seed)) {
      seeds[seed].add(ch);
    } else {
      seeds[seed];
      seeds[seed].add(ch);
    }
    file.unget();
    seed = seed.substr(1);
    if(file.get(ch)) seed += ch;
  }
}

/*
 * Function : findInitSeed
 * Usage    : findInitSeed(map);
 * ------------------------------------------------------------------
 *  used for finding the most common seed to be the first seed to print on
 *  the screen 
 */

string findInitSeed(Map<string, Vector<char> >& seeds){
	string commonSeed ="";
	int common =0, size = 0;

	foreach(string seed in seeds){
		size = seeds[seed].size();
		if(size > common) {
			common = size;
			commonSeed = seed;
		}
	}
	return commonSeed;
}

/*
 * Function : randomWriter
 * Usage : randomWriter(seeds, initialSeed, modelOrder);
 * ------------------------------------------------------------------
 *  this function take a map of seeds and associated vactors of characters
 *  that follows that seed and produce random text 
 */

void randomWriter(Map<string, Vector<char> >& seeds, string seed, int order){
  char ch;
  int size  = seeds[seed].size();
  int index;

  for(int i = 0; i < TEXT_LENGTH - order; i++){
    index = randomInteger(0, size - 1);
    ch = seeds[seed].get(index);
    cout << ch ;
    seed  = seed.substr(1) + ch;
    size  = seeds[seed].size();
  }
}
