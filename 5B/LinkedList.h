#include <fstream>
#include "DateType.h"

using namespace std;

//****************************************************
// The following are the contents of LinkedList.h 
//****************************************************
struct ListNode
{
   DateType date;
   ListNode * Next;
};

class List
{
private:
	ListNode * Head;
	int SizeOfList;

public:
	List();
	// Constructor: creating an empty list with 0 ListNode structures in it.
	
	~List();
	// Destructor: free all the storage of the ListNode structures in the linked list and
	// clear up the linked list to make it an empty list.
	
	void Display();
	// Display the contents stored in the Value field of all ListNode structures in the linked list.
	
	bool Search(DateType aDate);
	// Search the list to see whether Val is stored in the Value field of a ListNode structure.
	// Return true if it is found, return false otherwise.
	
	void Insert(DateType aDate);
	// Dynamically create a new ListNode structure and store Val in the Value field in it.
	// Then insert the ListNode structure as the first node in the linked list.
	
	void InsertInOrder(DateType aDate);
	// Dynamically create a new ListNode structure and store Val in the Value field in it.
	// Then insert the ListNode structure into the linked list to maintain a sorted linked list.
	// In other words, the values in the ListNode structure in the list are in ascending order.
	
	void Remove(DateType aDate);
	// Search the list to see whether Val is stored in the Value field of a ListNode structure.
	// Remove the first ListNode structure whose Value field is equal to Val from the linkled list.
	
	void Clear();
	// Clear up the linked list to make it an empty list.
	
	int Size();
	// Return the number of elements in the linked list.
	
	void FindAndDisplay(DateType dBegin, DateType dEnd);
	// Display the all the dates between dBegin and dEnd that are currently
	// stored in the date field of all ListNode structures in the linked list.
	
	//*******************************************************************
	// The following two global I/O operators are declared as friends
	//*******************************************************************
	
	friend ostream & operator<< (ostream & output, List & aList);
	// Writing out the integer values currently stored in the linked list "aList"
	// into the ostream object "output", which may represent a file or just cout.
	
	friend istream & operator>> (istream & input, List & aList);
	// Clear and empty the current list.
	// Read int values from the istream object "input", which may represent a file or just cin
	// and then store them into the linked list "aList".
 };
