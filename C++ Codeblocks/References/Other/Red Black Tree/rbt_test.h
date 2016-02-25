#ifndef RBT_TEST_H_INCLUDE
#define RBT_TEST_H_INCLUDE

/* rbt_test.h
*
* 	Red-black tree header TEST code
*
*	LU: 02/23/16
*/

#ifndef RBT_TEST_H_
#define RBT_TEST_H_

// If C++ 98 or earlier is being used.
#if __cplusplus <= 199711L
#define nullptr NULL
#endif

#include <iostream>

typedef unsigned int k_int; // Datatype to represent key values in nodes.

enum nColor { RED, BLACK };

struct Node {
	k_int key;
	bool color;
	Node *left, *right, *parent;
	// Constructor
	explicit Node(k_int n) : key(n), color(RED), left(nullptr), right(nullptr),
							parent(nullptr) {}
};
// ----------------------------------------------------------------------------
class RB_tree
{
private:
	Node *root;

	/* Methods */
	void insert_node_fix(Node *&, Node *&);
	// Left rotation method
	void rotate_left(Node *&, Node*&);
	// Right rotation method
	void rotate_right(Node *&, Node*&);
	
	
public:


	// Insert method
	void insert(RB_tree *&root, k_int newKey);

	// Delete method

	// Get node method **appears to work correctly
	RB_tree *get_node(RB_tree *root, k_int keyNode);

	// Inorder print
	void inorder_DebugPrint(RB_tree *root);
	// Inorder processing

	template<class Process>
	void inorder_processing(RB_tree *root, Process paramProc);

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
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// private: right_rotate()
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// insert()
// Base case for first creating the tree, otherwise, insert_node() is used.
// ----------------------------------------------------------------------------
void RB_tree::insert(RB_tree *&root, k_int newKey)
{
	static RB_tree *previous = nullptr;

	// Base case for first time insert
	if(root == nullptr)
	{
		root = new RB_tree(newKey);

	}

	else if (root->key <= newKey)
		insert(root->right, newKey, root);

	else
		insert(root->left, newKey, root);
}
// ----------------------------------------------------------------------------
// private: RB_insert_node()
// ----------------------------------------------------------------------------
void RB_tree::insert_node_fix(RB_tree *&root)
{
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

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#endif // RBT_TEST_H_INCLUDE_
#endif // RBT_TEST_H_