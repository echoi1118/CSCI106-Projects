#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "DateType.h"
using namespace std;

bool mergeTwoSortedVectors(vector<DateType> & vecA, vector<DateType> & vecB, vector<DateType> & vecC);
void mergeSort(vector<DateType> & vecToSort);

int main()
{
	HANDLE hConsole;			// For console color output

	bool inMenu = true;         // While the user is using the program, this var is set to true 
								// and the menu keeps looping. When the user wants to quit,
								// it is set to false and the loop ends.

	char keyPressed;            // This var stores which menu selection the user picks.

	int numDateRecords = 0;
	ifstream fin;
	ofstream fout;
	string filename;
	DateType date, dBegin, dEnd;
	vector<DateType> dateDB;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		// For console color output
	
	while (inMenu)
	{
		cout << left << endl << endl;
		cout << "________________________________________________________________________" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << setw(12) << "" << "MENU: (press a character to select an option)" << endl;
		cout << "------------------------------------------------------------------------" << endl << endl;

		cout << setw(10) << " K." << "Key in a date into the end of vector" << endl;
		cout << setw(10) << " B." << "Batch of dates read from a file into an empty vector" << endl << endl;

		cout << setw(10) << " D." << "Display the dates stored in the vector" << endl;
		cout << setw(10) << " M." << "Modify an element in the vector" << endl << endl;

		cout << setw(10) << " W." << "Write the dates in the vector to an output file" << endl;
		cout << setw(10) << " F." << "Find and display the dates within a specified range" << endl;
		cout << setw(10) << " S." << "Sort the dates in the vector in ascending order" << endl << endl;

		cout << setw(10) << " Q." << "Quit the program" << endl << endl;

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
				<< " Read in a date manually keyed in by the user and store it at the end" << endl
				<< " of vector dateDB" << endl
				<< "------------------------------------------------------------------------" << endl;

			cin >> date;						// Receive a date from user
			dateDB.push_back(date);				// Push that date into dateDB vector
			numDateRecords++;					// Increment numDateRecords

			cout << endl
				<< " " << date << " pushed into the end of vector dateDB" << endl
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
				<< " Empty dateDB and read a batch of dates from a file specified by the" << endl
				<< " user into the newly emptied vector" << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< setw(36) << " Enter filename:";
			cin >> filename;								// Receive filename from user

			fin.open(filename);								// Opening input file stream

			while (fin.fail())								// Checking to make sure the file exists
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
					<< " Nothing to push into vector dateDB :(";
			}
			else											// Executes if numDateRecords is positive
			{
				dateDB.clear();								// Empty out the dateDB vector

				for (int i = 0; i < numDateRecords; i++)
				{
					fin >> date;							// Read in the date
					dateDB.push_back(date);					// Push it into the end of dateDB vector
				}
				cout << endl
					<< " " << numDateRecords << " dates have been pushed into the vector" << endl
					<< " Enter 'D' to view";
			}
			fin.close();									// Close input file stream

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
				<< " Display the dates currently stored in vector dateDB to the screen" << endl
				<< "------------------------------------------------------------------------" << endl;

			if (numDateRecords >= 0)
			{
				cout << endl													// This label displays when non-negative numDateRecords value
					<< " Vector contains the following " << numDateRecords << " dates:" << endl;
			}
			else
			{
				cout << endl
					<< " Vector contains the following dates:" << endl;			// This label is for the case that numDateRecords contains a negative value.
			}																	// Preventing the following --> "Vector contains the following -6 dates:"

			if (dateDB.size() > 0)							// Executes if size of vector is positive
			{
				for (int i = 0; i < dateDB.size(); i++)
					cout << "  " << dateDB[i] << endl;		// Display vector elements to console screen
			}
			else
				cout << "  Nothing :(" << endl;				// Else, vector is empty so display following message

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
				<< " the contents of an existing DateType object in the vector" << endl
				<< "------------------------------------------------------------------------" << endl;

			int i = 0;

			cout << endl
				<< setw(36) << " Enter index of item to modify:";
			cin >> i;

			if (i >= 0 && i < dateDB.size())
			{
				cin >> dateDB[i];							// Write into dateDB[i] if i exists (i.e. i is between 0 and size of vector)
				cout << endl
					<< " Item at index " << i << " modified successfully" << endl
					<< " Enter 'D' to view";
			}
			else
			{												// Else, i does not exist, so print out the following error msg
				SetConsoleTextAttribute(hConsole, 14);
				cout << endl
					<< setw(31) << "" << "Improper index  ||  Make sure item exists";
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
				<< " Write the dates currently stored in the vector to a user-specified" << endl
				<< " output file" << endl
				<< "------------------------------------------------------------------------" << endl << endl;

			cout << setw(36) << " Specify output filename:";
			cin >> filename;										// Enter filename
			fout.open(filename);									// Open file
			fout << dateDB.size() << endl;							// Output size of vector to output file

			for (int i = 0; i < dateDB.size(); i++)					// Output dates in vector to output file
				fout << dateDB[i] << endl;
			fout.close();											// Close output file stream

			cout << endl
				<< " Vector elements successfully written to output file" << endl
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
			cin >> dBegin;											// Enter beginning date for find

			cout << endl
				<< setw(31) << "" << "Ending Date" << endl;
			cin >> dEnd;											// Enter ending date for find

			cout << endl
				<< " The following dates fall within the specified range:" << endl;

			int count = 0;

			for (int i = 0; i < dateDB.size(); i++)
			{
				if ((dateDB[i] >= dBegin) && (dateDB[i] <= dEnd))	// If dateDB[i] is between dBegin and dEnd, display dateDB[i]
				{
					cout << "  " << dateDB[i] << endl;
					count++;
				}
			}

			if (count == 0)											// Displays if there are no dates that fall within the specified range
				cout << "  None :(";

			break;
		}
		case 'S':
		case 's':
		{
			cout << endl;
			SetConsoleTextAttribute(hConsole, 63);
			cout << setw(36) << "" << setw(36) << "S" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "------------------------------------------------------------------------" << endl
				<< " Sort the dates currently stored in vector dateDB" << endl
				<< "------------------------------------------------------------------------" << endl << endl;
			if (dateDB.size() > 0)
			{
				mergeSort(dateDB);									// Call mergeSort() function to sort the contents of dateDB
				cout << " Vector successfully sorted" << endl
					<< " Enter 'D' to view";
			}
			else
				cout << " Nothing to sort :(" << endl;				// Message displays if size of dateDB is 0

			break;
		}
		case 'Q':													// Terminate program
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
			cout << setw(35) << "" << "Unknown Command  ||  Please Try Again";	// Unrecognized key, do nothing
			SetConsoleTextAttribute(hConsole, 7);

			break;
		}
	}
	return 0;
}

bool mergeTwoSortedVectors(vector<DateType> & vecA, vector<DateType> & vecB, vector<DateType> & vecC)
{
	// Set and initialize counters for each vector
	int countA = 0, countB = 0, countC = 0;

	HANDLE hConsole;															// For console color output
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < (vecA.size() - 1); i++)									// Did it this way to keep vector from checking out-of-bounds.
	{
		if (vecA[i] > vecA[i + 1])
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << endl
				<< " >> ERROR: Vector 1 not in ascending order <<" << endl;		// Displays if values in first vector are not in ascending order
			SetConsoleTextAttribute(hConsole, 7);
			return false;														// Automatically return false if vector is unsorted
		}
	}

	for (int i = 0; i < (vecB.size() - 1); i++)
	{
		if (vecB[i] > vecB[i + 1])												// If value in vecB[i] is greater than value in vecB[i + 1] means vector is unsorted
		{																		// so display error message and return false
			SetConsoleTextAttribute(hConsole, 14);
			cout << endl
				<< " >> ERROR: Vector 2 not in ascending order <<" << endl;		// Displays if values in second vector are not in ascending order
			SetConsoleTextAttribute(hConsole, 7);
			return false;
		}
	}

	// Resize vecC to fit the contents of both vecA and vecB
	vecC.resize(vecA.size() + vecB.size());

	// Note that the following while loop continues until the contents of
	// either vecA or vecB have been completely copied over into vecC

	while ((countA < vecA.size()) && (countB < vecB.size()))
	{
		if (vecA[countA] <= vecB[countB])		// If what's in vecA is less than or equal to what's in vecB
		{
			vecC[countC] = vecA[countA];		// Copy that value in vecA into vecC
			countA++;							// Increment the counter for A
		}
		else									// Else, what's in vecA is greater than what's in vecB
		{
			vecC[countC] = vecB[countB];		// Copy that value in vecB into vecC
			countB++;							// Increment the counter for B
		}
		countC++;								// Increment the counter for C
	}

	// Only one of the following two loops will have to execute. The other will have
	// a counter that has reached the size of the vector (from the loop above) and
	// will never execute

	// If there are any elements left in vecA, copy them over to vecC
	while (countA < vecA.size())
	{
		vecC[countC] = vecA[countA];
		countA++;
		countC++;
	}

	// If any elements left in vecB, copy them over to vecC
	while (countB < vecB.size())
	{
		vecC[countC] = vecB[countB];
		countB++;
		countC++;
	}
	return true;
}

void mergeSort(vector<DateType> & vecToSort)
{
	// If the size of vecToSort is 1 or less, it is already sorted, so just return
	if (vecToSort.size() <= 1)
		return;
	else if (vecToSort.size() == 2)
	{
		// If the size of vecToSort is 2, compare the two elements in it and swap them if necessary, and then return

		if (vecToSort[1] < vecToSort[0])				// Only enters this statement if value in vecToSort[1] is less than value in [0]
		{
			DateType temp;								// Set up a temp variable and swap the orders of the two
			temp = vecToSort[0];
			vecToSort[0] = vecToSort[1];
			vecToSort[1] = temp;
		}
		return;
	}
	else
	{
		vector<DateType> vec1, vec2;
		int count = 0;

		// Otherwise, the size of vecToSort is at least 3. Use two separate vectors, vec1 and vec2 (as local objects),
		// resize them to the sizes vecToSort.size() / 2 and vecToSort.size() - vecToSort.size() / 2 respectively
		vec1.resize(vecToSort.size() / 2);
		vec2.resize(vecToSort.size() - vecToSort.size() / 2);

		// Copy the first vecToSort.size() / 2 elements in vecToSort into vec1 and the remaining
		// vecToSort.size() - vecToSort.size() / 2  into vec2
		for (int i = 0; i < vec1.size(); i++)
		{
			vec1[i] = vecToSort[i];
			count++;									// Do not reset counter here. Where it leaves off is where we start copying from for vec2.
		}
		for (int i = 0; i < vec2.size(); i++)
		{
			vec2[i] = vecToSort[count];
			count++;									// Continue to increment the counter
		}
		count = 0;										// Counter reset

		mergeSort(vec1);								// Call mergeSort(vec1) to sort the first vector
		mergeSort(vec2);								// Call mergeSort(vec2) to sort the second vector
		mergeTwoSortedVectors(vec1, vec2, vecToSort);	// Call mergeTwoSortedVectors(vec1, vec2, vecToSort) to merge the sorted vec1 and vec2 into vecToSort and make it one sorted vector
	}
}
