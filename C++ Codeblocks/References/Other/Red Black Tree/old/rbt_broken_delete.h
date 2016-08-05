#ifndef RBT_BROKEN_DELETE_H_INCLUDE
#define RBT_BROKEN_DELETE_H_INCLUDE

/* rbt_broken_delete.h
*
*	Failed implementation code for delete method in RBT.
*   This code is only a reference in case I need to revert
*   back code.
*
*	LU: 03/17/16
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
	void preorder_print_debug_helper(Node *&root);

	// Helper for inorder_process	
	template<class Process>
	void inorder_process_helper(Node *&root, Process f);

	// Helper for cleanup()
	void cleanup_helper(Node *&root);

	/* remove() helper section */
	void bst_remove(Node *&root, const k_int &targetKey);
	void remove_one_child_case(Node *&root, const k_int &targetKey); // Handles first two cases or determines if there is 'double black' case.
	void double_black_case(Node *&root, const k_int &targetKey);
	k_int getSmallestNode(Node *&root); // Returns smallest node's key in subtree.

	
public:
	// Constructor
	RB_tree() : root(nullptr) {}

	// Insert method
	void insert(const k_int &key);

	// Tree printing methods
	void inorder_print();
	void preorder_print();
	void preorder_print_debug();

	// Callback method that occurs for each node in the tree in order.
	template<class Process>
	void inorder_process(Process f);

	// Gets the depth and 'black height' of tree.
	void tree_depth();

	// Cleanup method to call once at the end of the program.
	// If this method isn't called, there will be memory leaks.
	void cleanup();

	// Remove method. Deletes specified node or does nothing if node 
	// is not found.
	void remove(const k_int &targetKey);


};	// End RB_tree class


// ----------------------------------------------------------------------------
// insert()
// Dependencies: bst_insert(), fix_violation()
// ----------------------------------------------------------------------------
void RB_tree::insert(const k_int &key)
{
	Node *neoNode = new Node(key);

	bst_insert(root, neoNode);

	// If a node is inserted with a key that already exists, neoNode
	// will be set to NULL in bst_insert. We don't want duplicate nodes.
	if((neoNode != nullptr) && (neoNode != NULL))
		fix_violation(root, neoNode);
}
// ----------------------------------------------------------------------------
// inorder_print()
// ----------------------------------------------------------------------------
void RB_tree::inorder_print()
{
	if((root == NULL) || (root == nullptr))
	{
		std::cout << "[-] Error: Tree is empty. Cannot do inorder_print()" << std::endl;
		return;
	}
	std::cout << "In order print:" << std::endl;
	inorder_helper(root);
}
// ----------------------------------------------------------------------------
// preorder_print()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print()
{
	if((root == NULL) || (root == nullptr))
	{
		std::cout << "[-] Error: Tree is empty. Cannot do preorder_print()" << std::endl;
		return;
	}
	std::cout << "Preorder print:" << std::endl;
	preorder_print_helper(root);
}
// ----------------------------------------------------------------------------
// preorder_print_debug()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print_debug()
{
	if((root == NULL) || (root == nullptr))
	{
		std::cout << "[-] Error: Tree is empty. Cannot do preorder_debug()" << std::endl;
		return;
	}
	std::cout << "Preorder print:" << std::endl;
	preorder_print_debug_helper(root);
}
// ----------------------------------------------------------------------------
// inorder_process()
// ----------------------------------------------------------------------------
template<class Process>
void RB_tree::inorder_process(Process f)
{
	if((root == NULL) || (root == nullptr))
	{
		std::cout << "[-] Error: Tree is empty. Cannot do inorder_process()" << std::endl;
		return;
	}
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
	std::cout << std::endl; // Line break
}
// ----------------------------------------------------------------------------
// cleanup()
// ----------------------------------------------------------------------------
void RB_tree::cleanup()
{
	std::cout << "\n[+] Cleaning up tree to avoid memory leaks... ";

	// Double checking tree isn't already empty
	if ((root != NULL) || (root != nullptr))
		cleanup_helper(root);

	// I used NULL on purpose! Since we're deleting the nodes, we
	// don't want them branded as nullptr.
	if(root != NULL)
		std::cout << "\n[!] Had an issue cleaning up tree. Check RB_tree::cleanup_helper(), red_black_tree.h" << std::endl; 
	else
		std::cout << "Successfully cleared tree!" << std::endl;
}
// ----------------------------------------------------------------------------
// remove()
// ----------------------------------------------------------------------------
void RB_tree::remove(const k_int &targetKey)
{
	// Fringe case
	if(root == nullptr)
	{
		std::cout << "[-] Error: Tree is empty. Nothing to delete..." << std::endl;
		return;
	}

	std::cout << "[+] Deleting key (" << targetKey << ") from tree" << std::endl;
	bst_remove(root, targetKey);

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
	// needing to create a separate method for this base case and, 
	// also, to keep track of the parent later on.
	static Node *previous = nullptr;

	if(root == nullptr)
	{
		root = neoNode;
		neoNode->parent = previous;
	}
	else if (root->key == neoNode->key)
	{
		std::cout << "[-] There is already a copy of " << neoNode->key << " in the tree. Skipping..." << std::endl;
		delete neoNode;
		neoNode = NULL;	
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
			if((uncle_x != nullptr) && (uncle_x->color == RED))
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
// private: preorder_print_helper()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print_helper(Node *&root)
{
	if(root == nullptr)
		return;	

	std::cout << "  " << root->key << std::endl;
	preorder_print_helper(root->left);
	preorder_print_helper(root->right);
}
// ----------------------------------------------------------------------------
// private: preorder_print_debug_helper()
// ----------------------------------------------------------------------------
void RB_tree::preorder_print_debug_helper(Node *&root)
{
	if(root == nullptr)
		return;	

	std::cout << "  " << root->key << " - " << root->color << std::endl;
	preorder_print_debug_helper(root->left);
	preorder_print_debug_helper(root->right);
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
// ----------------------------------------------------------------------------
// private: bst_remove()
// ----------------------------------------------------------------------------
void RB_tree::bst_remove(Node *&root, const k_int &targetKey)
{
	
	Node* currentNode = root;

	// Fringe case
	if((currentNode == nullptr) || (currentNode == NULL))
		return;

	/* Handle 3 simple cases or 'Double black' cases */
	if(currentNode->key == targetKey)
	{
		// If there is AT MOST 1 non-null child, proceed to cases 1, 2 or 
		// 'Double black' case.
		if(!((currentNode->left != nullptr) && (currentNode->right != nullptr)))
		{
			std::cout << "[DEBUG] Running remove_one_child" << std::endl;
			remove_one_child_case(currentNode, targetKey); // try using root if current node doesn't work properly
		}
		//	Case 3: If node to be deleted has two non-null children, replace
		//	in order successor. No recoloring should be required.
		else
		{
			k_int inorderSuccessor = getSmallestNode(currentNode);
			if(inorderSuccessor != 0)
			{	
				std::cout << "[+] inorderSuccessor for " << currentNode->key << " is: " << inorderSuccessor << std::endl;
				currentNode->key = inorderSuccessor;
			}
		}
	}
	else
	{
		bst_remove(currentNode->left, targetKey);
		bst_remove(currentNode->right, targetKey);
	}
}
// ----------------------------------------------------------------------------
// private: remove_one_child
// Requires, at most, 0 or 1 non-null children in subtree.
// Handles Cases 1, 2, or detects 'double black' case and runs subroutine.
// Parameter 'root' is the reference subtree root node we are deleting.
/// NOTE that targetKey is NOT used here. May need to remove at the end.
// ----------------------------------------------------------------------------
void RB_tree::remove_one_child_case(Node *&root, const k_int &targetKey)
{
	/* Note: code here could be refactored for better readability, but
	I feel the code present is robust with all these if statements constantly checking that exact states of the tree are met at all points. */

	Node *currentNode = root;
	Node *childDependency = nullptr;

	// Fringe case where node to be deleted is the root of the tree.
	// and there is a "4-2-1-3" case or right-hand "4-2-1-3" case.
	// Note the we will NOT delete root node since that is the responsiblity
	// of cleanup() method.
	/// Implement later
	if(currentNode->parent == nullptr)
	{
		std::cout << "[DEBUG] CANNOT DELETE ROOT FOR NOW..." << std::endl;
		//std::cout << "[DEBUG] Handling root node removal" << std::endl;
		/*if(currentNode->left != nullptr)
		{
			currentNode = currentNode->left;
			root->key = currentNode->key;
			root->left = nullptr;

			delete currentNode;
			currentNode = NULL;
		}
		else if (currentNode->right != nullptr)
		{
			currentNode = currentNode->right;
			root->key = currentNode->key;
			root->right = nullptr;

			delete currentNode;
			currentNode = NULL;
		}
		else
			cleanup();*/
		return;
	}

	// Determine if currentNode has 0 or 1 children and assign to local var.
	if((currentNode->left != nullptr) && (currentNode->right == nullptr))
		childDependency = currentNode->left;
	else if ((currentNode->left == nullptr) && (currentNode->right != nullptr))
		childDependency = currentNode->right;
	// Else: Both children are nullptr, so childDependency stays nullptr
		
	// Setup connection between child and grandparent if applicable
	// and handle Cases 1 and 2.
	if(childDependency != nullptr)
	{
		// Setup connection between child and grandparent.
		if(currentNode == currentNode->parent->left)
			currentNode->parent->left = childDependency;
		else if (currentNode == currentNode->parent->right)
			currentNode->parent->right = childDependency;
		else
		{
			// Should be unreachable point.
			std::cout << "[DEBUG] ERROR: check remove_one_child() method, childDependency Connection section" << std::endl;
			return;
		}

		// Case 1: If node to be deleted is RED, then just delete RED node.
		if(currentNode->color == RED)
		{
			delete currentNode;
			return;
		}

		// Case 2: If node to be deleted is BLACK, but has one RED child,
		// then replace it with that child and change color to BLACK.
		else if ((currentNode->color == BLACK) && (childDependency->color == RED))
		{
			childDependency->color = BLACK;
			delete currentNode;
			return;
		}
		/* 'DOUBLE BLACK' situation. 
		There are 6 sub-cases and we start at case 1. 
		Cases 1, 4, and 6 are terminating cases. 
		If they run, the RBT should be valid. 

		This section is detailed and you should refer to your notes for
		graphical information and reasoning. 
		*/
		else
		{
			// Might need a reference to root of RB tree.
			double_black_case(root, targetKey);
		}
	}
	// Bottom tier node. Just delete it. Nice and simple :)
	else 
	{
		if(currentNode->parent->left == currentNode)
		{
			currentNode->parent->left = nullptr;
			delete currentNode;
			return;
		}
		else if (currentNode->parent->right == currentNode)
		{
			currentNode->parent->right = nullptr;
			delete currentNode;
			return;
		}
		else
		{
			// Should be unreachable point.
			std::cout << "[DEBUG] ERROR: check remove_one_child() method, Bottom Tier Node section" << std::endl;
			return;
		}

	}
}
// ----------------------------------------------------------------------------
// private: double_black_case()
// ----------------------------------------------------------------------------
void RB_tree::double_black_case(Node *&root, const k_int &targetKey)
{
	std::cout << "[DEBUG] DOUBLE BLACK CASE" << std::endl;
}
// ----------------------------------------------------------------------------
// private: getSmallestNode()
// Finds the smallest node in the given subtree. If found, then the smallest
// node is deleted and its key value is returned. Otherwise, 0 is returned
// to indicate an error or empty tree.
// ----------------------------------------------------------------------------
k_int RB_tree::getSmallestNode(Node *&root)
{
	Node *subtree = root->right;
	Node *prev = nullptr;
	k_int result = 0;

	std::cout << "[DEBUG] Running getSmallestNode()" << std::endl;
	// Find the in order successor node.
	while(subtree != nullptr)
	{
		prev = subtree;
		subtree = subtree->left;
	}

	if (prev != nullptr)
	{
		// Double checking to make sure child is left of parent.
		// This step is unnecessary, but I like to be safe.
		if (prev == prev->parent->left)
		{
			// Double checking that the RB tree is valid. 
			// Again, this is an unnecessary step, but I do it for safety.
			if (prev->right != nullptr)
			{
				std::cout << "[-] Issue in findSmallestNode(). RB Tree appears to be in violation." << std::endl;
				return 0;
			}

			// Uncouple the node and its parent then proceed to delete node
			// and return the key value.
			prev->parent->left = nullptr;
			prev->parent = nullptr;
			result = prev->key;
			delete prev;
			return result;	// We should get the key of the recently deleted node.
		}
		// Fringe case. At second last bottom tier of tree. Just make right 
		// node the new parent. Still valid RBT.
		else if(prev == prev->parent->right)
		{
			prev->parent->right = nullptr;
			prev->parent = nullptr;
			result = prev->key;
			delete prev;
			return result;
		}
		else
			std::cout << "[-] Could not find inorderSuccessor" << std::endl;
	}
	return 0;
}
// ----------------------------------------------------------------------------// ----------------------------------------------------------------------------
#endif // RBT_BROKEN_DELETE_H_INCLUDE


// ~Fin