// File: DateTest.cpp

#include <iostream>
#include <iomanip>
#include "DateType.h"
using namespace std;

void main()
{
	bool inMenu = true;				// While the user is using the program, this var is set to true and the menu keeps looping.
									// When the user wants to quit, it is set to false and the loop ends.
	char keyPressed;				// This var stores which menu selection the user picks.

	while (inMenu)
	{
		cout << left << endl;		// Left-alignment used for all setw() moving forward
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(15) << "" << "MENU: (press a character to select an option)" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(20) << " Q. [QUIT]" << "Quit program" << endl;
		cout << setw(20) << " C. [Constructor]" << "Test the default constructor and more" << endl;
		cout << setw(20) << " S. [Set]" << "Test the other constructor and the SetDate method" << endl;
		cout << setw(20) << " R. [Read date]" << "Test the ReadDate, ComparedTo, and ComparedCentury methods" << endl << endl;

		cout << setw(20) << " A. [Advance date]" << "Test the AdvanceDate method" << endl;
		cout << setw(20) << " B. [Back date]" << "Test the BackDate method" << endl;
		cout << setw(20) << " T. [Test]" << "Test further how well the date moves back" << endl;
		cout << "-------------------------------------------------------------------------------" << endl << endl;

		cout << setw(20) << " Your choice is:";
		cin >> keyPressed;

		// Two DateType objects to be tested
		DateType taxDay;							// Declared and constructed by the default constructor
		
		// I changed the arguments to the second constructor to: 1, 1, 2000
		// in place of the original: 12, 28, 2001
		// so that... (continued on DateTest.cpp, line 89)
		DateType groundHogDay(1, 1, 2000);			// Declared and constructed by the second constructor

		// Some more objects and variables for testing in the code below
		DateType AdvancedDate;
		DateType BackDate;
		int numDays;
		int ddd;
		char chr;

		DateType x;

		switch (keyPressed)
		{
			case 'Q':
			case 'q': // Quit
				cout << endl << " Program Terminated || Goodbye!" << endl;
				inMenu = false;
				break;

			case 'C':
			case 'c':
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 1: test taxDay, a DateType object declared in the main function, to" << endl
					<< setw(9) << " " << "see how the default constructor, and YearIs(), MonthIs(), DayIs()," << endl
					<< setw(9) << " " << "and the PrintDate() methods work on taxDay" << endl
					<< "-------------------------------------------------------------------------------" << endl;
				cout << "_______________________________________________________________________________" << endl << endl;

				// Testing the default constructor by using it to initialize taxDay
				cout << " taxDay is initialized by the default constructor method:" << endl;
				cout << setw(20) << " taxDay: year is " << taxDay.YearIs() << endl;
				cout << setw(20) << " taxDay: day is " << taxDay.DayIs() << endl;
				cout << setw(20) << " taxDay: month is " << taxDay.MonthIs() << endl << endl;

				cout << " PrintDate method prints the contents of taxDay as:" << endl;
				cout << " ";
				taxDay.PrintDate();								// Contents of taxDay printed to console output
				cout << endl << "_______________________________________________________________________________" << endl << endl;
				
				break;

			case 'S':
			case 's':
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 2: test the second constructor, SetDate(), and the PrintDate() method" << endl
					<< "-------------------------------------------------------------------------------" << endl;
				cout << "_______________________________________________________________________________" << endl << endl;

				// Testing the second constructor by using it to initialize groundHogDay
				cout << " groundHogDay is initialized by the second constructor:" << endl		// (continued from DateTest.cpp, lines 36-8)
					<< " groundHogDay(1, 1, 2000)" << endl		// ...so that it can match the date shown in this cout label.
					<< setw(20) << " The result is:";			
					groundHogDay.PrintDate();					// Prints date stored in groundHogDay to console output

				groundHogDay.SetDate(8, 8, 2005);				// groundHogDay is reset to 8, 8, 2005 using the SetDate() method
				cout << endl << endl
					<< " groundHogDay is reset now:"<< endl
					<< " groundHogDay.SetDate(8, 8, 2005)" << endl
					<< setw(20) << " The result is:";
				groundHogDay.PrintDate();						// Prints the new groundHogDay to console output
				cout << endl << "_______________________________________________________________________________" << endl << endl;

				break;

			case 'R':
			case 'r': // 3.
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 3: test ReadDate(), ComparedTo(), and ComparedCentury() methods" << endl
					<< "-------------------------------------------------------------------------------" << endl << endl;

				cout << " Get a new groundHogDay!" << endl;
				groundHogDay.ReadDate();						// Takes in user input (month, day, and year) into the DateType object

				cout << endl
					<< "_______________________________________________________________________________" << endl << endl;
				cout << setw(20) << " New groundHogDay:";
				groundHogDay.PrintDate();						// Prints date stored in DateType object to console output

				cout << endl << "_______________________________________________________________________________" << endl << endl;

				cout << " Get a new taxDay!" << endl;
				taxDay.ReadDate();

				cout << endl
					<< "_______________________________________________________________________________" << endl << endl;
				cout << setw(20) << " New taxDay:";
				taxDay.PrintDate();

				// The following line of code is for debugging, and causes -1, 0, 1 output:
				// cout << taxDay.ComparedTo(groundHogDay) << endl;

				cout << endl << "_______________________________________________________________________________" << endl << endl;

				cout << "_______________________________________________________________________________" << endl << endl;

				// Passing in groundHogDay to compare to taxDay
				if (taxDay.ComparedTo(groundHogDay) == LESS)
					cout << " taxDay is less than groundHogDay" << endl;		// Executes if comparison returns LESS
				else if (taxDay.ComparedTo(groundHogDay) == EQUAL)
					cout << " taxDay is equal to groundHogDay" << endl;			// Executes if comparison returns EQUAL
				else
					cout << " taxDay is greater than groundHogDay" << endl;		// Executes if comparison returns GREATER

				// Passing in taxDay to compare to groundHogDay
				if (groundHogDay.ComparedTo(taxDay) == LESS)
					cout << " groundHogDay is less than taxDay" << endl;
				else if (groundHogDay.ComparedTo(taxDay) == EQUAL)
					cout << " groundHogDay is equal to taxDay" << endl;
				else
					cout << " groundHogDay is greater than taxDay" << endl;		

				// Passing in taxDay to compare to groundHogDay
				if (groundHogDay.ComparedCentury(taxDay) == LESS)
					cout << " groundHogDay is in an earlier century" << endl;	// Executes if groundHogDay year is in an earlier century than taxDay year
				else if (groundHogDay.ComparedCentury(taxDay) == EQUAL)			// Executes if groundHogDay year and taxDay year are in the same century span
					cout << " groundHogDay and taxDay are in the same century" << endl;
				else
					cout << " groundHogDay is in a later century" << endl;		// Executes if groundHogDay year is in a later century than taxDay year
				cout << "_______________________________________________________________________________" << endl << endl;

				break;

			case 'A':
			case 'a': // 4. Advances the day numDays into the future
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 4: test the AdvanceDays() method" << endl
					<< "-------------------------------------------------------------------------------" << endl;

				cout << endl
					<< " Set the initial date:" << endl;
				AdvancedDate.ReadDate();				// Calling ReadDate() method to check the date in AdvancedDate object

				cout << endl
					<< "_______________________________________________________________________________" << endl << endl;
				cout << setw(20) << " Initial Date:";
				AdvancedDate.PrintDate();				// Calling PrintDate() method to print date in AdvancedDate to console
				cout << endl << "_______________________________________________________________________________" << endl;
				cout << endl << endl
					<< " How many days to advance into the future?" << endl;
				cout << setw(20) << " Advance the date:";
				cin >> numDays;
				AdvancedDate.AdvanceDays(numDays);		// Calling AdvanceDays() method and passing it numDays to advance the date in
				cout << endl;							// AdvancedDate object numDays times

				cout << "_______________________________________________________________________________" << endl << endl;
				cout << setw(20) << " The new date is:";
				AdvancedDate.PrintDate();				// Print out the new date
				cout << endl << "_______________________________________________________________________________" << endl << endl;

				break;

			case 'B':
			case 'b': // 5.
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 5: test the BackDays() method " << endl
					<< "-------------------------------------------------------------------------------" << endl;

				cout << endl << " Set the initial date:" << endl;
				AdvancedDate.ReadDate();
				cout << endl
					<< "_______________________________________________________________________________" << endl << endl;
				cout << setw(20) << " Initial Date:";
				AdvancedDate.PrintDate();
				cout << endl << "_______________________________________________________________________________" << endl;
				cout << endl << endl
					<< " How many days to set back into the past?" << endl;
				cout << setw(20) << " Regress the date:";
				cin >> numDays;							// Receive numDays from user
				AdvancedDate.BackDays(numDays);			// Calling BackDays() method and passing it numDays to regress the date in
				cout << endl							// AdvancedDate object numDays times
					<< "_______________________________________________________________________________" << endl << endl
					<< setw(20) << " The new date is:";
				AdvancedDate.PrintDate();				// Print regressed date to console output
				cout << endl << "_______________________________________________________________________________" << endl << endl;

				break;

			case 'T':
			case 't': // 6. 
				cout << endl
					<< "-------------------------------------------------------------------------------" << endl
					<< " Test 6: Check the BackDays() method 365 times and verify that it can" << endl
					<< setw(9) << " " << "correctly set Feb 14, 2007 back into Feb 14, 2006." << endl
					<< "-------------------------------------------------------------------------------" << endl;

				x.SetDate(2,14,2007);								// SetDate() in x object to 2/14/2007
				cout << endl;
				cout << "_______________________________________________________________________________" << endl << endl;
				cout << " ";
				x.PrintDate();										// PrintDate() stored in x object
				cout << endl << endl;

				ddd = 0;

				// Back to Jan, 14, 2007
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);									// Move back one day with each loop iteration
					cout << " ";
					x.PrintDate();									// Print the new date
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;

				ddd += 31;											// Incrementing and keeping track of the days for final output to console

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')									// I added in the while loop checks. Not that it was really needed, but
				{													// so long as the directions say to enter c, I felt it shouldn't allow
					cout << setw(25) << " Enter c to continue:";	// other characters to be able to continue the program.
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Dec, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Nov, 14, 2006
				for (int i = 0; i < 30; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 30;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Oct, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Sept, 14, 2006
				for (int i = 0; i < 30; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 30;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Aug, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to July, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to June, 14, 2006
				for (int i = 0; i < 30; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 30;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to May, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to April, 14, 2006
				for (int i = 0; i < 30; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 30;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to March, 14, 2006
				for (int i = 0; i < 31; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 31;

				cout << setw(25) << " Enter c to continue:";
				cin >> chr;
				while (chr != 'c')
				{
					cout << setw(25) << " Enter c to continue:";
					cin >> chr;
				}

				cout << "_______________________________________________________________________________" << endl << endl;
				// Back to Feb, 14, 2006
				for (int i = 0; i < 28; i++)
				{
					x.BackDays(1);
					cout << " ";
					x.PrintDate();
					cout << endl << endl;
				}
				cout << "_______________________________________________________________________________" << endl << endl;
				ddd += 28;

				cout << "_______________________________________________________________________________" << endl << endl;
				cout << " " << ddd << setw(36) << " days back from Feb 14, 2007 is:";		// Total number of days regressed (ddd) printed to output console
				x.PrintDate();																// PrintDate() in x after 365 (ddd) days
				cout << endl;
				cout << "_______________________________________________________________________________" << endl << endl;

				break;

			default:
				cout << endl
					<< " Unknown Command || Try Again" << endl;
				// Unrecognized key, do nothing
				break;
		}
	} // End of while loop
}