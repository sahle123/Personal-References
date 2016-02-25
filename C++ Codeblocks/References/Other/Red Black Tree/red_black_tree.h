#ifndef RED_BLACK_TREE_H_INCLUDE
#define RED_BLACK_TREE_H_INCLUDE

/* red_black_tree.h
*
* 	Des:	Red-black tree header code
*
*	To-do:	
*			1. (Complete) Tree depth 
*			2. (Complete More printing options
*			3. Delete method
*			4. (Complete) Processing for nodes
*
*	Status:	Semi-complete (missing delete method)
*
*	LU: 02/24/16
*/

// If C++ 98 or earlier is being used.
#if __cplusplus <= 199711L
#define nullptr NULL
#endif

#include <iostream>

typedef unsigned int k_int; // Datatype to represent key values in nodes.

enum nColor { RED, BLACK };

// ----------------------------------------------------------------------------
struct Node {
	k_int key;
	bool color;
	Node *left, *right, *parent;
	// Constructor
	explicit Node(k_int n) : key(n), color(RED), 
							 left(nullptr), right(nullptr), parent(nullptr) {}
};

// ----------------------------------------------------------------------------
class RB_tree
{
private:
	Node *root;

	// Insert methods block.
	void bst_insert(Node *&root, Node *&neoNode);
	void fix_violation(Node *&, Node *&);
	void rotate_left(Node *&, Node *&);
	void rotate_right(Node *&, Node *&);

	// Depth methods
	int depth_helper(Node *&root);
	int BH_helper(Node *&root); // Black-height

	// Tree printing helpers
	void inorder_helper(Node *&root);
	void preorder_print_helper(Node *&root);

	// Helper for inorder_process	
	template<class Process>
	void inorder_process_helper(Node *&root, Process f);

	// Helper for cleanup()
	void cleanup_helper(Node *&root);
	
public:
	// Constructor
	RB_tree() : root(nullptr) {}

	// Insert method
	void insert(const k_int &key);

	// Tree printing methods
	void inorder_print();
	void preorder_print();

	// Callback method that occurs for each node in the tree in order.
	template<class Process>
	void inorder_process(Process f);

	// Gets the depth and 'black height' of tree.
	void tree_depth();

	// Cleanup method to call once at the end of the program.
	// If this method isn't called, there will be memory leaks.
	void cleanup();

	// Delete method
	//...

};	// End RB_tree class


// ----------------------------------------------------------------------------
// insert()
// Dependencies: bst_insert(), fix_violation()
// ----------------------------------------------------------------------------
void RB_tree::insert(const k_int &key)
{
	Node *neoNode = new Node(key);

	bst_insert(root, neoNode);

	fix_violation(root, neoNode);
}
// ----------------------------------------------------------------------------
// inorder_print()
// ----------------------------------------------------------------------------
void RB_tree::inorder_print()
{
	std::cout << "Print out tree in order:" << std::endl;
	inorder_helper(root);
}
// ----------------------------------------------------------------------------
// preorder_print()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print()
{
	std::cout << "Preorder order print:" << std::endl;
	preorder_print_helper(root);
}
// ----------------------------------------------------------------------------
// inorder_process()
// ----------------------------------------------------------------------------
template<class Process>
void RB_tree::inorder_process(Process f)
{
	std::cout << "\nBeginning inorder process..." << std::endl;
	inorder_process_helper(root, f);
}
// ----------------------------------------------------------------------------
// tree_depth()
// ----------------------------------------------------------------------------
void RB_tree::tree_depth()
{
	int depth = 0;
	int bh = 0; 	
	
	// Get tree_depth
	depth = depth_helper(root);
	// Get black height
	bh = BH_helper(root);

	// print out information
	std::cout << "Depth:        " << depth << std::endl;
	std::cout << "Black height: " << bh << std::endl;
}
// ----------------------------------------------------------------------------
// cleanup()
// ----------------------------------------------------------------------------
void RB_tree::cleanup()
{
	std::cout << "Cleaning up tree to avoid memory leaks... ";
	cleanup_helper(root);

	if(root != NULL)
		std::cout << "\nHad an issue cleaning up tree. Check RB_tree::cleanup_helper(), red_black_tree.h" << std::endl; 
	else
		std::cout << "Successfully cleared tree!" << std::endl;
}
// ----------------------------------------------------------------------------

//                  ------ Private methods section ------

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// private: bst_insert()
// ----------------------------------------------------------------------------
void RB_tree::bst_insert(Node *&root, Node *&neoNode)
{
	// This is necessary for creating a brand new RB_tree without
	// needing to create a separate method for this base case and
	// keeping track of the parent later on.
	static Node *previous = nullptr;

	if(root == nullptr)
	{
		root = neoNode;
		neoNode->parent = previous;
	}
	else
	{
		previous = root; // To keep track of parent

		if(root->key > neoNode->key)
			bst_insert(root->left, neoNode);
		else if (root->key < neoNode->key)
			bst_insert(root->right, neoNode);
	}
}
// ----------------------------------------------------------------------------
// private: fix_violation()
// Need to test how local variables interact with root, x, and function calls.
// ----------------------------------------------------------------------------
void RB_tree::fix_violation(Node *&root, Node *&x)
{
	Node *parent_x = nullptr;
	Node *grand_parent_x = nullptr;

	while ((x != root) && (x->color == RED) && (x->parent->color == RED))
	{
		parent_x = x->parent;
		grand_parent_x = x->parent->parent;

		// If x's parent is the LEFT child of its grandparent.
		if (parent_x == grand_parent_x->left)
		{
			Node *uncle_x = grand_parent_x->right;

			/*
			*	Case: 1 
			*	The uncle (x's grandparent's right child) of x is also RED.
			*	Only do recoloring.
			*/
			if ((uncle_x != nullptr) && (uncle_x->color == RED))
			{
				parent_x->color = BLACK;
				uncle_x->color = BLACK;	
				grand_parent_x->color = RED;
				x = grand_parent_x;
			} 
			else 
			{
				/*
				*	Case: 2
				*	x is the right child of its parent.
				*	Do left-rotation
				*/
				if(x == parent_x->right)
				{
					rotate_left(root, parent_x);
					x = parent_x;
					parent_x = x->parent;
				}

				/*
				*	Case: 3
				*	x is left child of its parent.
				*	Do right-rotation
				*/
				rotate_right(root, grand_parent_x);
				std::swap(parent_x->color, grand_parent_x->color);
				x = parent_x;
			}
		}
		// If x's parent is the RIGHT child of its grandparent.
		else if (parent_x == grand_parent_x->right)
		{
			Node *uncle_x = grand_parent_x->left;

			/* 
			* 	Case: 1
			*	The uncle if x is also RED.
			*	Only do recoloring.
			*/
			if((uncle_x != nullptr) &&(uncle_x->color == RED))
			{
				grand_parent_x->color = RED;
				parent_x->color = BLACK;
				uncle_x->color = BLACK;
				x = grand_parent_x;
			}
			else
			{
				/* 
				*	Case: 2
				*	x is left child of its parent.
				*	Do right-rotation.
				*/
				if(x == parent_x->left)
				{
					rotate_right(root, parent_x);
					x = parent_x;
					parent_x = x->parent;
				}
				/*
				*	Case: 3
				*	x is right child of its parent.
				*	Do left-rotation.
				*/
				rotate_left(root, grand_parent_x);
				std::swap(parent_x->color, grand_parent_x->color);
				x = parent_x;

			}
		}
		else
		{
			// Should never reach here.
			std::cout << "[!] Possible problem in fix_violation()" << std::endl;
		}
	}

	// Root must always be a BLACK node. This does not violate any 
	// properties of RBT.
	root->color = BLACK;
}
// ----------------------------------------------------------------------------
// private: rotate_left()
// ----------------------------------------------------------------------------
void RB_tree::rotate_left(Node *&root, Node *&x)
{
	Node *y = x->right;	// Assign new temporary var y to x right child.
	x->right = y->left;	// x's right child becomes y's left child.

	if (x->right != nullptr) // Makes sure y's old left child points back to x.
		x->right->parent = x;	

	y->parent = x->parent;

	// 3 cases to check for about x's old parent
	// Case 1: x was root
	if(x->parent == nullptr)
		root = y;

	// Case 2: if x was the left child of its parent, have it point to y.
	else if (x == x->parent->left)
		x->parent->left = y;

	// Case 3: if x was the right child of its parent, have it point to y.
	else
		x->parent->right = y;

	// Finally, link x node and y node with each other
	y->left = x;
	x->parent = y;
}
// ----------------------------------------------------------------------------
// private: rotate_right()
// ----------------------------------------------------------------------------
void RB_tree::rotate_right(Node *&root, Node *&x)
{
	// All of this a mirrored process of rotate_left(). All instances of
	// 'left' and 'right' are swapped to create rotate_right().

	Node *y = x->left;
	x->left = y->right;

	if (x->left != nullptr)
		x->left->parent = x;

	y->parent = x->parent;

	if (x->parent == nullptr)
		root = y;

	else if (x == x->parent->left)
		x->parent->left = y;

	else
		x->parent->right = y;

	y->right = x;
	x->parent = y;
}
// ----------------------------------------------------------------------------
// private: depth_helper()
// ----------------------------------------------------------------------------
int RB_tree::depth_helper(Node *&root)
{
	if(root == nullptr)
		return 0;

	else
	{
		int left_depth = depth_helper(root->left);
		int right_depth = depth_helper(root->right);

		if(left_depth > right_depth)
			return (left_depth + 1);
		else
			return (right_depth + 1);
	}
}
// ----------------------------------------------------------------------------
// private: BH_helper()
// ----------------------------------------------------------------------------
int RB_tree::BH_helper(Node *&root)
{
	if(root == nullptr)
		return 0;

	else
	{
		int left_depth = BH_helper(root->left);
		int right_depth = BH_helper(root->right);

		if((root->color == BLACK) && (left_depth > right_depth))
			return (left_depth + 1);
		else if ((root->color == BLACK) && (left_depth <= right_depth))
			return (right_depth + 1);
		else
			return (left_depth < right_depth) ? left_depth : right_depth;
	}
}
// ----------------------------------------------------------------------------
// private: inorder_helper()
// ----------------------------------------------------------------------------
void RB_tree::inorder_helper(Node *&root)
{
	if (root == nullptr)
		return;

	inorder_helper(root->left);
	std::cout << "  " << root->key << std::endl;
	inorder_helper(root->right);
}
// ----------------------------------------------------------------------------
// private: preorder_print_helper()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print_helper(Node *&root)
{
	if(root == nullptr)
		return;	

	std::cout << " " << root->key << std::endl;
	preorder_print_helper(root->left);
	preorder_print_helper(root->right);
}
// ----------------------------------------------------------------------------
// private: inorder_process_helper()
// ----------------------------------------------------------------------------
template<class Process>
void RB_tree::inorder_process_helper(Node *&root, Process f)
{
	if (root == nullptr)
		return;

	inorder_process_helper(root->left, f);
	f(root->key, root->color);
	inorder_process_helper(root->right, f);
}
// ----------------------------------------------------------------------------
// private: cleanup_helper()
// ----------------------------------------------------------------------------
void RB_tree::cleanup_helper(Node *&root)
{
	if((root != NULL) || (root != nullptr))
	{
		cleanup_helper(root->left);
		cleanup_helper(root->right);
		delete root;
		root = NULL;
	}
}
// ----------------------------------------------------------------------------// ----------------------------------------------------------------------------
#endif // RED_BLACK_TREE_H_INCLUDE	


// ~Fin