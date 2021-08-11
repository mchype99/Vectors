
///////////////////////////////////////////////////////////////////////////////////////////////
//									V L I S T . H

#include <vector> 
#include <string>
using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();//Default Constructor
	vlist(const vlist&);//Copy Constructor
	~vlist();//Destructor
	bool isEmpty();//Checks if vector is empty
	vector<string>::iterator search(const string&);//Search for items location in vector
	void insert(const string&);//Inserts item in vector
	void remove(const string&);//Removes item from vector
	void print();//Prints all elements of vector
	void sort();//Sorts the vector
private:
	vector<string> DB;
	int count;
};

#endif


