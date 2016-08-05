/* rbt_test2.cpp
*
*	TEST CODE
*
*	LU: 03/17/16
*/

#include <iostream>
#include <cstdlib>
#include "rbt_test.h"

using namespace std;


// ----------------------------------------------------------------------------
int main()
{
	RB_tree leTree;

	// Test cases
	leTree.remove(8);
	/// Check for insert(0). Should fail

	//leTree.tree_depth();

	// Testing for inserting and deleting root of tree.
	leTree.insert(10);
	/*leTree.remove(10);
	leTree.insert(10);
	leTree.insert(5);
	leTree.remove(10);*/
	leTree.insert(5);

	// Setting up new tree
	leTree.insert(30);
	leTree.insert(20);
	leTree.insert(1);
	leTree.insert(7);
	leTree.insert(38);
	leTree.insert(35);


	leTree.preorder_print_debug();
/*
	leTree.insert(30);

	leTree.remove(35);

	leTree.preorder_print_debug();

	leTree.remove(30);
	leTree.remove(38);
	leTree.remove(38);
	//leTree.insert(35);
	//leTree.remove(20);
	leTree.remove(5);
*/
/*
	leTree.inorder_print();

	leTree.tree_depth();

	leTree.preorder_print();

	leTree.tree_depth();
	leTree.cleanup();

	//leTree.insert(10);
	//leTree.inorder_print();
	//leTree.cleanup();
*/
	leTree.preorder_print_debug();
	leTree.cleanup();
	return EXIT_SUCCESS;
}
// ----------------------------------------------------------------------------
/*
	Issues:
	

	Fixed:
	1 - Depth method appears to give n+1, where n is the actual tree height.
	2 - Adding a node with an existing key value in the tree causes a segfault.
	3 - Remove method is removing the inorder successor which is incorrect.
*/