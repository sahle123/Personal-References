/*
*    Written By: Sahle A. Alturaigi
*
*    Date: Apr 25, 2012
*    Binary search tree implementation file.
*
*/

#include<iostream>
#include<cstdlib>
#include "bst.h"
using namespace std;

template<class Item, class Key>
void print_out(Item &data, Key &k);
template<class Item, class Key>
void add_it(Item &data, Key &k);
template<class Item, class Key>
void multi(Item &data, Key &k);

int main()
{

     bstNode<int, size_t> *root_ptr = NULL;

     cout << "Tree size: " << root_ptr->tree_size(root_ptr) << endl; // Working
     cout << "Tree depth:  " << root_ptr->tree_depth(root_ptr) << endl; // Working

     // tree_copy: working
     bstNode<int, size_t> *copy_root_ptr = copy_root_ptr->tree_copy(root_ptr);
     copy_root_ptr->inorder_processing(copy_root_ptr, print_out<int, size_t>);

     // tree_clear: working
     copy_root_ptr->tree_clear(copy_root_ptr);

     // balance_bst
     root_ptr->balance_bst(root_ptr);

     // Process to check for Key value 100: Working
     bstNode<int, size_t> *check = NULL;
     check = check->get_node(copy_root_ptr, 100);
     if(!check)
          cout << "Error, the specified key was not found." << endl;

     // Print out function: Working
     root_ptr->inorder_processing(root_ptr, print_out<int, size_t>);

     // Validation: Working (May need checking)
     bool validation = root_ptr->validate_bst(root_ptr);
     if(!validation)
          cout << "Error, this is an invalid binary search tree." << endl;
     else
          cout << "This is a valid binary search tree." << endl;

     // Insert functions: Working
     root_ptr->insert_node(root_ptr, 600, 6000);
     root_ptr->insert_node(root_ptr, 200, 2000);
     root_ptr->insert_node(root_ptr, 500, 5000);
     root_ptr->insert_node(root_ptr, 900, 9000);
     root_ptr->insert_node(root_ptr, 300, 3000);
     root_ptr->insert_node(root_ptr, 800, 8000);
     root_ptr->insert_node(root_ptr, 700, 7000);
     root_ptr->insert_node(root_ptr, 100, 1000);

     cout << "Preorder: " << endl;
     root_ptr->preorder_processing(root_ptr, print_out<int, size_t>);
     cout << "\nPostorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);
     cout << "\nInorder: " << endl;
     root_ptr->inorder_processing(root_ptr, print_out<int, size_t>);

     // tree_size: Working
     cout << "\nTree size: " << root_ptr->tree_size(root_ptr) << endl;

      bool validation2 = root_ptr->validate_bst(root_ptr);
     if(!validation2)
          cout << "Error, this is an invalid binary search tree." << endl;
     else
          cout << "This is a valid binary search tree." << endl;

     bstNode<int, size_t> *copy2_root_ptr = copy2_root_ptr->tree_copy(root_ptr);
     copy2_root_ptr->inorder_processing(copy2_root_ptr, print_out<int, size_t>);

     copy2_root_ptr->insert_node(copy2_root_ptr, 601, 6001);
     copy2_root_ptr->insert_node(copy2_root_ptr, 201, 2001);
     copy2_root_ptr->insert_node(copy2_root_ptr, 501, 5001);

     cout << "Tree size: " << copy2_root_ptr->tree_size(copy2_root_ptr) << endl;

     copy2_root_ptr->tree_clear(copy2_root_ptr);

     cout << "Preorder: " << endl;
     root_ptr->preorder_processing(root_ptr, print_out<int, size_t>);

     copy2_root_ptr->inorder_processing(copy2_root_ptr, print_out<int, size_t>);

     cout << "Tree depth: " << root_ptr->tree_depth(root_ptr) << endl;

     root_ptr->balance_bst(root_ptr);
     cout <<"Binary search tree has been rebalanced." << endl;

     cout << "Inorder: " << endl;
     root_ptr->inorder_processing(root_ptr, print_out<int, size_t>);

     cout << "Tree depth: " << root_ptr->tree_depth(root_ptr) << endl;

     if (root_ptr->get_node(root_ptr, 300) != NULL)
          cout << "A node with this key value is present\n";
     else
          cout << "that node could not be found\n";

     root_ptr->insert_node(root_ptr, 60, 600);
     root_ptr->insert_node(root_ptr, 2000, 20000);
     root_ptr->insert_node(root_ptr, 5000, 50000);
     root_ptr->insert_node(root_ptr, 90, 900);

     if (root_ptr->validate_bst(root_ptr))
          cout << "This is a valid search tree\n";
     else
          cout << "this is not a binary search tree\n";

     cout << "Postorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);

     cout << "adding 1000\n";
     root_ptr->inorder_processing(root_ptr, add_it<int, size_t>);

     cout << "Postorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);

     cout << "Multiplying\n";
     root_ptr->inorder_processing(root_ptr, multi<int, size_t>);

     cout << "Postorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);

     root_ptr->remove_node(root_ptr, 900);

     cout << "Postorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);

     root_ptr->remove_node(root_ptr, 100);

     root_ptr->remove_node(root_ptr, 5000);

     cout << "Postorder: " << endl;
     root_ptr->postorder_processing(root_ptr, print_out<int, size_t>);

     cout << "root_ptr tree size: "<<root_ptr->tree_size(root_ptr) << endl;

     cout << "copy_ptr tree size: "<< copy_root_ptr->tree_size(copy_root_ptr) << endl;

     cout << "copy2_ptr tree size: "<< copy2_root_ptr->tree_size(copy_root_ptr) << endl;

     return EXIT_SUCCESS;
}

template<class Item, class Key>
void print_out(Item &data, Key &k)
{
     cout << "Item: " << data << "  " << "Key: " << k << endl;
}

template<class Item, class Key>
void add_it(Item &data, Key &k)
{
     if((k >599) && (k < 999))
     {
          data += 1000;
     }
}

template<class Item, class Key>
void multi(Item& data, Key& k)
{
    if (k > 399 && k < 5999)
    {
        data *= 20;
    }
}
