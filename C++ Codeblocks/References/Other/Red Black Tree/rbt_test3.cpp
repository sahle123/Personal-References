/* rbt_test3.cpp
*
*	TEST CODE
*
*	LU: 03/19/16
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
	leTree.insert(10);
	leTree.insert(5);
	leTree.insert(30);
	leTree.insert(1);
	leTree.insert(38);
	leTree.insert(7);
	leTree.insert(20);
	leTree.insert(35);
	//leTree.remove(10);
	leTree.insert(37);
	leTree.insert(40);
	leTree.remove(38);
	//leTree.remove(38);

	leTree.preorder_print_debug();
	leTree.cleanup();
	return EXIT_SUCCESS;
}
// ----------------------------------------------------------------------------
