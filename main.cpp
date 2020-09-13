// File: main.cpp

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "DateType.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	HANDLE hConsole;            // For console color output

	bool inMenu = true;         // While the user is using the program, this var is set to true 
	// and the menu keeps looping. When the user wants to quit,
	// it is set to false and the loop ends.

	char keyPressed;            // This var stores which menu selection the user picks.

	int numDateRecords = 0;
	ifstream fin;
	ofstream fout;
	string filename;
	List dateDB;
	DateType date, dBegin, dEnd;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     // For console color output

	while (inMenu)
	{
		cout << left << endl << endl;
		cout << "________________________________________________________________________" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << setw(12) << "" << "MENU: (press a character to select an option)" << endl;
		cout << "------------------------------------------------------------------------" << endl << endl;

		cout << setw(5) << "" << setw(5) << "K." << "Key in a date into proper location in the list" << endl;
		cout << setw(5) << "" << setw(5) << "B." << "Batch of dates read from a file into an empty list" << endl << endl;

		cout << setw(5) << "" << setw(5) << "D." << "Display the dates stored in the list" << endl;
		cout << setw(5) << "" << setw(5) << "M." << "Modify a date in the list" << endl << endl;

		cout << setw(5) << "" << setw(5) << "W." << "Write the dates in the list to an output file" << endl;
		cout << setw(5) << "" << setw(5) << "F." << "Find and display the dates within a specified range" << endl << endl;

		cout << setw(5) << "" << setw(5) << "Q." << "Quit the program" << endl << endl;

		cout << "________________________________________________________________________" << endl;
		cout << "------------------------------------------------------------------------" << endl << endl;

		cout << setw(36) << " Your choice is:";
		cin >> keyPressed;

		switch (keyPressed)
		{
		case 'K':
		case 'k':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "K" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Read in a date manually keyed in by the user and store it in the proper" << endl
				<< " location in the linked list" << endl
				<< "------------------------------------------------------------------------" << endl;

			cin >> date;						// Receive a date from user
			dateDB.InsertInOrder(date);			// Insert that date into the proper location in list

			cout << endl
				<< " " << date << " inserted into the list" << endl
				<< " Enter 'D' to view";

			break;
		}
		case 'B':
		case 'b':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "B" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Clear list and read a batch of dates from a file specified by the" << endl
				<< " user into the newly emptied list" << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< setw(36) << " Enter filename:";
			cin >> filename;								// Receive filename from user

			fin.open(filename);								// Opening input file stream

			while (fin.fail())								// Loop to check to check that the file exists
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << endl
					<< setw(18) << "" << " File does not exist  ||  Check filename and try again" << endl << endl;
				SetConsoleTextAttribute(hConsole, 7);

				cout << setw(36) << " Enter filename:";		// Asking for filename re-entry
				cin >> filename;
				fin.open(filename);
			}
			fin >> numDateRecords;							// First number is the number of records to import

			if (numDateRecords < 0)							// Executes if numDateRecords is a negative value
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << endl
					<< setw(14) << "" << "Operation aborted  ||  numDateRecords must be non-negative";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if (numDateRecords == 0)					// Executes if numDateRecords is 0
			{
				cout << endl
					<< " Nothing to insert into list :(";
			}
			else											// Executes if numDateRecords is positive
			{
				dateDB.Clear();								// Empty out the list

				for (int i = 0; i < numDateRecords; i++)
				{
					fin >> date;							// Read in the date
					dateDB.InsertInOrder(date);				// Insert the date into the proper location in the list
				}
				cout << endl
					<< " " << numDateRecords << " dates have been inserted into the list" << endl
					<< " Enter 'D' to view";
			}
			fin.close();                                    // Close input file stream

			break;
		}
		case 'D':
		case 'd':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "D" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Display the dates currently stored in the list to output screen" << endl
				<< "------------------------------------------------------------------------" << endl;

			if (dateDB.Size() > 0)							// Executes if size of list is non-negative
				dateDB.Display();							// Display list elements to console screen
			else
			{
				cout << endl
					<< " List contains the following " << dateDB.Size() << " dates:" << endl
					<< "  Nothing :(" << endl;				// Else, list is empty so display following message
			}
			break;
		}
		case 'M':
		case 'm':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "M";
			SetConsoleTextAttribute(hConsole, 7);
			cout << endl
				<< "------------------------------------------------------------------------" << endl
				<< " Modify a date by reading in a new date from the keyboard to overwrite" << endl
				<< " the contents of an existing DateType object in the list" << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< setw(25) << "" << " Date Item to Modify" << endl;
			cin >> date;										// Date to modify
			
			if (dateDB.Search(date))							// If the search turns up a matching date
			{
				dateDB.Remove(date);							// Remove that date

				cout << endl
					<< setw(28) << "" << " New Date Item" << endl;
				cin >> date;									// Enter new date to add to list
				dateDB.InsertInOrder(date);						// Call InsertInOrder() to insert date in proper location in list

				cout << endl
					<< " The specified date has been modified successfully" << endl
					<< " Enter 'D' to view";
			}
			else
			{													// Else, specified date is not in list, so output error msg
				SetConsoleTextAttribute(hConsole, 14);
				cout << endl
					<< setw(20) << "" << date << " not in list  ||  Verify input and try again";
				SetConsoleTextAttribute(hConsole, 7);
			}

			break;
		}
		case 'W':
		case 'w':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "W" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Write the dates currently stored in the list to a user-specified" << endl
				<< " output file (filename must be less than 20 characters)" << endl
				<< "------------------------------------------------------------------------" << endl << endl;

			cout << setw(36) << " Specify output filename:";
			cin >> filename;									// Enter filename

			while (filename.length() >= 20)						// Just following what the specs say about the filename having to be less than 20 characters
			{
				cout << endl;
				SetConsoleTextAttribute(hConsole, 14);
				cout << setw(31) << "" << " Filename must be less than 20 characters" << endl << endl;
				SetConsoleTextAttribute(hConsole, 7);
				cout << setw(36) << " Specify output filename:";
				cin >> filename;
			}
			fout.open(filename);								// Open file
			fout << dateDB << endl;								// Output size of list and dates in list to output file
			fout.close();										// Close output file stream

			cout << endl
				<< " List elements successfully written to output file" << endl
				<< " Open " << filename << " to view";

			break;
		}
		case 'F':
		case 'f':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "F" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Find and display the dates within a specified range" << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< setw(30) << "" << "Beginning Date" << endl;
			cin >> dBegin;										// Enter beginning date for find

			cout << endl
				<< setw(31) << "" << "Ending Date" << endl;
			cin >> dEnd;										// Enter ending date for find

			cout << endl
				<< " The following dates fall within the specified range:" << endl;

			dateDB.FindAndDisplay(dBegin, dEnd);				// Call FindAndDisplay() to find all dates between dBegin and dEnd

			break;
		}
		case 'Q':												// Terminate program
		case 'q':
		{
			cout << endl
				<< " Program Terminated  ||  Thank You!" << endl << endl;
			inMenu = false;

			break;
		}
		default:
			cout << endl;
			SetConsoleTextAttribute(hConsole, 14);
			cout << setw(35) << "" << "Unknown Command  ||  Please Try Again";    // Unrecognized key, do nothing
			SetConsoleTextAttribute(hConsole, 7);

			break;
		}
	}
	return 0;
}