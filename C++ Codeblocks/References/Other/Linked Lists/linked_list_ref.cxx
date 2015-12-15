/* linked_list_ref.cxx
*
*	Implementation code for linked_list_ref header. Check for more detail
*
*	Notes:
*		declaring 'const' nodes for some reason breaks cout <<
*
*	LU: 12/14/15
*/

#include <iostream>
#include <cstdlib>
#include "linked_list_ref.h"

using namespace std;

int main()
{
	node* nullPtr = 0;
	int delete_check = 0;
	int blargian = 24;
	int someInt = 1337;
	
	node* leHead = new node (blargian, nullPtr);
	node* secondNode = new node(someInt, nullPtr);
	node* secondCpy = leHead; // So we don't lose original head and a get mem. leak

	/*** Tests ***/

	// ** Getters, setters, ostreams, and instreams
	cout << "*** Testing getters, ostream, istream ***" << endl;
	cout << leHead->get_link() << endl;
	//cout << "Input a new value for leHead" << endl;
	// cin >> (*leHead);
	cout << (*leHead) << endl;
	leHead = secondNode;
	cout << "Testing assignment operator: " << (*leHead) << endl;

	// ** Build list
	cout << "\n\n*** Building Lists ***" << endl;
	leHead->list_print(leHead);
	leHead->insert(leHead, 822);
	leHead->list_print(leHead);
	leHead->insert(leHead, 564);
	leHead->list_print(leHead);
	leHead->insert(leHead, 55555);
	leHead->list_print(leHead);
	leHead->insert(leHead, 100000);
	leHead->list_print(leHead);
	leHead->insert(leHead, 9393922);
	leHead->list_print(leHead);

	// ** List print and size
	cout << "\n\n*** Testing print ***" << endl;
	cout << "Testing list_print: ";
	leHead->list_print(leHead);
	cout << "Testing list_size: ";
	leHead->list_size(leHead);
	cout << "\nget_link " << leHead->get_link();
	cout << "\nget_next " << leHead->get_next();

	// ** Erase list
	cout << "\n\n*** Testing erase methods ***" << endl;
	leHead->erase_head(leHead);
	cout << "New list and size: " << endl;
	leHead->list_print(leHead);
	leHead->list_size(leHead);
	cout << "New list and size after deleting whole list: " << endl;
	do
	{
		delete_check = leHead->erase_head(leHead);
	} while(delete_check != 1);

	leHead->list_print(leHead);
	leHead->list_size(leHead);

	cout << endl;
	delete secondCpy; // So we don't lose original head.
	delete leHead;

	return EXIT_SUCCESS;
}