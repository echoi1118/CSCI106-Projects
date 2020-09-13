#include "DateType.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <windows.h>

int main()
{
	// Setting the seed for the random function
	srand((unsigned int)time(NULL));

	HANDLE hConsole;			// For console color output
	DateType date1, date2;		// Two DateType objects for testing
	ofstream fout;				// For file output
	ifstream fin;				// For file input
	char fileName[50];			// For storing the file name
	int i;						// For storing integers
	
	bool inMenu = true;			// While the user is using the program, this var is set to true 
								// and the menu keeps looping. When the user wants to quit,
								// it is set to false and the loop ends.

	char keyPressed;			// This var stores which menu selection the user picks.
	
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		// For console color output

	while (inMenu)
	{
		cout << left << endl << endl;
		cout << "________________________________________________________________________" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << setw(12) << "" << "MENU: (press a character to select an option)" << endl;
		cout << "------------------------------------------------------------------------" << endl << endl;
		cout << setw(32) << " Q. [QUIT]" << "Quit" << endl;
		cout << endl;

		cout << setw(32) << " S. [Set Random Dates]" << "Test the SetRandomDate method" << endl;
		cout << endl;

		cout << setw(32) << " R. [Relational Operators]" << "Test all the relational operators" << endl;
		cout << setw(32) << " A. [Arithmetic Operators]" << "Test all the arithmetic operators" << endl;
		cout << endl;

		cout << setw(32) << " C. [Console Input / Output]" << "Test \"cout << date\" and \"cin >> date\" " << endl;
		cout << setw(32) << " F. [File Input / Output]" << "Test \"fout << date\" and \"fin >> date\" " << endl << endl;

		cout << "________________________________________________________________________" << endl;
		cout << "------------------------------------------------------------------------" << endl << endl;

		cout << setw(32) << " Your choice is:";
		cin >> keyPressed;

		switch(keyPressed)
		{
		case 'Q':
		case 'q': // Quit
			cout << endl
				<< " QUIT  ||  Program Terminated  ||  See ya later!" << endl << endl;
			inMenu = false;
			break;

		case 'S':
		case 's':
			cout << endl
				<< "------------------------------------------------------------------------" << endl
				<< " Test 1: Call date1, a DateType object declared in the main function," << endl
				<< setw(9) << "" << "to perform the SetRandomDate method 10 times to generate 10" << endl
				<< setw(9) << "" << "random dates." << endl
				<< "------------------------------------------------------------------------" << endl;

			for (i = 0; i < 10; i++)
			{
				date1.SetRandomDate();
				cout << endl
					<< setw(32) << " Set a new random date:";
				date1.PrintDate();
			}

			cout << endl << endl
				<< "------------------------------------------------------------------------" << endl
				<< setw(15) << "" << "Do the dates above really look random? " << endl
				<< "------------------------------------------------------------------------" << endl;

			break;

		case 'R':
		case 'r':
			cout << endl
				<< "------------------------------------------------------------------------" << endl
				<< " Test 2: Test all the relational operators on two DateType objects," << endl
				<< setw(9) << "" << "date1 and date2, declared in the main function." << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< "________________________________________________________________________" << endl << endl;
			SetConsoleTextAttribute(hConsole, 48);
			cout << setw(25) << "" << setw(72-25) << "Read a date into date1" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			date1.ReadDate();

			cout << endl;
			SetConsoleTextAttribute(hConsole, 48);
			cout << setw(25) << "" << setw(72-25) << "Read a date into date2" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			date2.ReadDate();
			cout << "________________________________________________________________________" << endl;

			cout << endl
				<< setw(32) << " Is (date1 > date2)?";			// > overloaded operator test
			if (date1 > date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << endl
				<< setw(32) << " Is (date1 < date2)?";			// < overloaded operator test
			if (date1 < date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << endl
				<< setw(32) << " Is (date1 == date2)?";			// == overloaded operator test
			if (date1 == date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << endl
				<< setw(32) << " Is (date1 != date2)?";			// != overloaded operator test
			if (date1 != date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << endl
				<< setw(32) << " Is (date1 >= date2)?";			// >= overloaded operator test
			if (date1 >= date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << endl
				<< setw(32) << " Is (date1 <= date2)?";			// <= overloaded operator test
			if (date1 <= date2)
				cout << setw(10) << "Yes" << "True" << endl;
			else
				cout << setw(10) << "No" << "False" << endl;

			cout << "________________________________________________________________________" << endl;

			break;

		case 'A':
		case 'a':
			cout << endl
				<< "------------------------------------------------------------------------" << endl
				<< " Test 3: Test all the arithmetic operators on two DateType objects," << endl
				<< setw(9) << "" << "date1 and date2, declared in the main function." << endl
				<< "------------------------------------------------------------------------" << endl;

			cout << endl
				<< "________________________________________________________________________" << endl << endl;
			SetConsoleTextAttribute(hConsole, 48);
			cout << setw(25) << "" << setw(47) << "Read a date into date1" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			date1.ReadDate();

			cout << endl;
			SetConsoleTextAttribute(hConsole, 48);
			cout << setw(25) << "" << setw(47) << "Read a date into date2" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			date2.ReadDate();
			cout << "________________________________________________________________________" << endl;

			cout << endl
				<< setw(32) << " Test the result of:" << "date1 - date2" << endl;				// - overloaded operator test
			cout << setw(32) << " (date1 - date2) equals:" << date1 - date2 << endl;
			cout << "________________________________________________________________________" << endl;
		    
			cout << endl
				<< setw(32) << " Test the result of:" << "date2 = date1 - i" << endl;			// - overloaded operator test
			cout << setw(32) << " Enter an integer i:";
			cin >> i;
			
			cout << setw(32) << " Let:" << "date2 = date1 - " << i << endl;
			date2 = date1 - i;

			cout << endl
				<< " After \"date2 = date1 - i\":" << endl;

			// Here, date1 needs to remain unchanged
			cout << setw(32) << "  date1 is:";
			date1.PrintDate();
			
			// The result in date2 after performing date1 - i
			cout << endl
				<< setw(32) << "  date2 is:";
			date2.PrintDate();

			cout << endl
				<< "________________________________________________________________________" << endl;
		    
			cout << endl
				<< setw(32) << " Test the result of:" << "date2 = date1 + i" << endl;			// + overloaded operator test
			cout << setw(32) << " Enter an integer i:";
			cin >> i;
			
			cout << setw(32) << " Let:" << "date2 = date1 + " << i << endl;
			date2 = date1 + i;

			cout << endl
				<< " After \"date2 = date1 + i\":" << endl;

			// Here, date1 needs to remain unchanged
			cout << setw(32) << "  date1 is:";
			date1.PrintDate();
			
			// The result in date2 after performing date1 + i
			cout << endl
				<< setw(32) << "  date2 is:";
			date2.PrintDate();
			cout << endl
				<< "________________________________________________________________________" << endl;

			break;

		case 'C':
		case 'c': // 4.
			 cout << endl
				 << "------------------------------------------------------------------------" << endl
				 << " Test 4: Test \"cout << date\" and \"cin >> date\"" << endl
				 << "------------------------------------------------------------------------" << endl;

			 cout << endl
				 << "________________________________________________________________________" << endl << endl;
			SetConsoleTextAttribute(hConsole, 48);
			cout << setw(25) << "" << setw(47) << "Now do \"cin >> date1\" " << endl;
			SetConsoleTextAttribute(hConsole, 7);		// Have to change console color back each time after changing it.
														// Soo annoying, but it looks good so.
			cin >> date1;

			cout << endl
				 << " Result of \"cout << date1\" after doing \"cin >> date1\":" << endl;
			cout << "  ";
			cout << date1 << endl;
			cout << "________________________________________________________________________" << endl;

			break;

		case 'F':
		case 'f': // 5.

		 cout << endl
			 << "------------------------------------------------------------------------" << endl
			 << " Test 5: Test \"fout << date\" and \"fin >> date\" where fout is an ofstream" << endl
			 << setw(9) << "" << "object for file output, and fin is an ifstream object for file" << endl
			 << setw(9) << "" << "input." << endl
			 << "------------------------------------------------------------------------" << endl;

		 cout << "________________________________________________________________________" << endl << endl;
		 SetConsoleTextAttribute(hConsole, 48);
		 cout << setw(20) << "" << setw(52) << "Input a date to store into date1" << endl;
		 SetConsoleTextAttribute(hConsole, 7);
			cin >> date1;				// Date input

		 cout << endl << endl
			 << " Input file name and store date1 into file:" << endl
			 << "  ";
			cin >> fileName;			// User-defined fileName to store date input

			cout << "________________________________________________________________________" << endl << endl;
			SetConsoleTextAttribute(hConsole, 14);
			cout << " Opening file... \"fout.open(" << fileName << ")\"" << endl;
			fout.open(fileName);		// Open the user-defined file

			cout << endl
				<< " Storing date1 in " << fileName << "... \"fout << date1\"" << endl;
			fout << date1;				// Push out date1 to file
			fout.close();				// Close the file

			cout << endl
				<< " File input... \"fin.open(" << fileName << ")\"" << endl;
			fin.open(fileName);

			cout << endl
				<< " Read date back into date2... \"fin >> date2\"";
			SetConsoleTextAttribute(hConsole, 7);
			fin >> date2;				// Read what is in new file back in
			fin.close();

			cout << endl
				<< "________________________________________________________________________" << endl << endl
				<< " Result of \"cout << date2\" after doing \"fin >> date2\":" << endl
				<< "  ";
			cout << date2 << endl;
			cout << "________________________________________________________________________" << endl;

			break;

		default:
			cout << endl;
			SetConsoleTextAttribute(hConsole, 14);
			cout << " Unknown Command  ||  Please Try Again";
			SetConsoleTextAttribute(hConsole, 7);
			// Unrecognized key, do nothing
			break;
		}
	}
	return 0;
}
