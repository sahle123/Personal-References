//
//  Header.h
//  Assignment 4
//
//  Created by Jacob Rail on 4/29/12.
//
//

#ifndef Assignment_4_Header_h
#define Assignment_4_Header_h
#include <iostream>
#include <cstdlib>

template <class Key, class Item>
class bstNode{
public:
    std::size_t tree_size(const bstNode<Item, Key>* root);
    void tree_clear(bstNode<Item, Key>*& root);
    bstNode<Item, Key>* tree_copy(const bstNode<Item, Key>*& root);
    std::size_t tree_depth(const bstNode<Item, Key>* root);
    bool validate_bst(const bstNode<Item, Key>* root);
    void insert_node(bstNode<Item, Key>*& root, const Key& number,
                     const Item& entry);
    void remove_node(bstNode<Item, Key>*& root, const Key& number);
    // ...
    bool process_node (bstNode<Item, Key>*&, Key k, Process f, Param p);
    void balance_bst(bstNode<Item, Key*& root);



    Key get_data() {return k;}
    void create_balanced_bst(bstNode<Item, Key>*& root, Key array);
    void create_array(bstNode<Item, Key>* root, Key& array,  unsigned int size)
private:
    Key k;
    Item it;
    bstNode<Item, Key> *left_feild = NULL;
    bstNode<Item, Key> *right_feild = NULL;
};
// ---------------------------------------------------------------
// ---------------------------------------------------------------
template <class Item, class Key>
std::size_t tree_size(const bstNode<Item, Key>* root){
    if (*root == NULL) { return 0; }

    return tree_size(root->left_feild) + 1
    + tree_size(root->right_feild) + 1;
}
// ---------------------------------------------------------------
template <class Item, class Key>
void tree_clear(bstNode<Item, Key>*& root){
    if (root != NULL) {
    tree_clear(root->left_feild);
    tree_clear(root->right_feild);
    }

    delete root;
    root = NULL;
}
// ---------------------------------------------------------------
template <class Item, class Key>
bstNode<Item, Key>* tree_copy(const bstNode<Item, Key>*& root){
    bstNode<Item> *left_ptr;
    bstNode<Item> *right_pr;

    if (root == NULL) { return NULL }
    tree_copy (root->left_feild);
    tree_copy (root->right_feild);

    return new bstNode<Item> (root->k, left_ptr, right_ptr);
}
// ---------------------------------------------------------------
template <class Item, class Key>
std::size_t tree_depth(const bstNode<Item, Key>* root){
    if (root == NULL) {return 0;}

    bstNode<Item, Key> left_side = tree_depth(root->left_feild);
    bstNode<Item, Key> right_side = tree_depth(root->right_feild);

    if (left_side > right_side) {
        return left_side + 1;
    }
    else{
        return right_side + 1;
    }
}
// ---------------------------------------------------------------
template<class Item, class Key>
bool validate_bst(const bstNode<Item, Key>* root){
    if (root == NULL) {
        return true;
    }

    if (root->left_feild->k > root->k
        || root->right_feild->k < root->k)
    {
        return false;
    }

    return (validate_bst(root->left_feild) && validate_bst(root->right_feild));
}
// ---------------------------------------------------------------
template <class Item, class Key>
void insert_node(bstNode<Item, Key>*& root, const Key& number,
                 const Item& entry){

    if (root == NULL){
        root = new bstNode<Item, Key> (number, entry)
    }
    else if (number <= root) {
        insert_node(root->left_feild, number, entry);
    }
    else{
        insert_node(root->right_feild, number, entry);
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void remove_node(bstNode<Item, Key>*& root, const Key number){
    if (root != NULL) {
        if (number < root->k) {
            remove_node(root->left_feild, number);
        }
        else if(number > root->k){
            remove_node(root->right_feild, number);
        }
        else{
            if (root->left_feild != NULL && root->right_feild != NULL) {
                bstNode<Item, Key>* temp = root->right_feild;
                while (temp != NULL) {
                    root->k = temp->get_data;
                    temp = temp->left_feild;
                }
                remove_node(root->right_feild, root->k);
            }
            else if(root->left_feild != NULL){
                bstNode<Item, Key>* temp = root->left_feild;
                bstNode<Item, Key>* temp2 = root->left_feild;
                temp = temp->left_feild;
                root = temp;
                delete temp2;
            }
            else if(root->right_feild != NULL){
                bstNode<Item, Key>* temp = root->right_feild;
                bstNode<Item, Key>* temp2 = root->right_feild;
                temp = temp->right_feild;
                root = temp;
                delete temp2;
            }
            else{
                delete root;
            }
        }
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
bool process_node (bstNode<Item, Key>*&, Key k, Process f, Param p){
    if (root == NULL) return false;
    else if(k , root->k){
        return process_node(node->left_feild, k, f, p);
    }
    else if(k > root->k){
        return process_node(root->right_feild, k, f, p);
    }
    else{
        f(root->it, p);
        return true;
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void create_balanced_bst(bstNode<Item, Key>*& root, Key& array, unsigned int size){
    if (size == 0) {
        bstNode<Item, Key> new_child = new bstNode<Item, Key> (root, array[size])
    }
    else{
        Key *low_list = new Key[size/2];
        Key *high_list = new Key[size/2];
        for (unsigned int i = 0; i < size; ++i) {
            if (i == size/2) root->k = array[i];
            else if (i < size/2) low_list[i];
            else high_list[i - size/2 - 1];

            delete [] array;

            create_balanced_bst(root->left_feild, low_list);
            create_balanced_bst(root->right_feild, hig_list);
        }

    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void create_array(bstNode<Item, Key>* root, Key& array, unsigned int& size){
    if (root==NULL) {
        size = 0;
    }
    else{
        create_array(root->left_feild, array, size + 1);
        create_array(root->right_feild, array, size + 1);

        array[size] = root->k;
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void balance_bst(bstNode<Item, Key>*& root){

    size = root->tree_size;
    Key array = new Key[root->tree_size];
    create_array(root, array, size);

    root->tree_clear;

    create_balanced_bst(root, array, size);

    }
}
// ---------------------------------------------------------------
// ---------------------------------------------------------------













#endif
