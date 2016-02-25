/* red_black_tree_old.cpp
*
*	Red-black tree implementation code. Refer to red_black_tree_notes.txt for 
*	more information.
*
*	Status: Header file is INCOMPLETE
*
*	LU: 02/17/16
*/

#include <iostream>
#include <cstdlib>
#include "red_black_tree_old.h"

using namespace std;

// Prototypes
void print_out(unsigned int &key); // Add color later...

// ----------------------------------------------------------------------------
int main()
{
	cout << "Colors are represented as 0 (RED) and 1 (BLACK)." << endl;
	RB_tree *myTree = nullptr;
	//RB_tree myTree(12); // Don't initialize this way.

	//myTree->inorder_processing(myTree, print_out);
	myTree->inorder_DebugPrint(myTree);

	myTree->insert(myTree, 12);
	myTree->insert(myTree, 16);
	myTree->insert(myTree, 1);
	myTree->insert(myTree, 11);
	//cout << "node addr: " << myTree->get_node(myTree, 16) << endl;

	//myTree->inorder_processing(myTree, print_out);
	myTree->inorder_DebugPrint(myTree);

	// We need test cases!!!
	return EXIT_SUCCESS;
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void print_out(unsigned int &key)
{
	cout << "Node key: " << key << endl;
	return;
}
// ----------------------------------------------------------------------------

