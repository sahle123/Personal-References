/* rbt_test.cpp
*
*	TEST CODE
*
*	LU: 03/13/16
*/

#include <iostream>
#include <cstdlib>
#include "rbt_test.h"

using namespace std;

// Prototypes
void print_out(unsigned int &key, bool &color);

// ----------------------------------------------------------------------------
int main()
{
	RB_tree leTree;

	// Test cases
	leTree.remove(8);

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

	leTree.remove(7);
	leTree.remove(1001230203);


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

