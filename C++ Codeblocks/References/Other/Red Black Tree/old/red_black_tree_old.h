#ifndef RED_BLACK_TREE_OLD_H_INCLUDE
#define RED_BLACK_TREE_OLD_H_INCLUDE

/* red_black_tree_old.h
*
* 	Red-black tree header code
*
*	Tasks: 	1) Implement BST
*			2) Add in insert, print, search, delete methods
*			3) Add in Red-Black tree properties and adapt code
*			4) Build strong test cases to stress-test program
*			5) Optimize code. Use nullptr instead of NULL
*			6) Give nodes ability to carry values
*	
*	Status: INCOMPLETE
*
*	LU: 02/23/16
*/

#ifndef RED_BLACK_TREE_OLD_H_
#define RED_BLACK_TREE_OLD_H_

#include <iostream>

typedef unsigned int k_int; // Datatype to represent key values in nodes.

// ----------------------------------------------------------------------------
class RB_tree
{
public:

	// Constructor for root node
	RB_tree (k_int newKey)
	{
		key = newKey;
		color = black;

		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	// General constructor
	RB_tree (k_int newKey, RB_tree *newParent)
	{
		key = newKey;
		color = red;

		left = nullptr;
		right = nullptr;
		parent = newParent;
	}

	// Insert method
	void insert(RB_tree *&root, k_int newKey);
	// Delete method
	// Get node method **appears to work correctly
	RB_tree *get_node(RB_tree *root, k_int keyNode);

	// Inorder print
	void inorder_DebugPrint(RB_tree *root);
	// Inorder processing **Needs testing
	template<class Process>
	void inorder_processing(RB_tree *root, Process paramProc);

private:
	enum nColor { red, black };

	/* Methods */
	// If there is a root node for the tree, this method gets called
	// to handle inserting new nodes into the tree.
	void insert_node(RB_tree *&root, k_int newKey, RB_tree *&parentRoot);
	// After node is inserted, RB_insert_node() will go through the steps
	// to preserve RB properties via color switching and rotations.
	void RB_insert_node(RB_tree *&root);
	// Left rotation method
	void left_rotate(RB_tree *&rotatePoint);
	// Right rotation method
	void right_rotate(RB_tree *&rotatePoint);

	/* Variables */
	k_int key;
	nColor color;
	RB_tree *left, *right, *parent;

};	// End RB_Tree class

// ----------------------------------------------------------------------------
// get_node()
// ----------------------------------------------------------------------------
RB_tree* RB_tree::get_node(RB_tree *root, k_int keyNode)
{
	if(root->key == keyNode)
		return root;
	else if(root->key <= keyNode)
		return get_node(root->right, keyNode);
	else if(root->key > keyNode)
		return get_node(root->left, keyNode);
	else
	{
		std::cout << "Error in retrieving keyNode: " << keyNode << std::endl;
		return NULL;
	}
}
// ----------------------------------------------------------------------------
// private: left_rotate()
// Dependencies: get_node()
// ----------------------------------------------------------------------------
void RB_tree::left_rotate(RB_tree *&rotatePoint)
{
	return;
}
// ----------------------------------------------------------------------------
// private: right_rotate()
// Dependencies: get_node()
// ----------------------------------------------------------------------------
void RB_tree::right_rotate(RB_tree *&rotatePoint)
{
	return;
}
// ----------------------------------------------------------------------------
// insert()
// Base case for first creating the tree, otherwise, insert_node() is used.
// ----------------------------------------------------------------------------
void RB_tree::insert(RB_tree *&root, k_int newKey)
{
	// Base case for first time insert
	if(root == nullptr)
		root = new RB_tree(newKey);

	else if (root->key <= newKey)
		insert_node(root->right, newKey, root);

	else
		insert_node(root->left, newKey, root);
}
// ----------------------------------------------------------------------------
// private: insert_node()
// May need to refactor so that insert_node() and insert are merged into one.
// ----------------------------------------------------------------------------
void RB_tree::insert_node(RB_tree *&root, k_int newKey, RB_tree *&parentRoot)
{
	if(root == nullptr)
	{
		root = new RB_tree(newKey, parentRoot);
		//RB_insert_node(root);
	}

	else if (root->key <= newKey)
		insert_node(root->right, newKey, root);

	else
		insert_node(root->left, newKey, root);
}
// ----------------------------------------------------------------------------
// private: RB_insert_node()
// Status: BROKEN. I'm suffering here. Can't make algorithm that won't 
// cause memory leaks or bad logic.
// IDEA: Consider adding another parameter for the recently added node,
// and root parameter will be the tree root. That way, we can do all changes
// relative to root and still know where our new node is.
// ----------------------------------------------------------------------------
void RB_tree::RB_insert_node(RB_tree *&root)
{
	RB_tree *x = root;

	while((x->parent != nullptr) && (x->parent->color == red))
	{	
		if(x->parent == x->parent->parent->left)
		{
			std::cout << "LEFT ping" << std::endl;

			//RB_tree *y = x->parent->parent->right;

			// Case 1
			if (x->parent->parent->right->color == red)
			{
				x->parent->color = black;
				x->parent->parent->right->color = black;
				//y->color = black;
				x->parent->parent->right->color = black;
				x->parent->parent->color = red;
				x = x->parent->parent;
			}		
		}
	}

	// Get child of x
	//while((x->right != root || (x->left != root))
	//{

	//}
	// Change root color to black
}
// ----------------------------------------------------------------------------
// inorder_processing()
// ----------------------------------------------------------------------------
void RB_tree::inorder_DebugPrint(RB_tree *root)
{
	if(root == nullptr)
		return;

	inorder_DebugPrint(root->left);
	
	if (root->parent != nullptr)
	{
		std::cout << "Node key/color/parent: (" << root->key << "/" << root->color << "/" << root->parent->key << ")" << std::endl;
		//std::cout << "Node addr: " << root << std::endl;
	}
	else
	{
		std::cout << "Node key/color: (" << root->key << "/" << root->color << ")" << std::endl;
		//std::cout << "Node addr: " << root << std::endl;
	}

	inorder_DebugPrint(root->right);
}
// ----------------------------------------------------------------------------
// inorder_processing()
// ----------------------------------------------------------------------------
template<class Process>
void RB_tree::inorder_processing(RB_tree *root, Process paramProc)
{
	if (root == nullptr)
		return;

	inorder_processing(root->left, paramProc);
	paramProc(root->key);
	inorder_processing(root->right, paramProc);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#endif // RED_BLACK_TREE_OLD_H_
#endif // RED_BLACK_TREE_OLD_H_INCLUDE