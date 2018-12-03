/*
* UUDate.cpp
*
* Version information
* Author: Jamie Neill B00732059
* Date: 15/10/2018
* Description: This file is the implementation file for the UUDate class and
* defines (implements) the functions of the class
*
* Copyright notice - Jamie Neill, Ulster University, 2018
*/

#include<regex>
#include<iostream>
#include<cmath>
#include "UUDate.h"

UUDate::UUDate() {
    /*
    Default constructor:
    Initialises the day_ and month_ to 1
    Initialises the year_ to 2000
    */
    day_ = 1;
    month_ = 1;
    year_ = 2000;
}

UUDate::UUDate(int day, int month, int year) {
    /*
    Custom constructor:

    So long as the month provided is valid, set the month_
    member of the object to the provided month, otherwise,
    set it to one (1)
    */
    if (month >= 1 && month <= 12) {
        month_ = month;
    }
    else {
        month_ = 1;
    }

    /*
    So long as the day provided is valid for the month & year provided,
    set the day_ member of the object to the provided day, otherwise,
    set it to one (1)
    */
    if (day > 0 && day <= 31) {
        switch (month) {
        case 1://Jan
            if (day < 31) {
                day_ = day;
            }
            break;
        case 2://Feb
            if (day < 28) {
                day_ = day;
            }
            else if (day == 28 && IsLeapYear(year)) {
                day_ = day;
            }
            else if ((day == 28 && !IsLeapYear(year)) || day_ == 29) {
                day_ = day;
            }
            break;
        case 3://Mar
            if (day <= 31) {
                day_ = day;
            }
            break;
        case 4://Apr
            if (day <= 30) {
                day_ = day;
            }
            break;
        case 5://May
            if (day <= 31) {
                day_ = day;
            }
            break;
        case 6://Jun
            if (day <= 30) {
                day_ = day;
            }
            break;
        case 7://Jul
            if (day <= 31) {
                day_ = day;
            }

            break;
        case 8://Aug
            if (day <= 31) {
                day_ = day;
            }

            break;
        case 9://Sep
            if (day <= 30) {
                day_ = day;
            }
            break;
        case 10://Oct
            if (day <= 31) {
                day_ = day;
            }
            break;
        case 11://Nov
            if (day <= 30) {
                day_ = day;
            }
            break;
        case 12://Dec
            if (day <= 31) {
                day_ = day;
            }
            break;
        default:
            break;
        }
    }
    else {
        day_ = 1;
    }
    /*
    So long as the year provided is valid set the year_
    member of the object to the provided year, otherwise,
    set it to 2000
    */
    if (year > 0) {
        year_ = year;
    }
    else {
        year_ = 2000;
    }
}

UUDate::UUDate(std::string date) {
    /*
    Check that the provided date string matches 
    the form d/d/yyyy OR dd/dd/yyyy
    */
    std::regex dateFormatString{ R"(\d{1,2}\/\d{1,2}\/\d{4})" };

    /*If the provided date DOES match one of the formats :

    Set the day_ data member of the object to the integer representation
    of everything from the first character of the date string until the
    first '/' character.

    set the month_ data member to the integer representation of the
    characters between the first '/' character(exclusive) and the
    second '/' character(exclusive)

    Set the year_ data member to the integer representation of the
    characters between the second '/' character(exclusive) and the
    end of the string(inclusive)
        */
    if (std::regex_match(date, dateFormatString)) {
        day_ = std::stoi(date.substr(0, date.find_first_of('/')));
        month_ = std::stoi(date.substr(date.find_first_of('/') 
            + 1, date.find_last_of('/')));
        year_ = std::stoi(date.substr(date.find_last_of('/')
            + 1, date.length()));
    }

    /*
    If the date DOES NOT match one of the formats:

    Set the day_ and month_ data members to one (1)

    Set the year_ data member to 2000
    */
    else {
        day_ = 1;
        month_ = 1;
        year_ = 2000;
    }
}

void UUDate::IncrementDate() {
    /*
    Depending on the month, if the current day_ data member of the
    object is less than the maximum day this month has this
    year add one (1) to the day_ data member of the object.

    OTHERWISE, set the day to 1 and add one(1) to the month
    of the object.

    EXCEPT WHEN: The current month_ data member of the object is 12
    and the current day_ data member is 31, in which case, set the
    data members of day_ and month_ to one(1) and add one (1) to the
    year_ data member of the object.
    */
    switch (month_) {
    case 1:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 2:
        if (day_ < 28) {
            ++day_;
        }
        else if (day_ == 28 && IsLeapYear(year_)) {
            ++day_;
        }
        else if ((day_ == 28 && !IsLeapYear(year_)) || day_ == 29) {
            day_ = 1;
            ++month_;
        }
        break;
    case 3:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 4:
        if (day_ < 30) {
            ++day_;
        }
        else if (day_ == 30) {
            day_ = 1;
            ++month_;
        }
        break;
    case 5:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 6:
        if (day_ < 30) {
            ++day_;
        }
        else if (day_ == 30) {
            day_ = 1;
            ++month_;
        }
        break;
    case 7:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 8:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 9:
        if (day_ < 30) {
            ++day_;
        }
        else if (day_ == 30) {
            day_ = 1;
            ++month_;
        }
        break;
    case 10:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            ++month_;
        }
        break;
    case 11:
        if (day_ < 30) {
            ++day_;
        }
        else if (day_ == 30) {
            day_ = 1;
            ++month_;
        }
        break;
    case 12:
        if (day_ < 31) {
            ++day_;
        }
        else if (day_ == 31) {
            day_ = 1;
            month_ = 1;
            ++year_;
        }
        break;
    default:
        break;
    }
}

int UUDate::Between(UUDate date) {
    /*
        Create an int vairable to store the difference in days
    */
    int Difference{};
    /*
        Create a copy of the object the function's being called on to preserve
        it's data during the Incremtation process.
    */
    UUDate Current{ day_, month_, year_ };
    /*
        While the day_ month_ or year_ components arent equal, increment
        the date by one and count how many times this is done until the 
        current object and the argument object are the same
    */
    while ((Current.GetDay() < date.GetDay()) || 
        (Current.GetMonth() < date.GetMonth()) || 
        (Current.GetYear()< date.GetYear())) {
        Current.IncrementDate();
        Difference += 1;
    }
    /*Return the number of times the above loop was executed*/
    return Difference;
}

int UUDate::GetDay() const {
    /*Return the value of the Object's day_ data member*/
    return day_;
}

void UUDate::SetDay(int day) {
    /*
    Check if the provided day is greater than 0
    */
    if (day > 0) {
        /*
        If the provided day is greater than 0 and 28
        and the year of the object isn't a leap year
        and the month of the object is February,
        make no change and return to execution.
        */
        if (!IsLeapYear(year_) && day > 28 && month_ == 2) {
            return;
        }

        /*
        If the object, with the provided day, is a day in february not on a
        leap year and the provided day is <= 28 set the day of the object
        to the day provided.
        */
        else if (day <= 28 && month_ == 2 && !IsLeapYear(year_)) {
            day_ = day;
        }

        /*
        If the object with the provided day is a day in february on a
        leap year and the provided day is <= 29 set the day of the object
        to the day provided.
        */
        else if ((day <= 29 && month_ == 2) && IsLeapYear(year_)) {
            day_ = day;
        }

        /*
        If the object is not in february and the provided day is <= 30
        set the day of the object to the provided day
        */
        else if (day <= 30 && month_ != 2) {
            day_ = day;
        }

        /*
        If the provided date is 31 and the object's month isnt a
        month with only 30 days set the day of the object to the day provided.
        */
        else if ((month_ != 9 || month_ != 4 || month_ != 6 || month_ != 11)
            && day <= 31) {
            day_ = day;
        }
    }
}

int UUDate::GetMonth() const {
    /*
    Return the value of the Object's month_ data member
    */
    return month_;
}

void UUDate::SetMonth(int month) {
    /*
        Providing the provided month is valid
        Set the value of the Object's month_ data member
        to the provided month value
    */
    if (month >= 1 && month <= 12) {
        month_ = month;
    }
}

int UUDate::GetYear() const {
    /*
    Return the value of the Object's year_ data member
    */
    return year_;
}

void UUDate::SetYear(int year) {
    /*
        Providing the provided year is valid
        Set the value of the Object's year_ data member
        to the provided month value
    */
    if (year >= 1) {
        year_ = year;
    }
}

std::string UUDate::GetDate() {
    /*
    Convert to strings and concatenate the object's
    day_ mont_ and year_ data members with '/'
    characters between each and return the resulting string.
    */
    std::string date;
    date.append(std::to_string(day_) + "/" + std::to_string(month_) + "/" 
        + std::to_string(year_));
    return date;
}

bool UUDate::IsLeapYear(int year) {
    /*
    If the year is divisible by 400 it's a leap year

    If it's divisible by 4 and 100 It's not a leap year
    If it's divisible by 4 it's a leap year

    If it's divisible by neither 4 nor 400
    its not a leap year
    */
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 4 == 0) {
        if (year % 100 == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
