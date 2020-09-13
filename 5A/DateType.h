// This is file DateType.h

// The following two lines are additional compiler directives to avoid the inclusion
// of the contents of DateType.h more than one time when compiling DateType.cpp.
#ifndef MY_DATETYPE_H
#define MY_DATETYPE_H

#define LESS -1
#define EQUAL 0
#define GREATER 1

#include <iostream>
using namespace std;

// Here, we declare the interface of a class so that we can
// store the information of dates in objects of the DateType class and
// call methods provided by these objects to process date information.
// The actual implementation of the methods is inside DateType.cpp.

class DateType
{
private:	// The following members can be direcly accessed in DateType.cpp
	int year;
	int month;
	int day;

public:		// The following members can be called anywhere

  DateType();
  // The first constructor method to initialize a DateType object.
  // Initialize day, month, year in the object to 1, 1, and 2000
  // representing 1/1/2000.

  DateType(int newMonth, int newDay, int newYear);
  // The second constructor method to initialize a DateType object.
  // Check whether newMonth, newDay, newYear compose a valid date first.
  // If they do not compose a valid date, initialize day, month, year in
  // the object to 1, 1, and 2000 representing 1/1/2000.
  // If they do compose a valid date, use newMonth, newDay, newYear to
  // update day, month, year in the object.

  int YearIs();       // a method to return year
  int MonthIs();      // a method to return month
  int DayIs();        // a method to return day

  bool SetDate(int newMonth, int newDay, int newYear);
  // A method to set a new date for the DateType object.
  // Check whether newMonth, newDay, newYear compose a valid date first.
  // If they do not compose a valid date, do not change the date stored
  // in the object and then return false. If they do compose a valid date,
  // use newMonth, newDay, newYear to update day, month, year in the object,
  // and then return true.

  void ReadDate();
  // A method to read in three integers and set them as the day, month, year
  // of the DateType object to the console cout.

  void PrintDate();
  // A method to output the contents of the DateType object to the console cout.

  int ComparedTo(DateType aDate);
  // Pre: the object itself and aDate should have been initialized.
  // Post:
  //    Return LESS, if the object itself comes before aDate.
  //    Return EQUAL, if the object itself is the same as aDate.
  //    Return GREATER, if the object itself comes after aDate.

  int ComparedCentury(DateType aDate);
	// Pre: self and aDate have been initialized.
	// Post:
	//    Returns LESS, if the object itself comes before the century of aDate.
	//    Returns EQUAL, if the object itself is in the same century as aDate.
	//    Returns GREATER, if the object itself comes after the century of aDate.

	void AdvanceDays(int NumDays);
	// Modify the date by advancing it "NumDays" days into the future.
	// Use a loop that repeats for NumDays iterations. Inside the loop,
	// advance the date one day into the future on each iteration of the loop. 
	// Precisely detect whether the current date is in the end of the month.

	void BackDays(int NumDays);
	// Modify the date by pushing it back "NumDays" into the past. Use a loop that
	// repeats for NumDays iterations. Inside the loop, just back down the date one
	// day into the past on each iteration of the loop. Precisely detect whether the
	// current date is in the beginning of the month.

	bool IsValidDate(int Month, int Day, int Year);
	// Check the input date to make sure it is a valid date. Use the if statement or
	// the switch statement to check to return true only when the value in the data
	// member day falls in the range of: 
	//    (i) 1 to 31 if the data member month indicates a month of 31 days, or
	//    (ii) 1 to 30 if the data member month indicates a month of 30 days, or
	//    (iii) 1 to 28 if the data member month indicates it is February while the
	//          data member year indicates it is not a leap year, or 
	//    (iv) 1 to 29 if the data member month indicates it is February while the data
	//          member year indicates it is a leap year.

	void IncrementDay();
	// Auxiliary for AdvanceDays(numDays) and BackDays(-numDays)
	// Increments by a day
	// Used to advance numDays into future

	void DecrementDay();
	// Auxiliary for AdvanceDays(-numDays) and BackDays(numDays)
	// Decrements by a day
	// Used to regress numDays into the past

	bool IsLeapYear(int newYear);
	// Auxiliary function to test for leap years. A year is a leap year if it is divisible by 4
	// except that any year divisible by 100 is a leap year only if it is also divisible by 400. 
	// So 1900 is not a leap year, but 2000 is. In other words,
	//    (i) a year (e.g. 1996) is a leap year if it is divisible by 4 but not by 100, 
	//    (ii) a year (e.g. 2000) is a leap year if it is divisible by 400, 
	//    (iii) otherwise, it is not a leap year.

	void SetRandomDate();
	// Set the contents to a valid random date

	bool operator> (const DateType & aDate);
	// Define the relational operator >
	
	bool operator< (const DateType & aDate);
	// Define the relational operator <
	
	bool operator== (const DateType & aDate);
	// Define the relational operator ==
	
	bool operator!= (const DateType & aDate);
	// Define the relational operator !=
	
	bool operator>= (const DateType & aDate);
	// Define the relational operator >=
	
	bool operator<= (const DateType & aDate);
	// Define the relational operator <=

	DateType operator + (int numDays);
	// Define the arithmetic operator + such that it will return a separate
	// DateType object recording a date that is numDays into the future from
	// the DateType object performing this operation. Note that the date recorded
	// in the DateType object performing this operation remains unchanged.
	
	DateType operator - (int & numDays);
	// Define the arithmetic operator - such that it will return a separate
	// DateType object recording a date that is numDays into the past from
	// the DateType object performing this operation. Note that the date recorded
	// in the DateType object performing this operation remains unchanged.

	int operator - (const DateType & aDate);
	// Define the arithmetic operator - such that it will calculate and return the
	// number of days to go from the DateType object aDate passed as the argument
	// to this DateType object now performing this operation. The number returned
	// should be positive if aDate records a date earlier than that recorded in this date.
	// The number returned should be negative if aDate records a date later than that
	// recorded in this date. The number returned should be 0 if aDate records the same
	// date as that recorded in this date.
	

	/********************************************************************************
	  The following two new global functions are I/O operators for DateType. They are
	  NOT member functions in DateType, but are declared as friends so that they can
	  access the private data members of DateType objects for input and output.
	********************************************************************************/

	friend ostream & operator<< (ostream & output, const DateType & aDate);
	// Check whether output is a reference to cout or not. If output is indeed a
	// reference to cout, print out day, month, year separated by '/'.
	// If output is NOT a reference to cout, it is a reference to an ostream object
	// for file output and simply write out day, month, year separated by ' '.
	
	friend istream & operator>> (istream & input, DateType & aDate);
	// Check whether input is a reference to cin or not. If input is indeed a
	// reference to cin, call the ReadDate method to prompt the user with messages
	// on the screen to enter day, month, year separately from the keyboard,
	// which will check and ensure the validity of date. If input is NOT a reference
	// to cin, it is a reference to an istream object for file input so read the
	// information of day, month, and year into some local variables you declared
	// through input without prompting the user. Then check whether they compose a
	// valid date: If they do, update the day, month, and year in aDate. If not,
	// keep the day, month, and year in aDate unchanged.
};
#endif
