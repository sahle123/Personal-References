/*
*    Written by: Sahle A. Alturaigi
*
*    Date: Apr 25, 2012
*    Binary search tree header.

std::size_t tree_size(const bstNode<Item, Key>* root);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: The function returns the number of nodes in the binary search tree.

void tree_clear(bstNode<Item, Key>*& root);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: The function deletes all nodes of the binary search tree and sets root to NULL.

bstNode<Item, Key>* tree_copy(const bstNode<Item, Key>*& root);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: The function creates a copy of the binary search tree and returns a pointer to the root of the copy.

std::size_t tree_depth(const bstNode<Item, Key>* root);
     // Precondition: root is a pointer to the root of a binary tree.
     // Postcondition: The function returns the depth (number of levels) of the binary search tree.

bool validate_bst(const bstNode<Item, Key>* root);
     // Precondition: root is a pointer to the root of a binary tree.
     // Postcondition: The function returns true if the binary tree pointed to by root is a binary search tree. Otherwise the function returns false.

void insert_node(bstNode<Item, Key>*& root, const Key& k, const Item& entry);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: A new binary search tree node containing the given item entry and key k has been inserted in the binary search tree.

void remove_node(bstNode<Item, Key>*& root, const Key& k);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: If a node with key k was present in the given binary search tree, that node has been removed.

bstNode<Item, Key>* get_node(const bstNode<Item, Key> *root, const Key& k);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: If a node with the given key k is present in the binary search tree, a pointer to that node is returned. Otherwise, the function returns NULL.

void inorder_processing(bstNode<Item, Key>*& root, Process f);
     // Precondition: root is a pointer to the root of a binary search tree. Process is an additional template parameter of this function.
     // Postcondition: The function f has been activated for each item in the binary search tree using in-order traversal.

void preorder_processing(bstNode<Item, Key>*& root, Process f);
     // Precondition: root is a pointer to the root of a binary search tree. Process is an additional template parameter of this function.
     // Postcondition: The function f has been activated for each item in the binary search tree using pre-order traversal.

void postorder_processing(bstNode<Item, Key>*& root, Process f);
     // Precondition: root is a pointer to the root of a binary search tree. Process is an additional template parameter of this function.
     // Postcondition: The function f has been activated for each item in the binary search tree using post-order traversal.

bool process_node (bstNode<Item, Key>*& root, Key k, Process f, Param p);
     // Precondition: root is a pointer to the root of a binary search tree. Process and Param are additional template parameters of this function.
     // Postcondition: If the item with key k is present in the binary search tree, then the function f has been activated for that item and the return value is true.
     // Otherwise, the return value is false. Function f takes two parameters: Item and Param.

void balance_bst(bstNode<Item, Key>*& root);
     // Precondition: root is a pointer to the root of a binary search tree.
     // Postcondition: The given binary search tree is converted to a well-balanced binary search tree. A well-balanced binary search tree is a binary search tree
     // with minimum possible depth.
*/

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include<iostream>
#include<cstdlib>

template<class Item, class Key>
class bstNode {
public:

     /// Constructors
     bstNode<Item, Key> (Item entry2, Key k2)
     {
          it = entry2;
          k = k2;
          left_child = NULL;
          right_child = NULL;
     }

     bstNode<Item, Key> (Key k2, Item entry, bstNode<Item, Key> *left, bstNode<Item, Key> *right)
     {
          k = k2;
          it = entry;
          left_child = left;
          right_child = right;
     }

     bstNode<Item, Key> (bstNode<Item, Key> *root)
     {
          k = root->k;
          it = root->it;
          left_child = NULL;
          right_child = NULL;
     }

//---------------------------------------------------------------------------------------------------------------------------------------------------
     /// Void Mod Functions.
     void insert_node(bstNode<Item, Key> *&root, const Key &number, const Item &entry);
     void remove_node(bstNode<Item, Key>*& root, const Key& number);

     template<class Process>
     void inorder_processing(bstNode<Item, Key> *&root, Process f);
     template<class Process>
     void preorder_processing(bstNode<Item, Key> *&root, Process f);
     template<class Process>
     void postorder_processing(bstNode<Item, Key> *&root, Process f);

     void balance_bst(bstNode<Item, Key>*& root); /// Has a tendency to cause SEG FAULTS
     void tree_clear(bstNode<Item, Key>*& root);

     /// Bool Mod Functions
     bool validate_bst(bstNode<Item, Key> *root);
     template<class Process, class Param>
     bool process_node (bstNode<Item, Key>*& root, Key k, Process f, Param p);

     /// Other Mod Functions
     bstNode<Item, Key>* get_node(bstNode<Item, Key> *root, const Key& k) const;
     bstNode<Item, Key>* tree_copy(bstNode<Item, Key> *&root) const;
     std::size_t tree_size(const bstNode<Item, Key> *root);
     std::size_t tree_depth(const bstNode<Item, Key> *root);
     Key get_data() {return k;}
     Item get_item() {return it;}


private:
     Key k;                              // The Key value of the node.
     Item it;                            // Data stored in the node.
     bstNode<Item, Key> *left_child;     // Left Child. Initialized to NULL
     bstNode<Item, Key> *right_child;    // Right Child. Initialized to NULL

     void bubble_sorter(bstNode<Item, Key> **a, int size);
     void array_to_bst(bstNode<Item, Key> *&root, bstNode<Item, Key> **a, int &begin, int &end, int absolute_end);
     int bst_to_array(bstNode<Item, Key> *&root, bstNode<Item, Key> **a, int size);


}; // End of bstNode class

template<class Item, class Key>
void bstNode<Item, Key>::insert_node(bstNode<Item, Key> *&root, const Key &number, const Item &entry)
{
     if(root == NULL)
          root = new bstNode<Item, Key> (entry, number);

     else if (number <= root->k)
          insert_node(root->left_child, number, entry);

     else
          insert_node(root->right_child, number, entry);
}

template<class Item, class Key>
void bstNode<Item, Key>::remove_node(bstNode<Item, Key>*& root, const Key& number)
{
     if(root != NULL)
     {
          if(number < root->k)
          {
               remove_node(root->left_child, number);
          }
          else if(number > root->k)
          {
               remove_node(root->right_child, number);
          }
     }
     else
     {
          if(root->left_child != NULL && root->right_child != NULL)
          {
               bstNode<Item, Key> *temp = root->right_child;
               while(temp != NULL)
               {
                    root->k = temp->k;
                    temp = temp->left_child;
               }
               remove_node(root->right_child, root->k);
          }
          else if(root->left_child != NULL)
          {
               bstNode<Item, Key> *temp = root->left_child;
               bstNode<Item, Key> *temp2 = root->left_child;
               temp = temp->left_child;
               root = temp;
               delete temp2;
          }
          else if(root->right_child != NULL)
          {
               bstNode<Item, Key> *temp = root->right_child;
               bstNode<Item, Key> *temp2 = root->right_child;
               temp = temp->left_child;
               root = temp;
               delete temp2;
          }
          else
               delete root;
     }
}

template<class Item, class Key>
template<class Process>
void bstNode<Item, Key>::inorder_processing(bstNode<Item, Key>*& root, Process f)
{
     if(root == NULL)
          return;

     inorder_processing(root->left_child, f);
     f(root->it, root->k);
     inorder_processing(root->right_child, f);
}

template<class Item, class Key>
template<class Process>
void bstNode<Item, Key>::preorder_processing(bstNode<Item, Key> *&root, Process f)
{
     if(root == NULL)
          return;

     f(root->it, root->k);
     preorder_processing(root->left_child, f);
     preorder_processing(root->right_child, f);
}

template<class Item, class Key>
template<class Process>
void bstNode<Item, Key>::postorder_processing(bstNode<Item, Key>*& root, Process f)
{
     if(root == NULL)
          return;

     postorder_processing(root->left_child, f);
     postorder_processing(root->right_child, f);
     f(root->it, root->k);
}

template<class Item, class Key>
void bstNode<Item, Key>::tree_clear(bstNode<Item, Key> *& root)
{
     if(root != NULL)
     {
          tree_clear(root->left_child);
          tree_clear(root->right_child);
          delete root;
          root = NULL;
     }
}

template<class Item, class Key>
bool bstNode<Item, Key>::validate_bst(bstNode<Item, Key> *root)
{
     // Old code.
     /*
     if(root == NULL) return true;

     bool left_check = validate_bst(root->left_child);
     bool right_check = validate_bst(root_right_child);
     int left_k = (root->left_child->k);
     int right_k = (root->right_child->k);

     if(left_k < right_k) return true;
     else return false;*/


     if(root == NULL)
          return true;

     return(validate_bst(root->left_child) && validate_bst(root->right_child));

     if ((root->left_child == NULL) && (root->right_child == NULL))
          return true;

     if(((root->left_child->k) > (root->k)) || ((root->right_child->k) < (root->k)))
          return false;


     /* // Improved Validate function
     if(root == NULL) return true;

     Key k_get(Item it, Key k)
     {

     }

     int n = tree_size(root);
     Key *array = new Key[n]; */


}

template<class Item, class Key>
template<class Process, class Param>
bool bstNode<Item, Key>::process_node(bstNode<Item, Key> *&root, Key k, Process f, Param p)
{
     if(root == NULL) return false;
     else if(k < root->k)
          return process_node(root->left_child, k, f, p);
     else if(k > root->k)
          return process_node(root->right_child, k, f, p);

     else
     {
          f(root->it, p);
          return true;
     }
}

template<class Item, class Key>
bstNode<Item, Key>* bstNode<Item, Key>::get_node(bstNode<Item, Key> *root, const Key& k) const
{
     if(root == NULL) return NULL;
     else
     {
          if(k == root->k) return root;
          if(k > root->k)
               return get_node(root->right_child, k);
          else
               return get_node(root->left_child, k);
     }
}

template<class Item, class Key>
bstNode<Item, Key>* bstNode<Item, Key>::tree_copy(bstNode<Item, Key> *&root) const
{
     bstNode<Item, Key> *l_ptr;
     bstNode<Item, Key> *r_ptr;

     if(root == NULL) return NULL;
     else
     {
          l_ptr = tree_copy(root->left_child);
          r_ptr = tree_copy(root->right_child);
          return new bstNode<Item, Key> (root->k, root->it, l_ptr, r_ptr);
     }
}

template<class Item, class Key>
typename std::size_t bstNode<Item, Key>::tree_size(const bstNode<Item, Key> *root)
{
     if(root == NULL) return 0;
     return (1 + tree_size(root->left_child) + tree_size(root->right_child));
}

template<class Item, class Key>
typename std::size_t bstNode<Item, Key>::tree_depth(const bstNode<Item, Key> *root)
{
     if(root == NULL)
          return 0;
     else
     {
          size_t left_depth = tree_depth(root->left_child);
          size_t right_depth = tree_depth(root->right_child);

          if(left_depth > right_depth)
               return (left_depth + 1);
          else if (right_depth > left_depth)
               return (right_depth + 1);
          else
               return 0;
     }
}

template<class Item, class Key>
void bstNode<Item, Key>::balance_bst(bstNode<Item, Key>*& root)
{
     if(root == NULL)
          return;

     int zero = 0;
     int size = tree_size(root);
     bstNode<Item, Key> **array = new bstNode<Item, Key> *[size];

     size = bst_to_array(root, array, zero);

     //bubble_sorter(array, size);
     root->tree_clear(root);
     zero = 0;
     array_to_bst(root, array, zero, size, size); /// Program seg faults here

     // To deallocate data allocated in the bst_to_array function.
    /* for( int i = 0; i < size; ++i)
     {
          delete[]array[i];
     }
     delete[]array;*/

}

// Note: The parameter: begin, never changes in the function
template<class Item, class Key>
void bstNode<Item, Key>::array_to_bst(bstNode<Item, Key> *&root, bstNode<Item, Key> **a, int &begin, int &end, int absolute_end)
{
     if(end < begin)
          return;

     int decrementation = ((begin + end) /2);
     root = a[decrementation];
     std::cout << "Decrementation value: " <<  decrementation << " absolute_end: " << absolute_end << std::endl;
     std::cout << "Item_array: " << root->get_item() << " Key_array: " << root->get_data() << std::endl;
     --decrementation;

     array_to_bst(root->left_child,   a,  begin, decrementation, absolute_end);
     decrementation = decrementation + 2;

     if(absolute_end <= decrementation)
          return;

     array_to_bst(root->right_child, a, decrementation, end, absolute_end);
}


template<class Item, class Key>
int bstNode<Item, Key>::bst_to_array(bstNode<Item, Key> *&root, bstNode<Item, Key> **a, int size)
{
     if(root == NULL) return size;

     size = bst_to_array(root->left_child, a, size);

     a[size] = new bstNode<Item, Key> (root);

     ++size;
     size = bst_to_array(root->right_child, a, size);

     return size;
}

//-----------------------------------------------------------------------------
// Unused
template<class Item, class Key>
void bstNode<Item, Key>::bubble_sorter(bstNode<Item, Key> **a, int size)
{
     bstNode<Item, Key> *temp;
     bool check = false;
     while(!check)
     {
          check = true;
          for(int i = 0; i < size; ++i)
          {
               for(int j = i + 1; j < size; ++j)
               {
                    if(a[i]->k < a[j]->k)
                    {
                         temp = a[i];
                         a[i] = a[j];
                         a[j] = temp;
                         check = false;
                    }
               }
          }
     }
}
#endif // BST_H_INCLUDED
