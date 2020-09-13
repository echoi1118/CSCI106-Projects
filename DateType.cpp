// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h"		// Gain access to specification of class
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

// The first constructor method to initialize a DateType object
// initialize day, month, and year in the object to 1, 1, and
// 2000 (representing 1/1/2000)
DateType::DateType()
{
	year = 2000;
	month = 1;
	day = 1;
}

// The second constructor method to initialize a DateType object
// Check whether newMonth, newDay, newYear compose a valid date first.
// If they do NOT compose a valid date, initialize day, month, year in the object
// to 1, 1, and 2000 (representing 1/1/2000). If they do compose a valid date,
// use newMonth, newDay, newYear to update day, month, year in the object.
DateType::DateType(int newMonth, int newDay, int newYear)
{
	if (IsValidDate(newMonth, newDay, newYear))
	{
		year = newYear;
		month = newMonth;
		day = newDay;
	}
	else
	{
		year = 2000;
		month = 1;
		day = 1;
		cout << endl;
		cout << "_______________________________________________________________________________" << endl << endl
			<< " Invalid arguments passed to the second constructor." << endl;
		cout << left << setw(36) << " Reset to default:" << month << "/" << day << "/" << year << endl;
		cout << "_______________________________________________________________________________" << endl << endl;
	}
}

// A method to set a new date for the DateType object.
// Check whether newMonth, newDay, newYear compose a valid date first.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
	// If they do compose a valid date, use newMonth, newDay, newYear
	// to update day, month, year in the object, and then return true.
	if (IsValidDate(newMonth, newDay, newYear))
	{
		year = newYear;
		month = newMonth;
		day = newDay;
		return true;
	}
	// If they do NOT compose a valid date, do not change the date stored in
	// the object and then return false.
	// This approach keeps bad dates from getting into the DateType object.
	else
		return false;
}

int DateType::MonthIs()
{
	// Accessor function for data member month.
	return month;
}

int DateType::YearIs()
{
	// Accessor function for data member year.
	return year;
}

int DateType::DayIs()
{
	// Accessor function for data member day.
	return day;
}

void DateType::ReadDate()
{
	HANDLE hConsole;				// For console color output

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl
		<< " Read in the date information:" << endl;

	cout << setw(36) << "  The month is:";
	cin >> month;
	cout << setw(36) << "  The day is:";
	cin >> day;
	cout << setw(36) << "  The year is:";
	cin >> year;

	// Using IsValidDate() to check the day, month, and year parameters.
	// Loop runs as long as an invalid day, month, and/or year is given.

	while (IsValidDate(month, day, year) == false)
	{
		cout << endl;
		SetConsoleTextAttribute(hConsole, 14);
		cout << setw(26) << "" << "Error  ||  Invalid Date  ||  Re-entry required" << endl << endl;
		SetConsoleTextAttribute(hConsole, 7);

		cout << setw(36) << "  The month is:";
		cin >> month;
		cout << setw(36) << "  The day is:";
		cin >> day;
		cout << setw(36) << "  The year is:";
		cin >> year;
	}
}

void DateType::PrintDate()
{
	// Output content of DateType object to console in form: mm/dd/yyyy
	if (year <= 0)
	{
		cout << " Error  ||  Invalid Date";					// This is for when user decrements too far back and year becomes 0 or less
		DateType d2;										// date2 is reset to what is in the default constructor (user will not see this,
	}														// but just for posterity, since I don't want a bad date to get stored, period)
	else
		cout << month << "/" << day << "/" << year;			// When all is good, output date to console
}

int DateType::ComparedTo(DateType aDate)
{
	// Pre: self and aDate have been initialized.

	// Compare self and aDate and return appropriate integer:
	//   LESS, if self comes before aDate
	//   GREATER, if self comes after aDate
	//   EQUAL, if self and aDate are equal

	// Check the precedence for years, months, and days.
	// If it passes through all six conditions, then the two dates are EQUAL.

	if (year < aDate.year)
		return LESS;		// Return values are defined in preprocessor directive
	else if (year > aDate.year)
		return GREATER;
	else if (month < aDate.month)
		return LESS;
	else if (month > aDate.month)
		return GREATER;
	else if (day < aDate.day)
		return LESS;
	else if (day > aDate.day)
		return GREATER;
	else
		return EQUAL;		// Else the two dates are equal

	/* Example 1: 5/4/2000 and 6/1/2000

	If the months are mismatched, then there is no need to test any
	further (into the days) because months are greater than days.

	Example 2: 4/20/2000 and 7/18/1975

	Likewise, if the years are mismatched, then there is no need to test
	the months and days because years take precedence over months and days.
	This was the spirit in which I ordered the above if statements.	*/
}

int DateType::ComparedCentury(DateType aDate)
{
	// Pre: self and aDate have been initialized.

	int cen1, cen2;

	// Divide the year and store the integer in century variable
	cen1 = year / 100;
	cen2 = aDate.year / 100;

	/* The following is to make the final year in a century calculate correctly.
	For example: 1969 and 2000 are in the same century, but without this modulus
	division check here, 2000 gets considered as part of the next century. This code
	makes it so that all round years at the end of the centuries get subtracted one
	so they figure into the correct century. */

	if (year % 100 == 0)					// If no remainders (meaning a round year at the end of century)
		cen1 -= 1;							// subtract 1 from cen1 and store in cen1
	if (aDate.year % 100 == 0)
		cen2 -= 1;

	/* 'else if' doesn't work here because both years have to be tested.
	For example: If the first year is 2000 and the next year is 1900,
	'if/else if' would consider these to be in the same century since it
	executes the first if statement and doesn't bother with the next one.
	So each must be tested separately in the case of two remainder-free years. */

	/* Return LESS, if the object itself comes before the century of aDate.
	Return EQUAL, if the object itself is in the same century as aDate.
	Return GREATER, if the object itself comes after the century of aDate. */

	if (cen1 < cen2)
		return LESS;
	else if (cen1 > cen2)
		return GREATER;
	else
		return EQUAL;
}

bool DateType::IsLeapYear(int newYear)
{
	// Method to test for leap year
	// Returns true if conditions for leap year are met
	// Returns false otherwise

	if ((newYear % 4 == 0 && newYear % 100 != 0) || (newYear % 400 == 0))
		return true;
	return false;
}

bool DateType::IsValidDate(int newMonth, int newDay, int newYear)
{
	// Checking for negative year values
	if (newYear < 1)
		return false;

	// Checking for correct number of days in each month
	switch (newMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (newDay < 1 || newDay > 31)		// Checking the 31-day months
			return false;
		break;
		// I'd forgotten to put the breaks here so valid dates like 5/31/2000 were
		// returning false. I was like, "Whhhhhaaaaat is going on?" Hahaha...
	case 4:
	case 6:
	case 9:
	case 11:
		if (newDay < 1 || newDay > 30)		// Checking the 30-day months
			return false;
		break;
	case 2:
		if (IsLeapYear(newYear) && (newDay < 1 || newDay > 29))		// If it's a leap year and day is less than 1 and greater than 29
			return false;											// Return false to calling function
		else if (IsLeapYear(newYear) == false && (newDay < 1 || newDay > 28))							// Checking for correct number of days in a non-leap year February
			return false;
		break;
	default:								// Default catches all months outside 1-12 range
		return false;
	}
	return true;								// If the date passes all triggers, returns true because it is a valid date
}

void DateType::AdvanceDays(int numDays)
{
	// This loop is for advancing using positive numDays.
	for (int i = 0; i < numDays; i++)
		IncrementDay();
	// I placed the actual implementation for incrementing and decrementing in separate
	// functions because they get used again in BackDays(), (cutting down on redundancies).

	// This loop is for regressing using negative numDays.
	for (int i = numDays; i < 0; i++)
		DecrementDay();
}

void DateType::IncrementDay()
{
	// If AdvanceDays(numDays), advances numDays into future.
	// If BackDays(-numDays), advances numDays into future.

	switch (month)
	{
	case 2:
		if (IsLeapYear(year) && day == 29)	// If it is a leap year and days for Feb equivalent to 29
		{
			month++;						// Increment into March
			day = 0;						// Day reset to 0
		}
		else if (IsLeapYear(year) == false && day == 28)		// If not a leap year and days for Feb equivalent to 28
		{
			month++;						// Increment into March
			day = 0;						// Day reset to 0
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (day == 30)						// For months that have 30 days
		{									// When 30-day limit is reached
			month++;						// Increment into next month
			day = 0;						// Reset day to 0
		}
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day == 31 && month == 12)		// This one is specifically for December
		{
			year++;							// Year increments as we pass from 12/31 into 1/1
			month = 1;						// Month reset
			day = 0;

			// The days here are all assigned 1 less because day is automatically incremented at the
			// bottom of this code segment before the for loop in calling function repeats.
			// In other words, to keep misdates like 3/32 from happening, I subtracted one more
			// from 'day' so that the increment at the end doesn't over-add to the tail-end dates.
		}
		else if (day == 31)					// This one is for non-December months that have 31 days
		{									// When day is equivalent to 31
			month++;						// Increment month
			day = 0;						// Reset day to 0
		}
	default:								// We don't have to use breaks to prevent cases from trickling down
		day++;								// if we order the cases like so, testing February first.
	}
}

void DateType::DecrementDay()
{
	// If AdvanceDays(-numDays), regresses numDays into past.
	// If BackDays(numDays), regresses numDays into past.

	// The reason why I used 'if/else if' here instead of the switch is because
	// all the conditions for decrementing hinge on day being equivalent to 1,
	// and so it seemed more convenient to place all subconditions underneath the
	// "if (day == 1)" umbrella.

	if (day == 1)
	{
		if (month == 1)
		{
			year--;
			month = 12;
			day = 31;
		}
		else if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			month--;
			day = 30;
		}
		else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
		{
			// August (8) is part of this 'else if' block, because July (7) is also
			// a 31-day month. So in order to give 31 days to July when regressing
			// from August, August needs to be part of this group.

			month--;
			day = 31;
		}
		else if (month == 3 && IsLeapYear(year))
		{
			month--;
			day = 29;
		}
		else if (month == 3 && IsLeapYear(year) == false)
		{
			month--;
			day = 28;
		}
	}
	else
		day--;			// Decrement day

	// Upside to implementing it using 'if/else if' instead of switch:
	// No need to watch for double decrementing

	// I was trying to decide between the switch and the if/else if (as in which method looks
	// cleaner and more readable for the viewer), and then I ended up using both ('switch' for advancing,
	// 'if/else if' for regressing). It was really convenient too, because both the increment and
	// decrement methods are exactly the same for BackDays(). All I had to do was switch which one goes
	// into the different loops.
}

void DateType::BackDays(int numDays)
{
	// This loop is for regressing using positive numDays. Loop sets i to 0 and runs
	// as long as i is less than numDays.

	for (int i = 0; i < numDays; i++)
		DecrementDay();				// Same content as second 'for' loop in AdvanceDays()

	// This loop is for advancing using negative numDays. Loop sets i to numDays
	// and repeats as long as i is less than 0.

	for (int i = numDays; i < 0; i++)
		IncrementDay();				// Same content as first 'for' loop in AdvanceDays()
}

void DateType::SetRandomDate()
{
	year = rand() % 9999 + 1;		// Limited to 4-digit years from 1-9999
	month = rand() % 12 + 1;		// Random month from 1-12

	if (month == 2)
	{
		if (IsLeapYear(year))
			day = rand() % 29 + 1;	// If it is a leap year, random day from 1-29
		else
			day = rand() % 28 + 1;	// If not a leap year, random day from 1-28
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		day = rand() % 30 + 1;		// If 30-day month, random day from 1-30
	else
		day = rand() % 31 + 1;		// Else, random day from 1-31
}

bool DateType::operator> (const DateType & aDate)
{
	// If aDate is GREATER, return true. Else, return false.

	if (ComparedTo(aDate) == GREATER)		// Got the idea to use ComparedTo() instead of recreating all of the
		return true;						// comparisons for the relational operators from the professor's solutions.
	return false;							// Brilliant. Why didn't I see this before turning in #2? Well, using it for #5A so...
}

bool DateType::operator< (const DateType & aDate)
{
	// If aDate is LESS, return true. Else, return false.

	if (ComparedTo(aDate) == LESS)
		return true;
	return false;
}

bool DateType::operator== (const DateType & aDate)
{
	// If aDate is equivalent, return true.
	// Else, the two dates are not equivalent, so return false.

	if (ComparedTo(aDate) == EQUAL)
		return true;
	return false;
}

bool DateType::operator!= (const DateType & aDate)
{
	// If the years, months, or days are mismatched, return true.
	// Else, the two dates are equivalent, so return false.

	if (ComparedTo(aDate) != EQUAL)
		return true;
	return false;
}

bool DateType::operator>= (const DateType & aDate)
{
	// If aDate is greater than or equal, return true. Else, return false.

	if (ComparedTo(aDate) == GREATER || ComparedTo(aDate) == EQUAL)
		return true;
	return false;
}

bool DateType::operator<= (const DateType & aDate)
{
	// If aDate is less than or equal, return true. Else, return false.

	if (ComparedTo(aDate) == LESS || ComparedTo(aDate) == EQUAL)
		return true;
	return false;
}

int DateType::operator - (const DateType & aDate)
{
	// Define the arithmetic operator - such that it will calculate and return the
	// number of days to go from the DateType object aDate passed as the argument 
	// to this DateType object now performing this operation.

	// Create two DateType objects and load them with the two dates.
	DateType d1(month, day, year);
	DateType d2(aDate.month, aDate.day, aDate.year);

	// Didn't want to actually change the contents of d1 so I used a temp instead.
	DateType temp = d1;
	
	// Set i to 0. From here, we either decrement, increment, or stay 0.
	int i = 0;

	// The number returned should be positive if aDate records a date earlier
	// than that recorded in this date. The number returned should be negative
	// if aDate records a date later than that recorded in this date. The number
	// returned should be 0 if aDate records the same date as that recorded in this date.

	// So if (temp == d2) from the get-go, we never go into the loop and... (cont. on line 508)
	while (temp != d2)
	{
		if (temp < d2)
		{
			temp.IncrementDay();
			i--;					// Decrement counter i until temp == d2
		}
		else if (temp > d2)
		{
			temp.DecrementDay();
			i++;					// Increment counter i until temp == d2
		}
	}
	return i;						// (cont. from line 494) ...we return 0, meaning temp == d2.
}

DateType DateType::operator + (int numDays)
{
	// Define the arithmetic operator + such that it will return a separate
	// DateType object recording a date that is numDays into the future from
	// the DateType object performing this operation. Note that the date recorded
	// in the DateType object performing this operation remains unchanged.

	DateType d1(month, day, year);	// Load month, day, and year into d1 DateType object.
	DateType d2 = d1;				// This way, the date stored in d1 remains unchanged,
									// while the date in d2 does change.
	HANDLE hConsole;				// For console color output

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Did my implementation below a bit differently from the demo program.
	// If numDays is non-positive, program displays error message and asks
	// for another numDays (loops until positive value is received).

	while (numDays <= 0)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl
			<< setw(72) << " Error  ||  Value must be positive  ||  Try Again";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl << endl;

		cout << setw(32) << " Enter an integer i:";
		cin >> numDays;
		cout << setw(32) << " Let:" << "date2 = date1 + " << numDays << endl;	
	}

	// The following is how the demo program handles non-positive numDays inputs.
	// It produces an error msg and simply returns the d2 that was set with d1.
	// I placed it here in comments so I can show you I know how to do it, but
	// went with my own implementation (right above).

	/*if (numDays <= 0)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl
			<< " Error  ||  Non-positive numDays Detected";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		return d2;
	}*/

	d2.AdvanceDays(numDays);		// We call AdvanceDays for d2 DateType object and pass it numDays
	return d2;						// Return the incremented d2 object
}

DateType DateType::operator - (int & numDays)
{
	// Define the arithmetic operator - such that it will return a separate
	// DateType object recording a date that is numDays into the past from
	// the DateType object performing this operation. Note that the date recorded
	// in the DateType object performing this operation remains unchanged.
	
	DateType d1(month, day, year);	// Load month, day, and year into d1 DateType object
	DateType d2 = d1;				// Leaving d1 unchanged, but we can work with d2
	HANDLE hConsole;				// For console color output

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (numDays <= 0)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl
			<< setw(72) << " Error  ||  Value must be positive  ||  Try Again";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl << endl;

		cout << setw(32) << " Enter an integer i:";
		cin >> numDays;
		cout << setw(32) << " Let:" << "date2 = date1 - " << numDays << endl;
	}

	// The following is how the demo program handles non-positive numDays inputs.
	// It produces an error msg and simply returns the d2 that was set with d1.
	// I placed it here in comments so I can show you I know how to do it, but
	// went with my own implementation (right above).

	/*if (numDays <= 0)
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl
			<< " Error  ||  Non-positive numDays Detected";
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl;
		return d2;
	}*/

	d2.BackDays(numDays);					// We call BackDays for d2 DateType object and pass it numDays
	return d2;								// Return the decremented d2 object
}


/********************************************************************************
The following two new global functions are I/O operators for DateType. They are
NOT member functions in DateType, but are declared as friends so that they can
access the private data members of DateType objects for input and output.
********************************************************************************/

ostream & operator<< (ostream & output, const DateType & aDate)
{
	// Check whether output is a reference to cout or not.
	// If output is indeed a reference to cout, print out
	// day, month, year separated by '/'

	if (&output == &cout)
		output << aDate.month << '/' << aDate.day << '/' << aDate.year;
	else
		output << aDate.month << ' ' << aDate.day << ' ' << aDate.year;

	// If output is NOT a reference to cout, it is a reference
	// to an ostream object for file output, so simply
	// write out day, month, year separated by ' '
	return output;
}

istream & operator>> (istream & input, DateType & aDate)
{
	// Check whether input is a reference to cin or not.
	// If input is indeed a reference to cin, simply call
	// the ReadDate method to prompt the user with messages
	// on the screen to enter day, month, year separately from
	// the keyboard, which will check and ensure the validity of date.

	if (&input == &cin)
		aDate.ReadDate();
	else
	{
		int temp_month,
			temp_day,
			temp_year;

		// If input is NOT a reference to cin, it is a reference to an
		// istream object for file input so read the information of day,
		// month, and year into some local variables declared through input
		// without prompting the user.

		input >> temp_month >> temp_day >> temp_year;

		// Then check whether they compose a valid date.
		// If they do, update the day, month, and year in aDate.
		// If not, keep the day, month, and year in aDate unchanged.

		if (aDate.IsValidDate(temp_month, temp_day, temp_year))
		{
			aDate.month = temp_month;
			aDate.day = temp_day;
			aDate.year = temp_year;
		}
	}
	return input;
}