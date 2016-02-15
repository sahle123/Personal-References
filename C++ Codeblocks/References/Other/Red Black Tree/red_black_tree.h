#ifndef RED_BLACK_TREE_H_INCLUDE
#define RED_BLACK_TREE_H_INCLUDE

/* red_black_tree.h
*
* 	Red-black tree header code
*
*	Tasks: 	1) Implement BST
*			2) Add in insert, print, search, delete methods
*			3) Add in Red-Black tree properties and adapt code
*			4) Build strong test cases to stress-test program
*			5) Optimize code. Use nullptr instead of NULL
*	
*	Status: INCOMPLETE
*
*	LU: 02/10/16
*/

#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include <iostream>

// ----------------------------------------------------------------------------
struct RB_Node
{
	int key;
	enum color {red, black};
	RB_Node *left, *right, *parent
};

// ----------------------------------------------------------------------------
class RB_Tree
{
public:
private:
};

// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------

#endif // RED_BLACK_TREE_H_
#endif // RED_BLACK_TREE_H_INCLUDE	




