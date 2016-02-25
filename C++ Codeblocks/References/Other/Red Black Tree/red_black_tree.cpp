/* red_black_tree.cpp
*
*	Red-black tree implementation code. 
*	Refer to red_black_tree_notes.txt for more information.
*
*	I received much insight on this thanks to Dinesh Khandewal.
*	Reference: http://ideone.com/PvEzCI
*
*	Status: Semi-Complete (missing delete method)
*
*	LU: 02/24/16
*/

#include <iostream>
#include <cstdlib>
#include "red_black_tree.h"

using namespace std;

// Prototypes
void print_out(unsigned int &key, bool &color);

// ----------------------------------------------------------------------------
int main()
{
	RB_tree leTree;

	// Test cases
	leTree.insert(15);
	leTree.insert(12);
	leTree.insert(11);
	leTree.insert(20);
	leTree.insert(1);
	leTree.insert(2);
	leTree.insert(5);
	leTree.insert(100);
	leTree.insert(31);
	leTree.insert(7);
	leTree.insert(42);

	leTree.inorder_print();

	leTree.tree_depth();

	leTree.inorder_process(print_out);

	leTree.preorder_print();

	leTree.cleanup();

	return EXIT_SUCCESS;
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void print_out(unsigned int &key, bool &color)
{
	// If color is 1 -> Black. If 0 -> Red.
	char c = (color) ? 'B' : 'R';

	cout << "Node key:   " << key << endl;
	cout << "Node color: " << c << endl;
	cout << endl;
	return;
}
// ----------------------------------------------------------------------------

