///////////////////////////////////////////////////////////////////////////////////////////////
//									V L I S T . C P P

#include <iostream>
#include <vector>
#include <string>
#include "vlist.h" 
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
	count = 0;
	DB.reserve(9);
	cout << "\nDefault Constructor Invoked" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Copy Constructor
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org)
{
	cout << "\nCopy Constructor Invoked" << endl;
	DB = Org.DB;
	print();
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist()
{
	cout << "\nDestructor Invoked";
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: isEmpty
//Precondition: Vector DB has been initialized.
//Postcondition: Returns true if the vlist is empty; otherwise false.
//Description: Checks if vlist is empty.
///////////////////////////////////////////////////////////////////////////////////////////////
bool vlist::isEmpty()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search
//Precondition: The parameter key is passed.
//Postcondition: Iterator to the location is returned.
//Description: Searches the vector for an item and return the location.
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string>::iterator vlist::search(const string& key)
{
	auto itr = std::find(DB.begin(), DB.end(), key);
	if (itr == DB.end())
	{
		cout << "\nItem Not found" << endl;
	}
	else
	{
		cout << "\nItem Found: " << *itr;
	}
	return itr;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: The parameter key is passed.
//Postcondition: The paramter key is inserted into the vector.
//Description: Adds an item to the vector in alphabetical order.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::insert(const string & key)
{
	DB.push_back(key);
	count++;
	sort();
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove
//Precondition: The paramter key is passed.
//Postcondition: An item is removed from the vector if found.
//Description: Removes an item from the vector if it is there; 
//			   otherwise prints a message stating it was not in vector. 
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::remove(const string& key) 
{
	auto itr = search(key);
	if (itr != DB.end())
	{
		DB.erase(itr);
	}
	else
	{
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print
//Precondition: Vector DB has been initialized.
//Postcondition: Elements of vector DB has been displayed.
//Description: Prints out the elements of vector DB.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::print() 
{
	vector<string>::iterator v = DB.begin();
	while (v != DB.end()) 
	{
		cout << *v << endl;
		v++;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: sort
//Precondition: Vector DB has been initialized.
//Postcondition: Vector is sorted alphabetically.
//Description: Sorts the vector in alphabetical order.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::sort()
{
	for (int i = 0; i < DB.size(); i++) 
	{
		for (int j = i; j < (DB.size()); j++)
		{
			if (DB[i] > DB[j])
			{
				std::swap(DB[i], DB[j]);
			}
		}
	}
}