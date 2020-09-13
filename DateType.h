#define LESS -1
#define EQUAL 0
#define GREATER	1

#ifndef DATETYPE_H
#define DATETYPE_H

// This is file DateType.h
// Here we declare the interface of a class so that we can
// store the information of dates in objects of the DateType class and
// call methods provided by these objects to process date information.
// The actual implementation of the methods are inside DateType.cpp

class DateType
{
private:	// The following members can be directly accessed in DateType.cpp
	int year;
	int month;
	int day;

public:		// The following members can be called anywhere
	DateType();
	// The first constructor method to initialize a DateType object:
	// initialize day, month, year in the object
	// to 1, 1, and 2000 representing 1/1/2000

	DateType(int newMonth, int newDay, int newYear);
	// The second constructor method to initialize a DateType object
	// Check whether newMonth, newDay, newYear compose a valid date first.
	// If they do Not compose a valid date,
	// initialize day, month, year in the object
	// to 1, 1, and 2000 representing 1/1/2000
	// If they do compose a valid date,
	// use newMonth, newDay, newYear to update month, day, year in the object

	int YearIs();       // a method to return year
	int MonthIs();      // a method to return month
	int DayIs();        // a method to return day

	bool SetDate(int newMonth, int newDay, int newYear);
	// A method to set a new date for the DateType object.
	// Check whether newMonth, newDay, newYear compose a valid date first.
	// If they do Not compose a valid date,
	//   do not change the date stored in the object and then return false.
	// If they do compose a valid date,
	//   use newMonth, newDay, newYear to update day, month, year in the object,
	//   and then return true.

	void ReadDate();
	// A method to read in three integers and set them as the
	// day, month, year of the DateType object to the console cout

	void PrintDate();
	// A method to output the contents of the DateType object to the console cout

	int ComparedTo(DateType aDate);
	// Pre: the object itself and aDate should have been initialized.
	// Post: return value should be
	//	LESS, if the object itself comes before aDate.
	//	EQUAL, if the object itself is the same as aDate.
	//	GREATER, if the object itself comes after aDate.

	int ComparedCentury(DateType aDate);
	// Pre: Self and aDate have been initialized.
	// Post: return
	//	LESS, if the object itself comes before the century of aDate.
	//	EQUAL, if the object itself is in the same century as aDate.
	//	GREATER, if the object itself comes after the century of aDate.

	void AdvanceDays(int numDays);
	// If AdvanceDays(numDays), advances numDays into future.
	// If AdvanceDays(-numDays), regresses numDays into the past.

	void BackDays(int numDays);
	// If BackDays(numDays), regresses numDays into the past.
	// If BackDays(-numDays), advances numDays into the future.

	void IncrementDay();
	// Auxiliary for AdvanceDays(numDays) and BackDays(-numDays)
	// Increments by a day
	// Used to advance numDays into future

	void DecrementDay();
	// Auxiliary for AdvanceDays(-numDays) and BackDays(numDays)
	// Decrements by a day
	// Used to regress numDays into the past

	bool IsValidDate(int newMonth, int newDay, int newYear);
	// Checks the arguments passed into it to see that they fall within proper date ranges
	// (positive values, months between 1-12, days that correspond to the given months, etc.)
	
	bool IsLeapYear(int newYear);
	// Auxiliary function to test for leap years
};

#endif