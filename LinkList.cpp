//****************************************************
// The following is the content of LinkedList.cpp
//****************************************************
// List Class Constructor Code

#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor: creating an empty list with 0 ListNode structure in it.
List::List()
{
	Head = nullptr;			// In legacy code, people may put it as "Head = NULL;"
	SizeOfList = 0;
}

// Destructor: free all the storage of the ListNode structures in the linked list and
// clear up the linked list to make it an empty list
List::~List()
{
	ListNode * Temp;
	
	while (Head != nullptr)
	{
		Temp = Head->Next;
		delete Head;
		Head = Temp;
	}
}

// Display the contents stored in the date field of all ListNode structures in the linked list
void List::Display()
{
	ListNode * Temp = Head;
	
	cout << endl
		<< " List contains the following " << SizeOfList << " dates:" << endl;
	
	while (Temp != nullptr)
	{
		cout << "  " << Temp->date << endl;
		Temp = Temp->Next;
	}
}

// Search the list to see whether aDate is stored in the date field of a ListNode structure.
// Return true if it is found, return false otherwise.
bool List::Search(DateType aDate)
{
	ListNode * Temp = Head;
	
	while (Temp != nullptr && Temp->date != aDate)
		Temp = Temp->Next;
	
	if (Temp)
		return true;
	else
		return false;
}

// Dynamically create a new ListNode structure and store aDate in the date field.
// Then insert the ListNode structure as the first node in the linked list.
void List::Insert(DateType aDate)
{
	ListNode * Temp = new ListNode;
	
	Temp->date = aDate;
	Temp->Next = Head;
	Head = Temp;
	
	SizeOfList++;
}

// Dynamically create a new ListNode structure and store aDate in the date field.
// Then insert the ListNode structure into the linked list to maintain a sorted linked list.
// In other words, the values in the ListNode structure in the list are in ascending order.
void List::InsertInOrder(DateType aDate)
{
	ListNode * Curr = Head;
	ListNode * Prev = nullptr;
	ListNode * Temp = new ListNode;

	Temp->date = aDate;
	
	// Loop through list until end or item is found
	while ((Curr != nullptr) && (Curr->date < aDate))
	{
		Prev = Curr;
		Curr = Curr->Next;
	}
	
	// Perform the actual insert
	Temp->Next = Curr;
	
	if (Prev != nullptr)				// Inserting in the middle of the list
		Prev->Next = Temp;
	else								// Inserting into the front of the list
		Head = Temp;
	
	SizeOfList++;
}

// Search the list to see whether aDate is stored in the date field of a ListNode structure.
// Remove the first ListNode structure whose date field is equal to aDate from the linked list.
void List::Remove(DateType aDate)
{
	ListNode * Curr = Head;
	ListNode * Prev = nullptr;
	
	while(Curr != nullptr)
	{
		if (Curr->date == aDate)
		{
			if (Prev == nullptr)		// Removing first node
				Head = Curr->Next;
			else						// Removing a normal node
				Prev->Next = Curr->Next;
			
			delete Curr;				// In either case
			SizeOfList--;
			
			return;
		}
		else							// Move to the next item in the list
		{
			Prev = Curr;
			Curr = Curr->Next;
		}
	}
}

// Clear up the linked list to make it an empty list
void List::Clear()
{
	ListNode * Temp;
	
	while (Head != nullptr)
	{
		Temp = Head->Next;
		delete Head;
		Head = Temp;
	}
	
	SizeOfList = 0;
}

// Return the number of elements in the linked list
int List::Size()
{
	return SizeOfList;
}

// Display all the dates between dBegin and dEnd that are currently 
// stored in the date field of all ListNode structures in the linked list
void List::FindAndDisplay(DateType dBegin, DateType dEnd)
{
	ListNode * Temp = Head;
	int count = 0;

	while(Temp != nullptr)
	{
		DateType thisDate;
		
		thisDate = Temp->date;
		
		if (thisDate >= dBegin && thisDate <= dEnd)
			cout << "  " << thisDate << endl;
		
		Temp = Temp->Next;
		count++;
   }

	// Displays if there are no dates that fall within the specified range
	if (count == 0)
		cout << "  None :(";
}

// Clear and empty the current list. Read dates from the istream object "input",
// which may represent a file or just cin, and then store them into the linked list "aList"
istream & operator>> (istream & input, List & aList)
{
	int n;
	
	if (&input == &cin)
	{
		n = -1;
		while (n < 0)
		{
			cout << " How many elements to add into list? ";
			cin >> n;
		}

		aList.Clear();				// Clear the list

		cout << endl
			<< "Enter them one by one" << endl;
		
		for (int i = 0; i < n; i++)
		{
			DateType temp;

			cout << "[" << i << "]:";
			cin >> temp;
			aList.InsertInOrder(temp);
		}
	}
	else							// (&input != &cin)
	{
		input >> n;

		if (n >= 0)
			aList.Clear();
		else
			return input;

		for (int i = 0; i < n; i++)
		{
			DateType temp;

			input >> temp;
			aList.InsertInOrder(temp);
		}
	}
	return input;
}

// Writing out the dates currently stored in the linked list "aList"
// into the ostream object "output", which may represent a file or just cout
ostream & operator<< (ostream & output, List & aList)
{
	if (&output == &cout)
		aList.Display();
	else							// (&output != &cout)
	{
		// Write out the size of the list
		output << aList.Size() << endl;
		
		ListNode * Temp = aList.Head;

		// Write out the dates in the list
		while (Temp != nullptr)
		{ 
			output << Temp->date << endl;
			Temp = Temp->Next;
		}
	}
	return output;
}