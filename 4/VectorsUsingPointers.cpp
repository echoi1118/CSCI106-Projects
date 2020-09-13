#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

bool mergeTwoSortedSeries(double * ptrA, int sizeOfA, double * ptrB, int sizeOfB, double * ptrC);
void mergeSort(double * ptrSeriesToSort, int sizeOfSeries);

int main()
{
	HANDLE hConsole;									// For console color output
	char chr;

	// Sizes of series A and series B
	int n1 = 0, n2 = 0;

	// Declare the three pointers and set them to nullptr
	double *ptrA = nullptr;
	double *ptrB = nullptr;
	double *ptrC = nullptr;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);			// For console color output

	cout << left << endl << endl;
	SetConsoleTextAttribute(hConsole, 47);
	cout << setw(15) << "" << setw(31) << "Merging Series" << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);

	cout << "______________________________________________" << endl;
	cout << " Please enter the sizes of the two series" << endl
		<< " (Enter negative series size to exit loop)" << endl
		<< setw(32) << "  Size of series 1:";
	cin >> n1;											// Input size for series A

	while (n1 >= 0)
	{
		cout << setw(32) << "  Size of series 2:";		// Check size of second series inside the while loop
		cin >> n2;										// Input size for series B
		cout << endl;

		// Break out of this loop if second series size is negative
		if (n2 < 0)
			break;
		
		// Dynamically allocate an array of doubles of size n1 and have ptrA point to it
		ptrA = new double[n1];

		// Asking for values to fill into series A if it is not empty
		if (n1 != 0)
		{
			cout << " Please enter values in the first series" << endl;

			for (int i = 0; i < n1; i++)									// Fill series A
			{
				cout << "  Element #" << (i + 1) << ": \t\t\t";
				cin >> ptrA[i];
			}
		}
		else
			cout << " Nothing to enter into the first series" << endl		// Displays if series A is empty
			<< "  Size of first series is " << n1 << endl;

		int n3 = n1 + n2;													// Set size for series C

		// Dynamically allocate an array of doubles of size n2 and n3 and have ptrB and ptrC, respectively, point to them
		ptrB = new double[n2];
		ptrC = new double[n3];

		// Asking for values to fill into series B if it is not empty
		if (n2 != 0)
		{
			cout << endl
				<< " Please enter values in the second series" << endl;

			for (int i = 0; i < n2; i++)									// Fill series B
			{
				cout << "  Element #" << (i + 1) << ": \t\t\t";
				cin >> ptrB[i];
			}
		}
		else
		{
			cout << endl
				<< " Nothing to enter into the second series" << endl		// Displays if series B is empty
				<< "  Size of second series is " << n2 << endl;
		}

		if ((mergeTwoSortedSeries(ptrA, n1, ptrB, n2, ptrC)))
		{
			cout << endl
				<< " The merged series contains: " << endl;

			if (n3 == 0)													// Checking for empty series
				cout << "  Nothing. The series is empty. :(" << endl;
			else
			{
				int k = 0;

				for (int i = 0; i < n3; i++)
				{
					if (k == 11)					// Purely for formatting purposes: Every time k reaches 11, newline so that
					{								// values don't continue to the right of the console screen. I know the console
						cout << endl;				// newlines it automatically eventually, but I don't like it newlining at the
						k = 0;						// edge of the console. Looks unpresentable.
					}
					k++;							// Increment k
					cout << "  " << *(ptrC + i);	// Display series C values
				}
				cout << endl;
			}
		}

		// Free dynamically allocated memory
		delete[] ptrA;
		delete[] ptrB;
		delete[] ptrC;
		
		// Book says it's good programming practice to do this upon deleting...
		ptrA = nullptr;
		ptrB = nullptr;
		ptrC = nullptr;

		cout << endl
			<< "______________________________________________" << endl
			<< " Please enter the sizes of the two series" << endl
			<< " (Enter negative series size to exit loop)" << endl;		// We exit the loop when n1 or n2 are given a negative value
		cout << setw(32) << "  Size of series 1:";
		cin >> n1;															// Input size for series A
	}

	int n = 0;
	double *ptrToSort = nullptr;

	cout << left << endl << endl;
	SetConsoleTextAttribute(hConsole, 47);
	cout << setw(15) << "" << setw(31) << "Series Sorting" << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);

	cout << "______________________________________________" << endl
		<< " Please enter the size of series to be sorted" << endl
		<< " (Enter negative series size to exit loop)" << endl
		<< setw(32) << "  Series size:";
	cin >> n;

	while (n >= 0)
	{
		// Dynamically allocate a chunk of memory storage that can hold n double values and have ptrToSort point to it
		ptrToSort = new double[n];

		if (n != 0)														// So that user sees the "Please enter the values..." label only if series size is not 0.
		{																// Because if series size is 0, there is no need for user to input anything at all.
			cout << endl
				<< " Please enter the values in the series" << endl;
			for (int i = 0; i < n; i++)									// cin values into the array until i reaches array size
			{
				cout << "  Element #" << i + 1 << ": \t\t\t";
				cin >> *(ptrToSort + i);								// Just trying out this way of doing it in place of ptrToSort[i]; works the same, but looks weird IMO.
			}
			mergeSort(ptrToSort, n);									// Calling the recursive function
		}

		cout << endl
			<< " The sorted series contains:" << endl;
		if (n == 0)
			cout << "  Nothing. Series is empty. :(" << endl;			// In the case of the array being empty
		else
		{
			int k = 0;

			for (int i = 0; i < n; i++)
			{
				if (k == 11)											// For formatting of the displaying of the values
				{
					cout << endl;										// So that program newlines after every 11 values
					k = 0;
				}
				k++;
				cout << "  " << *(ptrToSort + i);
			}

			// Free dynamically allocated memory
			delete[] ptrToSort;
			ptrToSort = nullptr;
			
			cout << endl;
		}
		cout << endl
			<< "______________________________________________" << endl
			<< " Please enter the size of series to be sorted " << endl
			<< " (Enter negative series size to exit loop)" << endl
			<< setw(32) << "  Series size:";
		cin >> n;
	}

	cout << endl
		<< "______________________________________________" << endl
		<< setw(32) << "  Enter x to quit:";
	cin >> chr;

	// Technically, user is being asked to input x to quit, so I made
	// it do that. Really though, I don't think it's that big a deal,
	// which is why the demo program didn't account for it and just allowed
	// any character to terminate the program.

	while (chr != 'x' && chr != 'X')
	{
		SetConsoleTextAttribute(hConsole, 14);
		cout << endl
			<< setw(10) << "" << " >> Invalid character << " << endl;	// Must enter x to quit
		SetConsoleTextAttribute(hConsole, 7);

		cout << endl
			<< "______________________________________________" << endl
			<< setw(32) << "  Enter x to quit:";
		cin >> chr;
	}
	return 0;
}

bool mergeTwoSortedSeries(double * ptrA, int sizeOfA, double * ptrB, int sizeOfB, double * ptrC)
{
	// Set and initialize counters for each series
	int countA = 0, countB = 0, countC = 0;

	HANDLE hConsole;															// For console color output
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// The following if statement was very redundant, but I spoke with the
	// professor and she said to just keep it in because it's in the specs,
	// and that it's good training to follow the specs (for when we're in the
	// industry), so I kept it. But I still say it's weird...

	if (sizeOfA < 0 || sizeOfB < 0)
		return false;

	for (int i = 1; i < sizeOfA; i++)
	{
		if (ptrA[i - 1] > ptrA[i])												// Did it this way to keep from checking out-of-bounds
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << endl
				<< " >> ERROR: Series 1 not in ascending order <<" << endl;		// Displays if values in first series are not in ascending order
			SetConsoleTextAttribute(hConsole, 7);

			return false;														// Automatically return false if series is unsorted
		}
	}

	for (int i = 1; i < sizeOfB; i++)
	{
		if (ptrB[i - 1] > ptrB[i])												// If value in ptrB[i - 1] is greater than value in ptrB[i] means series is unsorted
		{																		// so display error message and return false
			SetConsoleTextAttribute(hConsole, 14);
			cout << endl
				<< " >> ERROR: Series 2 not in ascending order <<" << endl;		// Displays if values in second series are not in ascending order
			SetConsoleTextAttribute(hConsole, 7);

			return false;
		}
	}

	// Note that the following while loop continues until the contents of
	// either series A or series B have been completely copied over into series C.

	while ((countA < sizeOfA) && (countB < sizeOfB))
	{
		if (ptrA[countA] <= ptrB[countB])		// If what's in series A is greater than or equal to what's in series B
		{
			ptrC[countC] = ptrA[countA];		// Copy that value in series A into series C
			countA++;							// Increment the counter for A
		}
		else if (ptrA[countA] > ptrB[countB])	// Else if what's in series A is greater than what's in series B
		{
			ptrC[countC] = ptrB[countB];		// Copy that value in series B into series C
			countB++;							// Increment the counter for B
		}
		countC++;								// Increment the counter for C
	}

	// Only one of the following two loops will have to execute. The other will have
	// a counter that has reached the size of the series (from the loop above) and
	// will never execute.

	// If there are any elements left in series A, copy them over to series C.
	while (countA < sizeOfA)
	{
		ptrC[countC] = ptrA[countA];
		countA++;
		countC++;
	}

	// If any elements left in vecB, copy them over to vecC.
	while (countB < sizeOfB)
	{
		ptrC[countC] = ptrB[countB];
		countB++;
		countC++;
	}
	return true;
}

void mergeSort(double * ptrSeriesToSort, int sizeOfSeries)
{
	// If sizeOfSeries is 1 or less, it is already sorted, so just return.
	if (sizeOfSeries <= 1)
		return;
	else if (sizeOfSeries == 2)
	{
		// If sizeOfSeries is 2, compare the two elements in it and swap them if necessary, and then return.
		if (ptrSeriesToSort[1] < ptrSeriesToSort[0])
		{
			// Only enters this statement if value in ptrSeriesToSort[1] is less than value in [0].
			// Set up a temp variable and swap the orders of the two.
			double temp;

			temp = ptrSeriesToSort[0];
			ptrSeriesToSort[0] = ptrSeriesToSort[1];
			ptrSeriesToSort[1] = temp;
		}
		return;
	}
	else
	{
		int count = 0;									// Initialize counter to 0
		
		int sizeOfSeries1 = sizeOfSeries / 2;
		int sizeOfSeries2 = sizeOfSeries - sizeOfSeries / 2;

		// Dynamic memory allocation
		double *ptrSeries1 = new double[sizeOfSeries1];
		double *ptrSeries2 = new double[sizeOfSeries2];

		// Copy the first sizeOfSeries / 2 elements in ptrSeriesToSort into ptrSeries1 and the remaining
		// sizeOfSeries - sizeOfSeries / 2  into ptrSeries2.
		for (int i = 0; i < sizeOfSeries1; i++)
		{
			ptrSeries1[i] = ptrSeriesToSort[i];

			// Do not reset counter here. Where it leaves off is where we start copying from for ptrSeries2.
			count++;
		}
		for (int i = 0; i < sizeOfSeries2; i++)
		{
			ptrSeries2[i] = ptrSeriesToSort[count];
			count++;									// Increment the counter
		}
		count = 0;										// Counter reset

		// Call mergeSort() to sort the first series
		mergeSort(ptrSeries1, sizeOfSeries1);
		// Call mergeSort() to sort the second series
		mergeSort(ptrSeries2, sizeOfSeries2);
		// Call mergeTwoSortedSeries() to merge the sorted series into ptrSeriesToSort and make it one sorted series
		mergeTwoSortedSeries(ptrSeries1, sizeOfSeries1, ptrSeries2, sizeOfSeries2, ptrSeriesToSort);
		
		// Free dynamically allocated memory
		delete[] ptrSeries1;
		delete[] ptrSeries2;

		// Reset pointers to point to NULL
		ptrSeries1 = nullptr;
		ptrSeries2 = nullptr;
	}
}
