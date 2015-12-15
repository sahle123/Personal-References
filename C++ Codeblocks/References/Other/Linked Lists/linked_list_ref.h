#ifndef LINKED_LIST_REF_H_INCLUDE
#define LINKED_LIST_REF_H_INCLUDE

/* Linked_list_ref.h
*
*	Reference for linked lists implemented in C++	
*
*	Notes: 
*		'node*&' and 'const node*' are equivalent. I think.
*
*	LU: 12/14/15
*/

#ifndef LINKED_LIST_REF_H_
#define LINKED_LIST_REF_H_

#include <iostream>
#include <cstdlib>

using namespace std;

class node
{
public:
	typedef int value_type;

	// Constructor
	node(value_type newData, node* newLink)
	{
		data = newData;
		link = newLink;
	}

	// Destructor
	// *Don't bother with this. Delete acts strangely and there are NO
	// good answers anywhere on google. Stick with manually calling
	// erase_head and deleting them that way.
	/*~node()
	{
		node* ptr_deleter;
		node* temp;
		cout << "\n\nCleaning up linked list. One moment..." << endl;

		if(this != 0)
		{
			ptr_deleter = this;
			while(ptr_deleter != 0)
			{
				cout << "ptr_: " << ptr_deleter->get_link() << endl;
				temp = ptr_deleter->get_link();
				//cout << "temp: " << temp->get_link() << endl;
				//delete ptr_deleter;
				ptr_deleter = temp;
			}
		}
	}*/


	// Mod functions
	void set_data(const value_type& newData) {data = newData;}
	void set_link(node*& newLink) {link = newLink;}
	const value_type get_data() const {return data;}
	const node* get_link() const {return link;}
	node* get_link() {return link;}

	// Gets the next link in the link list.
	node* get_next();

	void list_print(node* head);
	void list_size (node* head);

	void insert(node*& head, node::value_type newVal);
	int erase_head(node*& head);

	// Overloaded operands
	friend istream& operator >> (istream& ins, node& target);
	friend ostream& operator << (ostream& outs, node& target);
	node& operator = (const node &obj);

private: 
	value_type data;
	node* link;
};

//-----------------------------------------------------------------------------
void node::list_print(node* head)
{
	node* temp;

	if (head == 0x0)
	{
		cout << "List is empty." << endl;
		return;
	}

	// The end of the list must equal 0 for this forloop to quit.
	for(temp = head; temp != 0x0; temp = temp->get_link())
	{
		cout << temp->get_data() << ", " << temp->get_link() << "\t";
	}
	cout << endl;
}
//-----------------------------------------------------------------------------
void node::list_size(node* head)
{
	unsigned int count = 0;
	node* temp;

	for(temp = head; temp !=0x0; temp = temp->get_link())
		++count;

	cout << "List size: " << count << endl;
}
//-----------------------------------------------------------------------------
void node::insert(node*& head, node::value_type newVal)
{
	node* new_node = new node(head->get_data(), head->get_link());
	head->set_link(new_node);
	head->set_data(newVal);
	//head = new_node;
	cout << "Link has been inserted to list!" << endl;
	//cout << "\tData: " << head->data << " Link: " << head->link << endl;
}
//-----------------------------------------------------------------------------
int node::erase_head(node*& head)
{
	node* temp;

	if (head != 0x0)
	{
		temp = head->get_link();
		delete head;
		head = temp;
		return 0;
	}

	cout << "List is already empty..." << endl;
	return 1;
}
//-----------------------------------------------------------------------------
istream& operator >> (istream& ins, node& target)
{
	ins >> target.data;
	return ins;
}
//-----------------------------------------------------------------------------
ostream& operator << (ostream& outs, node& target)
{
	outs << "Data: " << target.data << " Link: " << target.link;
	return outs;
}
//-----------------------------------------------------------------------------
node& node::operator = (const node& obj)
{
	if(this != &obj)
	{
		data = obj.data;
		link = obj.link;
	}
	return *this;
}
//-----------------------------------------------------------------------------
node* node::get_next()
{
	return link->get_link();
}
//-----------------------------------------------------------------------------

#endif // LINKED_LIST_REF_H
#endif // LINKED_LIST_REF_H_INCLUDE