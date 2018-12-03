/*
* Main.cpp
*
* Version information
* Author: Jamie Neill B00732059
* Date: 18/10/2018
* Description: This file is the driver for the project, 
* use it to test your code. 
*
* Copyright notice - Jamie Neill, Ulster University, 2018
*/
                                                                              
#pragma once 
#include "UUDate.h"
#include<iostream>
using namespace std;

void TestDefault();
void TestInt();
void TestString();
void TestIncrement();
void TestBetween();
void TestGetDay();
void TestSetDay();
void TestGetMonth();
void TestSetMonth();
void TestGetYear();
void TestSetYear();
void TestGetDate();
void TestInvalidConstructors();
void TestInvalidSetters();

int main() {
     TestDefault();
     TestInt();
     TestString();
     TestIncrement();
     TestBetween();
     TestGetDay();
     TestSetDay();
     TestGetMonth();
     TestSetMonth();
     TestGetYear();
     TestSetYear();
     TestGetDate();
     TestInvalidConstructors();
     TestInvalidSetters();

	return 0;

}

void TestDefault(){
    UUDate defaultTest{};
    cout << "TESTING DEFAULT CONSTRUCTOR" << endl;
    cout << "Expected: 1/1/2000 \t Actual: " << defaultTest.GetDate() 
        << endl << endl;
}

void TestInt() {
    UUDate intTest{5,9,2010};
    cout << "TESTING INTEGER ARGUMENT CONSTRUCTOR" << endl;
    cout << "Expected: 5/9/2010 \t Actual: " << intTest.GetDate() 
        << endl << endl;
}

void TestString() {
    UUDate stringTest{ "31/10/2009" };
    cout << "TESTING STRING ARGUMENT CONSTRUCTOR" << endl;
    cout << "Expected: 31/10/2009 \t Actual: " << stringTest.GetDate() 
        << endl << endl;
}

void TestIncrement() {
    UUDate incrementDay{};
    UUDate incrementMonth{"31/01/2009"};
    UUDate incrementYear{"31/12/2017"};
    UUDate incrementFebLeap{"28/02/2012"};
    UUDate incrementFebNonLeap{"28/02/2013"};

    cout << "TESTING INCREMENT DAY" << endl;
    cout << "Initial: " << incrementDay.GetDate();
    incrementDay.IncrementDate();
    cout << "\t Expected: 2/1/2000\tActual: " << incrementDay.GetDate() 
        << endl << endl;

    cout << "TESTING INCREMENT MONTH" << endl;
    cout << "Initial: " << incrementMonth.GetDate();
    incrementMonth.IncrementDate();
    cout << "\t Expected: 1/2/2009\tActual: " << incrementMonth.GetDate() 
        << endl << endl;

    cout << "TESTING INCREMENT YEAR" << endl;
    cout << "Initial: " << incrementYear.GetDate();
    incrementYear.IncrementDate();
    cout << "\t Expected: 1/1/2018\tActual: " << incrementYear.GetDate() 
        << endl << endl;

    cout << "TESTING INCREMENT DAY FOR 28/2/2012" << endl;
    cout << "Initial: " << incrementFebLeap.GetDate();
    incrementFebLeap.IncrementDate();
    cout << "\t Expected: 29/2/2012\tActual: " << incrementFebLeap.GetDate() 
        << endl << endl;

    cout << "TESTING INCREMENT DAY FOR 28/2/2013" << endl;
    cout << "Initial: " << incrementFebNonLeap.GetDate();
    incrementFebNonLeap.IncrementDate();
    cout << "\t Expected: 1/3/2013\tActual: " << incrementFebNonLeap.GetDate() 
        << endl << endl;
}

void TestBetween() {
    UUDate startDays{"1/3/2009"};
    UUDate endDays{"16/3/2009"};
    UUDate startDaysMonths{"2/3/2009"};
    UUDate endDaysMonths{"5/6/2009"};
    UUDate startDaysMonthsYears{"1/5/2003"};
    UUDate endDaysMonthsYears{"7/8/2007"};

    cout << "TESTING BETWEEN 1/3/2009 & 16/3/2009" << endl;
    cout << "Expected: 15\t Actual: " << startDays.Between(endDays)
        << endl << endl;

    cout << "TESTING BETWEEN 2/3/2009 & 5/6/2009" << endl;
    cout << "Expected: 95\t Actual: " 
        << startDaysMonths.Between(endDaysMonths) << endl << endl;

    cout << "TESTING BETWEEN 1/5/2003 & 7/8/2007" << endl;
    cout << "Expected: 1559\t Actual: " 
        << startDaysMonthsYears.Between(endDaysMonthsYears) << endl << endl;
}

void TestGetDay() {
    UUDate dayTest{ "15/3/2001" };

    cout << "TESTING GetDay() FOR 15/3/2001" << endl;
    cout << "Expected: 15\t Actual: " << dayTest.GetDay() << endl << endl;
}

void TestSetDay() {
    UUDate dayTest{ "15/3/2001" };

    cout << "TESTING SetDay(31) FOR 15/3/2001" << endl;
    cout << "Previous Day: "<<dayTest.GetDay();
    dayTest.SetDay(31);
    cout << "\tExpected Day: 31\tActual Day: " << dayTest.GetDay()
        << endl << endl;
}

void TestGetMonth() {
    UUDate monthTest{ "15/3/2001" };

    cout << "TESTING GetMonth() FOR 15/3/2001" << endl;
    cout << "Expected: 3\t Actual: " << monthTest.GetMonth() << endl << endl;
}

void TestSetMonth() {
    UUDate monthTest{ "15/3/2001" };

    cout << "TESTING SetMonth(5) FOR 15/3/2001" << endl;
    cout << "Previous Month: " << monthTest.GetMonth();
    monthTest.SetMonth(5);
    cout << "\tExpected Month: 5\tActual Month: " << monthTest.GetMonth() 
        << endl << endl;
}

void TestGetYear() {
    UUDate yearTest{ "15/3/2001" };

    cout << "TESTING GetYear() FOR 15/3/2001" << endl;
    cout << "Expected: 2001\t Actual: " << yearTest.GetYear() << endl << endl;

}

void TestSetYear() {
    UUDate yearTest{ "15/3/2001" };

    cout << "TESTING SetYear(3008) FOR 15/3/2001" << endl;
    cout << "Previous Month: " << yearTest.GetYear();
    yearTest.SetYear(3008);
    cout << "\tExpected Year: 3008\tActual Year: " << yearTest.GetYear()
        << endl << endl;
}

void TestGetDate() {
    UUDate getDateTest{ "1/11/1998" };
    cout << "TESTING GetDate() ON 1/11/1998" << endl;
    cout << "Expected: 1/11/1998\t Actual: " << getDateTest.GetDate()
        << endl << endl;
}

void TestInvalidConstructors() {
    UUDate invalidInt{ 100 , 50 , -1922 };
    UUDate invalidString{ "10000,320,134" };
    UUDate invalidString2{ "100/3134/-2801" };

    cout << "TESTING INVALID CONSTRUCTORS" << endl;
    cout << "Initializing UUDate{100 , 50 , -1922}\nExpected Date: 1/1/2000";
    cout << "\tActual Date: " << invalidInt.GetDate() << endl << endl;

    cout << "Initializing UUDate{ \"10000, 320, 134\" }"
        <<"\nExpected Date: 1/1/2000";
    cout << "\tActual Date: " << invalidString.GetDate() << endl << endl;

    cout << "Initializing UUDate{ \"100/3134/-2801\" }"
        <<"\nExpected Date: 1/1/2000";
    cout << "\tActual Date: " << invalidString2.GetDate() << endl << endl;
}

void TestInvalidSetters() {
    UUDate invalidSetters{ 15,2,2003 };

    cout << "TESTING INVALID SetDay()" << endl;
    cout << "Current Date: " << invalidSetters.GetDate() << endl;
    cout << "Setting Day to 31..." << endl;
    invalidSetters.SetDay(31);
    cout << "Expected Date: 15/2/2003\tActual Date: " 
        << invalidSetters.GetDate() << endl << endl;

    cout << "TESTING INVALID SetMonth()" << endl;
    cout << "Current Date: " << invalidSetters.GetDate() << endl;
    cout << "Setting Month to 13..." << endl;
    invalidSetters.SetMonth(13);
    cout << "Expected Date: 15/2/2003\tActual Date: " 
        << invalidSetters.GetDate() << endl << endl;

    cout << "TESTING INVALID SetYear()" << endl;
    cout << "Current Date: " << invalidSetters.GetDate() << endl;
    cout << "Setting Year to -2018..." << endl;
    invalidSetters.SetMonth(-2018);
    cout << "Expected Date: 15/2/2003\tActual Date: " 
        << invalidSetters.GetDate() << endl << endl;

}