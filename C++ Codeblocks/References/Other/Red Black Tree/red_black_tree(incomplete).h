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
*	LU: 01/28/16
*/

#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include <iostream>

// ----------------------------------------------------------------------------
struct node
{
	int key;
	char color;
	node *parent;
	node *left;
	node *right;
};

// ----------------------------------------------------------------------------
class RBtree
{
public:
	RBtree()
	{
		root=NULL;
		q=NULL;
	}

	/* Inserts a node into the red-black tre and calls insertfix at the end */
	void insert();
	void insertfix(node *t);
	void leftrotate(node *t);
	void rightrotate(node *t);
	void del();
	node* successor(node *t);
	void delfix(node *t);
	void disp();
	void display(node *t);
	void search();

private:
	node *root;
	node *q;
};

// ----------------------------------------------------------------------------
void RBtree::insert()
{
	int z, i =0; // z will take the key from user. 
	node *p, *q; // node* temporary helper variables
	
	cout <<"\nEnter key of the node to be inserted: ";
	cin >> z;

	node *t = new node;
	t->key=z;
	t->left=NULL;
	t->right=NULL;
	t->color='R';
	p=root;
	q=NULL;

	// If we have no tree at all, the inserted values will become root.
	if(root == NULL)
	{
		root = t;
		t->parent = NULL;
	}

	// Find appropriate location for node
	else
	{
		while(p != NULL)
		{
			q = p;
			if(p->key < t->key)
				p = p->right;
			else // (p->key < t->key)
				p = p->left;
		}
		t->parent = q;
		if(q->key < t->key)
			q->right = t;
		else // (q->key > t->key)
			q->left = t;
	}

	// Fiqure out the color of the node
	insertfix(t);
}

// ----------------------------------------------------------------------------
void RBtree::insertfix(node *t)
{
	node *u;
	node *g;
	// If we have a new tree, the node is BLACK; Base case
	if(root == t)
	{
		t->color = 'B';
		return;
	}

	// Otherwise, 
	while((t->parent != NULL ) && (t->parent->color=='R'))
	{
		g = t->parent->parent;

		// t's parent on left-side
		if(g->left == t->parent)
		{
			if(g->right != NULL)
			{
				//...
			}
			else
			{
				//...
			}
		}

		// t's parent on right-side
		else
		{
			if(g->left != NULL)
			{
				u = g->left;
				if(u->color == 'R')
				{
					t->parent->color = ""
				}
			}
			else
			{

			}
		}
	}
}

// ----------------------------------------------------------------------------

#endif // RED_BLACK_TREE_H_
#endif // RED_BLACK_TREE_H_INCLUDE	




