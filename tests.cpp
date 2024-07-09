#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarComparator() {
    Bar b("Chicago", 9234324, "US");
    Bar c("Dallas", 2384524, "US");
  
    if (!(c < b)){
      cout << "testBarComparator: < failed" << endl;
      return false;
    }
    else if (!(c <= b)){
      cout << "testBarComparator: <= failed" << endl;
      return false;
    }
    else if (!(b > c)){
      cout << "testBarComparator: > failed" << endl;
      return false;
    }
    else if (!(b >= c)){
      cout << "testBarComparator: >= failed" << endl;
      return false;
    }
    cout << "testBarComparator: all passed!" << endl;
    return true;
}

bool testBarchartDefaultConstructor() {
  BarChart bc;
  
  if (bc.getSize() != 0){
    cout << "testBarchartDefaultConstructor: getSize failed" << endl;
    return false;
  }
  
  BarChart bc2(10);
  bc = bc2;
  
  if (bc2.getSize() != 0) {
    cout << "testBarchartDefaultConstructor: copy operator failed" << endl;
    return false;
  }
  
  bc.setFrame("1950");
  
  if (bc.getFrame() != "1950") {
    cout << "testBarchartDefaultConstructor: getFrame failed" << endl;
    return false;
  }
  cout << "testBarchartDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBarchartParamConstructor() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  
  if (bc.getSize() != 3){
    cout << "testBarchartParamConstructor: getSize failed" << endl;
    return false;
  }
  else if (bc[0].getName() != "Chicago") {
    cout << "testBarchartParamConstructor: addBar failed" << endl;
    cout << "testBarchartParamConstructor: [] failed" << endl;
    return false;
  }
  
  bc.setFrame("1950");
  
  if (bc.getFrame() != "1950") {
    cout << "testBarchartParamConstructor: getFrame failed" << endl;
    return false;
  }
  
  bc.clear();
  
  if (bc.getSize() != 0) {
    cout << "testBarchartParamConstructor: clear failed" << endl;
    return false;
  }
  
  cout << "testBarchartParamConstructor: all passed!" << endl;
  return true;
}

bool testBarchartCopyConstructor() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  
  BarChart bcCopy(bc);
  
  if (bcCopy.getSize() != 3){
    cout << "testBarchartCopyConstructor: getSize failed" << endl;
    return false;
  }
  else if (bcCopy[0].getName() != "Chicago") {
    cout << "testBarchartCopyConstructor: addBar failed" << endl;
    cout << "testBarchartCopyConstructor: [] failed" << endl;
    return false;
  }
  
  bcCopy.setFrame("1950");
  
  if (bcCopy.getFrame() != "1950") {
    cout << "testBarchartCopyConstructor: getFrame failed" << endl;
    return false;
  }
  
  bcCopy.clear();
  
  if (bcCopy.getSize() != 0) {
    cout << "testBarchartCopyConstructor: clear failed" << endl;
    return false;
  }
  cout << "testBarchartCopyConstructor: all passed!" << endl;
  return true;
}

void testDump() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  
  cout << endl;
  cout << "Dumping: " << endl;
  
  bc.dump(cout);
  cout << endl;
}

void testDumpLong() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  bc.addBar("Monte Carlo", 100, "Monaco");
  bc.addBar("London", 1400, "UK");
  bc.addBar("Cairo", 1215, "Egypt");
  bc.addBar("Tehran", 1516, "Iran");
  bc.addBar("Tokyo", 1320, "Japan");
  bc.addBar("Marseille", 1120, "France");
  
  cout << endl;
  cout << "Dumping: " << endl;
  
  bc.dump(cout);
  cout << endl;
}

void testGraph() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  
  string red("\033[1;36m");
  string blue("\033[1;33m");
  map<string, string> colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  
  cout << endl;
  cout << "Graphing: " << endl;
  
  bc.graph(cout, colorMap, 3);
  cout << endl;
}

void testGraphLong() {
  BarChart bc(10);
  
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  bc.addBar("Monte Carlo", 100, "Monaco");
  bc.addBar("London", 1400, "UK");
  bc.addBar("Cairo", 1215, "Egypt");
  bc.addBar("Tehran", 1516, "Iran");
  bc.addBar("Tokyo", 1320, "Japan");
  bc.addBar("Marseille", 1120, "France");
  
  string red("\033[1;36m");
  string blue("\033[1;33m");
  string gold("\033[1;34m");
  string green("\033[1;35m");
  string purple("\033[1;32m");
  
  map<string, string> colorMap;
  
  colorMap["US"] = red;
  colorMap["France"] = blue;
  colorMap["Monaco"] = gold;
  colorMap["UK"] = green;
  colorMap["Egypt"] = purple;
  colorMap["Iran"] = red;
  colorMap["Japan"] = blue;

  cout << endl;
  cout << "Graphing: " << endl;
  
  bc.graph(cout, colorMap, 9);
  
  cout << endl;
}

bool testBarChartAnimateConstructor() {
  string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
  
  BarChartAnimate bca(title, xlabel, source);
  
  if (bca.getSize() != 0){
    cout << "testBarChartAnimateConstructor: getSize failed" << endl;
    return false;
  }
   
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
  
  if (bca[0][0].getName() != "Beijing"){
    cout << "testBarChartAnimateConstructor: addFrame failed" << endl;
    cout << "testBarChartAnimateConstructor: [] failed" << endl;
    return false;
  }
  
  bca.animate(cout, 12, 10);
  
  cout << "testBarChartAnimateConstructor: all passed!" << endl;
  return true;
}

bool testBarChartAnimateConstructorLong() {
  string filename = "baby-names.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
  
  BarChartAnimate bca(title, xlabel, source);
  
  if (bca.getSize() != 0){
    cout << "testBarChartAnimateConstructorLong: getSize failed" << endl;
    return false;
  }
   
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
  
  if (bca[0][0].getName() != "Ada"){
    cout << "testBarChartAnimateConstructorLong: addFrame failed" << endl;
    cout << "testBarChartAnimateConstructorLong: [] failed" << endl;
    return false;
  }
  
  bca.animate(cout, 12, 10);
  
  cout << "testBarChartAnimateConstructorLong: all passed!" << endl;
  return true;
}


int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
  testBarComparator();
  testBarchartDefaultConstructor();
  testBarchartParamConstructor();
  testBarchartCopyConstructor();
  testDump();
  testDumpLong();
  testGraph();
  testGraphLong();
  testBarChartAnimateConstructor();
  testBarChartAnimateConstructorLong();
  
    return 0;
}