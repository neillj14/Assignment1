
# COM326 assignment 1

## Problem statement:
Implement a simple date class called `UUDate` in C++. The `UUDate.h` file declares the interface for the class. You must
implement the member functions in the `UUDate.cpp` file. __DO NOT__ change the signatures of the class member functions
or the data members of the class. You can add your own utility member functions or data members. However, your
code must provide the public member functions as specified in the `UUDate.h` file.

## Exceptions
* Do not throw exceptions in your code. Just ignore invalid arguments.

## Notes
* We are using the Gregorian Calendar only
* The code in `UUDate.cpp` should __not__ write out to the console or accept input from the keyboard
* Make sure your code compiles and runs. __There are no points for code that does not compile__
* You will receive marks for every test your code passes
* Check the logs from Travis to verify the correctness of your program

## Marking scheme
Your assignment mark will be based on the unit tests passed. The unit tests for this assignment are:

\# | Description | Marks
--- | ----------- | -----
1 |	Test GetDay on using default constructor | 2
2 |	Test GetMonth on using default constructor |	2
4 |	Test default constructor |	2
3 |	Test Getyear on using default constructor |	2
5	| Test create date constructor with valid arguments |	4
6 |	Test create date constructor with invalid day argument |	4
7 |	Test create date constructor with invalid month argument |	4
8 |	Test create date constructor with year 0 fails |	2
9 |	Test setDay with bad day argument |	2
10 | Test setDay with argument 29 on non leap year |	3
12 |	Test setYear with bad year argument |	3
11 |	Test setMonth with bad argument |	3
13 |	Test constructor with string1  |	5
14 |	Test constructor with string  |	5
15 |	Test incrementDate - increments the day |	4
16 |	Test incrementDate - increments the month |	5
17 |	Test incrementDate - increments the year |	6
18 |	Test incrementDate works for leap years 29/02	| 6
19 |	Test increment date functions correctly 29/03 moves to 01/04 |	6
20 |	Check BetweenDates | 8
21 |	Check Between2 - different days and months |	8
22 |	Check Between3 - different years |	8
23 |	GetDate returns correct string |	6
