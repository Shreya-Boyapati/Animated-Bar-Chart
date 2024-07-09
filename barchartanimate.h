// barchartanimate.h
//
// Shreya Boyapati
// netid: sboyap2
//
// CS251
// Project 3 - Animated Bar Chart
//
// header file defines animation of barchart

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for animation of barchart
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;

 public:

    // a parameterized constructor:
    // 
    // initializes with default values
    BarChartAnimate(string title, string xlabel, string source) {
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;

        size = 0;
        capacity = 4;

        barcharts = new BarChart[4];
    }

    // destructor:
    //
    // called automatically by c++ to free memory
    virtual ~BarChartAnimate() {
       delete[] barcharts;
    }

    // addFrame()
    // 
    // adds a new BarChart to the BarChartAnimate object
    // values of BarChart are determined by filestream
    void addFrame(ifstream &file) {
      if (size == capacity) {
          int newCapacity = capacity * 2;
          BarChart* newBarCharts = new BarChart[newCapacity];

          for (int i = 0; i < size; ++i) {
            newBarCharts[i] = barcharts[i];
          }

          delete[] barcharts;
          barcharts = newBarCharts;
          capacity = newCapacity;
      }

      int bc_size;

      file >> bc_size;

      BarChart bc(bc_size);

      string bc_frame, bc_name, bc_category, str;
      int bc_value, sep1, sep2, sep3, sep4;

      getline(file, str);

      for (int i = 0; i < bc_size; i++) {
        getline(file, str);

        sep1 = str.find(",");
        bc_frame = str.substr(0, sep1);
        bc.setFrame(bc_frame);
        str.erase(0, sep1+1);

        sep2 = str.find(",");
        bc_name = str.substr(0, sep2);
        str.erase(0, sep2+1);

        sep3 = str.find(",");
        str.erase(0, sep3+1);

        sep4 = str.find(",");
        bc_value = stoi(str.substr(0, sep4));
        str.erase(0, sep4+1);

        bc_category = str;

        bc.addBar(bc_name, bc_value, bc_category);
      }

      barcharts[size] = bc;
      size++;
      getline(file, str);
    }

    // animate()
    // 
    // displays each frame stored in barcharts one by one
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        if (endIter == -1) {
          endIter = size;
        }

        map<string, string> colorMap;
        int count = 0;

        for (int i = 0; i < endIter; i++) {
          for (int j = 0; j < barcharts[i].getSize(); j++) {
            if (colorMap.count(barcharts[i][j].getCategory()) == 0) {
              colorMap.insert({barcharts[i][j].getCategory(), COLORS[count]});
              count++;
              if (count == 7) {
                count = 0;
              }
            }
          }
        }

        for (int i = 0; i < endIter; i++) {
          output << CLEARCONSOLE;
          cout << title << endl;
          cout << source << endl;
          barcharts[i].graph(output, colorMap, top);
          output << BLACK;
          cout << xlabel << endl;
          cout << barcharts[i].getFrame() << endl;
          usleep(3 * microsecond);
        }
	}
  
    // animate()
    // 
    // displays each frame stored in barcharts one by one
    // playback rate of animation is parameterized
  void animate(ostream &output, int top, int endIter, int playback_rate) {
        if (endIter == -1) {
          endIter = size;
        }

        map<string, string> colorMap;
        int count = 0;

        for (int i = 0; i < endIter; i++) {
          for (int j = 0; j < barcharts[i].getSize(); j++) {
            if (colorMap.count(barcharts[i][j].getCategory()) == 0) {
              colorMap.insert({barcharts[i][j].getCategory(), COLORS[count]});
              count++;
              if (count == 7) {
                count = 0;
              }
            }
          }
        }

        for (int i = 0; i < endIter; i++) {
          output << CLEARCONSOLE;
          cout << title << endl;
          cout << source << endl;
          barcharts[i].graph(output, colorMap, top);
          output << BLACK;
          cout << xlabel << endl;
          cout << barcharts[i].getFrame() << endl;
          usleep(playback_rate);
        }
	}

    // getSize()
    // 
    // public member function
    // returns size of BarChartAnimate object
    int getSize() {
        return size;
    }

    // operator[]
    // 
    // public member function
    // returns BarChart element in BarChartAnimate
    // if i is out of bounds, error message is thrown
    BarChart& operator[](int i) {
        if (i > capacity) {
          throw out_of_range("BarChartAnimate: i out of bounds");
        }

        return barcharts[i];
    }
};
