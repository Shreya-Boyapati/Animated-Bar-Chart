// Bar Chart Animation
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//
//
// Creative Component: user control of playback rate
// user is prompted to enter playback rate
// entered rate is fourth parameter to overloaded animate() function
// entered rate will be speed at which frames are output
// added overloaded animate() function to allow modified playback rate

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	
	string filename;
  
  cout << "Enter filename: " << endl;
  cin >> filename;
  
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
  
  // testing creative component
  /*
  int playback;
  
  cout << "Enter playback rate: " << endl;
  cin >> playback;
  
  bca.animate(cout, 12, 10, playback);
  */
  
	bca.animate(cout, 12, 10);

    return 0;
}
