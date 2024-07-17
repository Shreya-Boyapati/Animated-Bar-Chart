Animated Bar Chart
=====

The animated bar chart is used to display data in a fun and engaging way. Custom Bar, BarChart, and BarChartAnimate classes are used to create the animation effect and sync it to the input data. Data is spliced into frames that are combined into an animation. Bar chart supports all data inputs in csv format.

Installing, Compiling and Running
---
- Clone and run the project from the command line or chosen IDE
- Build and run the project using the commands ```rm -f application.exe
	g++ -g -std=c++11 -Wall application.cpp -o application.exe```
- Run with ```./application.exe```
- Enter the data file name as keyboard input (stdin). Example data files can be found in the [data](data) directory.

Testing
---
Build tests: ```rm -f tests.exe
	g++ -g -std=c++11 -Wall tests.cpp -o tests.exe```
 
 Run tests: ```./tests.exe```

 Build valgrind: ```valgrind --tool=memcheck --leak-check=yes ./application.exe```

 Run valgrind: ```valgrind --tool=memcheck --leak-check=yes ./tests.exe```
