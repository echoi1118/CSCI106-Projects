#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
using namespace std;

bool mergeTwoSortedVectors(vector<double> & vecA, vector<double> & vecB, vector<double> & vecC);
void mergeSort(vector<double> & vecToSort);

int main()
{
	HANDLE hConsole;								// For console color output
	char chr;
	int n1, n2;
	vector<double> vecA;
	vector<double> vecB;
	vector<double> vecC;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		// For console color output
	
	cout << left << endl << endl;
	SetConsoleTextAttribute(hConsole, 47);
	cout << setw(15) << "" << setw(31) << "Merging Vectors" << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);

	cout << "______________________________________________" << endl;
	cout << " Please enter the sizes of the two vectors" << endl
		<< " (Enter negative vector size to exit loop)" << endl;
	cout << setw(32) << "  Size of vector 1:";
	cin >> n1;											// Input size for vecA

	while (n1 >= 0)
	{
		cout << setw(32) << "  Size of vector 2:";		// Check size of second vector inside the while loop
		cin >> n2;										// Input size for vecB
		cout << endl;

		if (n2 < 0)
			break;										// Break out of this loop if second vector's size is negative

		// Resize vecA, vecB, and vecC (for vecC, make sure it accounts for vecA and vecB's combined size)
		vecA.resize(n1);
		vecB.resize(n2);
		vecC.resize(n1 + n2);
		
		if (n1 != 0)														// Asking for values to fill into vecA if it is not empty
		{
			cout << " Please enter values in the first vector" << endl;
			
			int k = 0;
			
			for (int i = 0; i < n1; i++)									// Fill vecA
			{
				cout << "  Element #" << (i + 1) << ": \t\t\t";
				cin >> vecA[i];
			}
		}
		else
			cout << " Nothing to enter into the first vector" << endl		// Displays if vecA is empty
				<< "  Size of first vector is " << vecA.size() << endl;

		if (n2 != 0)														// Asking for values to fill into vecB if it is not empty
		{
			cout << endl
				<< " Please enter values in the second vector" << endl;

			for (int i = 0; i < n2; i++)									// Fill vecB
			{
				cout << "  Element #" << (i + 1) << ": \t\t\t";
				cin >> vecB[i];
			}
		}
		else
			cout << endl
				<< " Nothing to enter into the second vector" << endl		// Displays if vecB is empty
				<< "  Size of second vector is " << vecB.size() << endl;

		if ((mergeTwoSortedVectors(vecA, vecB, vecC)))
		{
			cout << endl
				<< " The merged vector contains: " << endl;

			if (vecC.size() == 0)											// Checking for empty vector
				cout << "  Nothing. The vector is empty. :(" << endl;
			else
			{
				int k = 0;

				for (int i = 0; i < vecC.size(); i++)
				{
					if (k == 11)					// Purely for formatting purposes: Every time k reaches 11, newline so that
					{								// values don't continue to the right of the console screen. I know the console
						cout << endl;				// newlines it automatically eventually, but I don't like it newlining at the
						k = 0;						// edge of the console. Looks unpresentable.
					}
					k++;							// Increment k
					cout << "  " << vecC[i];		// Display vecC values
				}
				cout << endl;
			}
		}
		cout << endl
			<< "______________________________________________" << endl
			<< " Please enter the sizes of the two vectors" << endl
			<< " (Enter negative vector size to exit loop)" << endl;		// Loop will end when n1 or n2 are given a negative value
		cout << setw(32) << "  Size of vector 1:";
		cin >> n1;															// Input size for vecA
	}

	vector<double> vector;
	int n;

	cout << left << endl << endl;
	SetConsoleTextAttribute(hConsole, 47);
	cout << setw(15) << "" << setw(31) << "Series Sorting" << endl << endl;
	SetConsoleTextAttribute(hConsole, 7);

	cout << "______________________________________________" << endl
		<< " Please enter the size of vector to be sorted" << endl
		<< " (Enter negative vector size to exit loop)" << endl
		<< setw(32) << "  Vector size:";
	cin >> n;

	while (n >= 0)
	{
		vector.resize(n);

		if (n != 0)													// So that user sees the "Please enter the values..." label only if vector size is not 0.
		{															// Because if vector size is 0, there is no need for user to input anything at all.
			cout << endl
				<< " Please enter the values in the vector" << endl;
			for (int i = 0; i < n; i++)								// cin values into the vector until i reaches vector size
			{
				cout << "  Element #" << i + 1 << ": \t\t\t";
				cin >> vector[i];
			}
			mergeSort(vector);										// Calling the recursive function
		}

		cout << endl
			<< " The sorted vector contains:" << endl;
		if (vector.size() == 0)
			cout << "  Nothing. Vector is empty. :(" << endl;		// In the case of the vector being empty
		else
		{
			int k = 0;

			for (int i = 0; i < n; i++)
			{
				if (k == 11)										// For formatting of the displaying of the vector values
				{
					cout << endl;									// So that program newlines after every 11 values
					k = 0;
				}
				k++;
				cout << "  " << vector[i];
			}
			cout << endl;
		}
		cout << endl
			<< "______________________________________________" << endl
			<< " Please enter the size of vector to be sorted " << endl
			<< " (Enter negative vector size to exit loop)" << endl
			<< setw(32) << "  Vector size:";
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
			<< setw(10) << "" << " >> Invalid character << " << endl;		// Must enter x to quit
		SetConsoleTextAttribute(hConsole, 7);

		cout << endl
			<< "______________________________________________" << endl
			<< setw(32) << "  Enter x to quit:";
		cin >> chr;
	}
	return 0;
}

bool mergeTwoSortedVectors(vector<double> & vecA, vector<double> & vecB, vector<double> & vecC)
{
	// Set and initialize counters for each vector
	int countA = 0, countB = 0, countC = 0;

	HANDLE hConsole;															// For console color output
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 1; i < vecA.size(); i++)
	{
		if (vecA[i - 1] > vecA[i])												// Did it this way to keep vector from checking out-of-bounds.
		{
			SetConsoleTextAttribute(hConsole, 14);
			cout << endl
				<< " >> ERROR: Vector 1 not in ascending order <<" << endl;		// Displays if values in first vector are not in ascending order
			SetConsoleTextAttribute(hConsole, 7);
			return false;														// Automatically return false if vector is unsorted
		}
	}

	for (int i = 1; i < vecB.size(); i++)
	{
		if (vecB[i - 1] > vecB[i])												// If value in vecB[i - 1] is greater than value in vecB[i] means vector is unsorted
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
	// either vecA or vecB have been completely copied over into vecC.

	while ((countA < vecA.size()) && (countB < vecB.size()))
	{
		if (vecA[countA] <= vecB[countB])		// If what's in vecA is greater than or equal to what's in vecB
		{
			vecC[countC] = vecA[countA];		// Copy that value in vecA into vecC
			countA++;							// Increment the counter for A
		}
		else if (vecA[countA] > vecB[countB])	// Else if what's in vecA is greater than what's in vecB
		{
			vecC[countC] = vecB[countB];		// Copy that value in vecB into vecC
			countB++;							// Increment the counter for B
		}
		countC++;								// Increment the counter for C
	}

	// Only one of the following two loops will have to execute. The other will have
	// a counter that has reached the size of the vector (from the loop above) and
	// will never execute.

	// If there are any elements left in vecA, copy them over to vecC.
	while (countA < vecA.size())
	{
		vecC[countC] = vecA[countA];
		countA++;
		countC++;
	}

	// If any elements left in vecB, copy them over to vecC.
	while (countB < vecB.size())
	{
		vecC[countC] = vecB[countB];
		countB++;
		countC++;
	}

	// I wouldn't have to do it this way if if weren't for the recursive function that also uses this
	// function. I would've just used vecC.push_back(vecA[countA]) instead of vecC[countC] = vecA[countA]
	// since, according to the reading, vectors are very dynamic and don't require us to state a size. So I
	// wanted to test it out. But then with the recursive function we also have to implement, found out
	// that it's definitely a no-no. There was a reason why the specs made us predefine the size for vecC
	// and why it told us to "copy over" instead of using push_back(). Lesson learned. Specs know best.

	return true;
}

void mergeSort(vector<double> & vecToSort)
{
	if (vecToSort.size() <= 1)
	{
		// If the size of vecToSort is 1 or less, it is already sorted, so just return.

		return;

		// This was really weird for me. It's returning nothing. It's just returning...
		// Not even return 0 worked since this is a void function and so it can't return anything.
		// And there were no examples like this in the book so I was stumped, until I decided to
		// just take the instructions in the specs at face value. I just returned...and then I understood
		// a little what was going on here (this is what's called the base case). But I'm just saying...
		// I've never done something so weird before. It was a weird thing to do. Like going home empty-handed.
	}
	else if (vecToSort.size() == 2)
	{
		// If the size of vecToSort is 2, compare the two elements in it and swap them if necessary, and then return.

		if (vecToSort[1] < vecToSort[0])				// Only enters this statement if value in vecToSort[1] is less than value in [0]
		{
			double temp;								// Set up a temp variable and swap the orders of the two
			temp = vecToSort[0];
			vecToSort[0] = vecToSort[1];
			vecToSort[1] = temp;
		}
		return;
	}
	else
	{
		vector<double> vec1, vec2;
		int count = 0;

		// Otherwise, the size of vecToSort is at least 3. Use two separate vectors, vec1 and vec2 (as local objects),
		// resize them to the sizes vecToSort.size() / 2 and vecToSort.size() - vecToSort.size() / 2 respectively.
		vec1.resize(vecToSort.size() / 2);
		vec2.resize(vecToSort.size() - vecToSort.size() / 2);

		// Copy the first vecToSort.size() / 2 elements in vecToSort into vec1 and the remaining
		// vecToSort.size() - vecToSort.size() / 2  into vec2.
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
