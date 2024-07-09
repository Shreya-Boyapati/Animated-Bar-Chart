// bar.h
//
// Shreya Boyapati
// netid: sboyap2
//
// CS251
// Project 3 - Animated Bar Chart
//
// header file defines single bar of barchart

#include <iostream>
#include <string>
#include "myrandom.h"
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    string name;
    int value;
    string category;

 public:
    // default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
    }

    // destructor:
    virtual ~Bar() {

    }

    // getName()
    //
    // return name of object
	string getName() {
        return name;
	}

    // getValue()
    //
    // returns value of object
	int getValue() {
        return value;
	}

    // getCategory()
    //
    // returns category of object
	string getCategory() {
        return category;
	}

	// operators: <, <=, >, >=
	//
	// overloaded operators for class
	bool operator<(const Bar &other) const {
        if (this->value < other.value) {
          return true;
        }

        return false;
	}

	bool operator<=(const Bar &other) const {
        if (this->value <= other.value) {
          return true;
        }

        return false;
	}

	bool operator>(const Bar &other) const {
        if (this->value > other.value) {
          return true;
        }

        return false;
	}

	bool operator>=(const Bar &other) const {
        if (this->value >= other.value) {
          return true;
        }

        return false;
	}
};
