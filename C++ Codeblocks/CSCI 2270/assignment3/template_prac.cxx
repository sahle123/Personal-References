/*
 * template_prac.cxx
 *
 *
 *  Created on: Apr 3, 2012
 *      Author: Sahle A. Alturaigi
 *
 *
 *		google: stl lists, bool main()
 *
 *		variable.clear() will clear this list of all objects.
 *		the += should add another list. i.e. l = [1,2,3]; l += 4; l = [1,2,3,4].
 */
/*
#include<iostream>
#include<list>
//#include sorted_bag.template
// If we were to make this class its own file. It would be defined as a template class and saved as 'sorted_bag.template' and include it with the above syntax.

using namespace std;

// --
// This code is for defining the friend operator for overloading the output operator.
template<class Item>
class sorted_bag;
template<class Item>
std::ostream& operator << (std::ostream& outs, const sorted_bag<Item>& item);
// --

template<class Item>
class sorted_bag {

private:
	// Use list<Item> bag; or list<Item>* bag; If the first, the default constructor can be used (Just define the constructor/destructor/copy constructor with an empty body) and the latter, manually define the constructor/destructor/copy constructor.

public:
	// Mod Functions
	void insert_item(const Item& item);

	// Overloaded operands
	const sorted_bag& operator = (const sorted_bag& cSource);
	friend std::ostream& operator << <>(std::ostream& outs, const sorted_bag<Item>& item); // The angle brackets is not a syntax error, this is used for template functions.
}; // End of Class

template<class Item>
void sorted_bag<Item>::insert_item(const Item& item) // When calling sorted_bag outside the class, make sure to specify the data type in anglular brackets.
{
	// bag.push_back(item); // This can be used in the assignment. This mod function will append the link list from the back of the list.
	// bag.sort(); // This can't be used in the assignment. This is a mod function provided by the list class. We're not using this for the assignment. In lieu of that, call your own sorter function.

	// Assuming the bag is sorted and all that is being rearranged is the item in the parameter.
	typename std::list<Item>::iterator i; // typename should only be used here. Read up on the book.
	for(i = bag.begin(); i != bag.end(); ++i)
	{
		if(*i > item) // This will dereference to the object being pointed to by i. This is the ith object.
		{
			// Code for putting the item right before *i.
		}
	}
}

template<class Item>
const sorted_bag<Item>&:: operator = (const sorted_bag& cSource)
{
	// Code for overloading the assignment operator. Should be similar to previous code.
}

template<class Item>
std::ostream& operator << (std::ostream& outs, const sorted_bag<Item>& item)
{
	typename std::list<Item>::const_iterator i;
	for(i = item.bag.begin(); i != item.bag.end(); ++i)
	{
		outs << *i << " ";
	}
	return outs;
}
// End of class scope

int main()
{
	list<int> l; 		 // list of datatype int.
	list<Item> bag;      // list of datatype item.
	list<Item>* bag;	 // Pointer list of datatype item.
	std::list<Item> bag; // Use this syntax if namespace std is not being used.

	// l.size(); list datatype mod function. returns the size of the list.
}

*/
