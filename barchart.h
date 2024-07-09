// barchart.h
//
// Shreya Boyapati
// netid: sboyap2
//
// CS251
// Project 3 - Animated Bar Chart
//
// header file defines barchart

#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <string>
#include "myrandom.h"
#include "bar.h"

using namespace std;

// Constants used for bar chart animation
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;

 public:
    // default constructor:
    // 
    // initializes BarChart with default values
    BarChart() {
      capacity = 0;
      size = 0;
      bars = nullptr;
      frame = "";
    }

    // parameterized constructor:
    // 
    // parameter passed in determines memory allocated for bars
    BarChart(int n) {
        capacity = n;
        size = 0;
        bars = new Bar[n];
        frame = "";
    }

    // copy constructor:
    //
    // called automatically by C++ to create a copy of an existing BarChart
    BarChart(const BarChart& other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->frame = other.frame;
        
        this->bars = new Bar[this->capacity];
      
        copy(other.bars, other.bars + size, this->bars);
    }

    // copy operator=
    //
    // sets one BarChart object equal to another, i.e. this = other;
    BarChart& operator=(const BarChart& other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->frame = other.frame;

        this->bars = new Bar[this->capacity];

        copy(other.bars, other.bars + size, this->bars);

        return *this;
    }

    // clear()
    // 
    // frees memory and resets all private member variables to default values
    void clear() {
        delete[] bars;
        bars = nullptr;
        capacity = 0;
        size = 0;
    }
    
    // destructor:
    //
    // called automatically by c++ to free memory
    virtual ~BarChart() {
        delete[] bars;
        capacity = 0;
        size = 0;
    }
    
    // setFrame()
    //
    // sets value to track what frame BarChart is associated with
    void setFrame(string frame) {
        this->frame = frame;
    }
    
    // getFrame()
    // 
    // returns the frame of the BarChart object
    string getFrame() {
        return frame;
    }

    // addBar()
    // 
    // adds a Bar to the BarChart
    bool addBar(string name, int value, string category) {
        if (this->getSize() >= capacity) {
          return false;
        }

        Bar b(name, value, category);

        bars[this->getSize()] = b;
        size++;

        return true;
    }
    
    // getSize()
    // 
    // returns the size (number of bars) of the BarChart object
    int getSize() {       
        return size; 
    }
    
    // operator[]
    // 
    // returns Bar element in BarChart
    // if i is out of bounds, error message is thrown
    Bar& operator[](int i) {
      if (i > capacity) {
        throw out_of_range("BarChart: i out of bounds");
      }

      return bars[i];
    }
    
    // dump()
    // 
    // prints contents of the BarChart object
    // output is any stream (cout, file stream, string stream)
    void dump(ostream &output) {
        output << "frame: " << this->frame << endl;

        sort(bars, bars + size, greater<Bar>());

        for (int i = 0; i < size; i++) {
          output << bars[i].getName() << " ";
          output << bars[i].getValue() << " ";
          output << bars[i].getCategory();
          output << endl;
        }
    }
    
    // graph()
    // 
    // prints the Bars in BarChart
    // output is any stream (cout, file stream, string stream)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
        sort(bars, bars + size, greater<Bar>());

        int lenMax = 60;

        string color;  

        for (int i = 0; i < top; i++) {
          if (colorMap.empty()){
            color = BLACK;
          }
          else {
            color = colorMap[bars[i].getCategory()];
          }
          
          string barstr = "";

          double l = double(bars[i].getValue()) / double(bars[0].getValue());
          double length = l * lenMax;

          for (int j = 0; j < int(length); j++) {
            barstr += BOX;
          }

          output << color << barstr << " ";
          output << bars[i].getName() << " " << bars[i].getValue();
          output << endl;
        }
    }
    
};
