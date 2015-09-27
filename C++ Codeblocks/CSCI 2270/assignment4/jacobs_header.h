//
//  Header.h
//  Assignment 4
//
//  Created by Jacob Rail on 4/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Assignment_4_Header_h
#define Assignment_4_Header_h
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;


template <class Item, class Key>
class bstNode{
public:
    //CONSTRUCTOR
    bstNode(Key K, Item I){
        k = K;
        it = I;
        left_feild = NULL;
        right_feild = NULL;
    }

    // MEMBER FUNCTIONS
    std::size_t tree_size(const bstNode<Item, Key>* root);
    void tree_clear(bstNode<Item, Key>*& root);
    bstNode<Item, Key>* tree_copy(bstNode<Item, Key>*& root);
    std::size_t tree_depth(const bstNode<Item, Key>* root);
    bool validate_bst(const bstNode<Item, Key>* root);
    void insert_node(bstNode<Item, Key>*& root, const Key& number,
                     const Item& entry);
    void remove_node(bstNode<Item, Key>*& root, const Key& number);
    bstNode<Item, Key>* get_node(const bstNode<Item, Key>* root, const Key& k);
//    void inorder_processing(bstNode<Item, Key>*& root, Process f);
//    void preorder_processing(bstNode<Item, Key>*& root, Process f);
//    void postorder_processing(bstNode<Item, Key>*& root, Process f);
//    bool process_node (bstNode<Item, Key>*&, Key k, Process f, Param p);
    void balance_bst(bstNode<Item, Key>*& root);

    void create_balanced_bst(bstNode<Item, Key>*& root, list<Key> key_list, list<Item> item_list);
    void create_array(bstNode<Item, Key>* root, list<Key>& key_list, list<Item>& item_list);

    Key get_data() {return k;}
    bstNode<Item, Key>* left() {return left_feild;}
    bstNode<Item, Key>* right() {return right_feild;}

private:
    Key k;
    Item it;
    bstNode<Item, Key> *left_feild;
    bstNode<Item, Key> *right_feild;

   };
// ---------------------------------------------------------------
// ---------------------------------------------------------------
template <class Item, class Key>
typename std::size_t bstNode<Item, Key>::tree_size(const bstNode<Item, Key>* root){
    if (root == NULL) { return 0; }
    else{
    return tree_size(root->left_feild) + tree_size(root->right_feild) + 1;
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::tree_clear(bstNode<Item, Key>*& root){
    if (root != NULL) {
    tree_clear(root->left_feild);
    tree_clear(root->right_feild);
    }

    delete root;
    root = NULL;
}
// ---------------------------------------------------------------
template <class Item, class Key>
bstNode<Item, Key>* bstNode<Item, Key>::tree_copy(bstNode<Item, Key>*& root)
{
    bstNode<Item, Key>* root_copy;
    if (root != NULL) {
        root_copy = new bstNode<Item, Key> (root->k, root->it);
        root_copy->left_feild = tree_copy(root->left_feild);
        root_copy->right_feild = tree_copy(root->right_feild);
    }
    else return NULL;

    return root_copy;
}
// ---------------------------------------------------------------
template <class Item, class Key>
typename std::size_t bstNode<Item, Key>::tree_depth(const bstNode<Item, Key>* root){
    if (root == NULL) {return 0;}

    std::size_t left_side = tree_depth(root->left_feild);
    std::size_t right_side = tree_depth(root->right_feild);

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
void bstNode<Item, Key>::insert_node(bstNode<Item, Key>*& root, const Key& number,
                 const Item& entry){

    if (root == NULL){
        root = new bstNode<Item, Key> (number, entry);
    }
    else if (number <= root->get_data()) {
        insert_node(root->left_feild, number, entry);
    }
    else{
        insert_node(root->right_feild, number, entry);
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::remove_node(bstNode<Item, Key>*& root, const Key& number){
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
                    root->k = temp->get_data();
                    temp = temp->left_feild;
                }
                remove_node(root->right_feild, root->k);
            }
            else if(root->left_feild != NULL){
                bstNode<Item, Key>* temp = left_feild;
                bstNode<Item, Key>* temp2 = left_feild;
                temp = temp->left_feild;
                root = temp;
                delete temp2;
            }
            else if(root->right_feild != NULL){
                bstNode<Item, Key>* temp = right_feild;
                bstNode<Item, Key>* temp2 = right_feild;
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
bstNode<Item, Key>* get_node(const bstNode<Item, Key>* root, const Key& number){
    if (number == root->k) return root->k;
    else if (number <= root->k){
        return get_node(root->left_feild, number);
    }
    else{
        return get_node(root->right_feild, number);
    }
}
// ---------------------------------------------------------------
//template <class Item, class Key>
//template <class Process>
//void inorder_processing(bstNode<Item, Key>*& root, Process f){
//    if (root == NULL) return;
//    inorder_processing(root->left_feild);
//    f(root->k);
//    inorder_processing(root->right_feild);
//}
//// ---------------------------------------------------------------
//template <class Item, class Key>
//template <class Process>
//void preorder_processing(bstNode<Item, Key>*& root, Process f){
//    if (root == NULL) return;
//    f(root->k);
//    preorder_processing(root->left_feild, f);
//    preorder_processing(root->right_feild, f);
//}
//// ---------------------------------------------------------------
//template <class Item, class Key>
//template <class Process>
//void postorder_processing(bstNode<Item, Key>*& root, Process f){
//    if (root == NULL) return;
//    postorder_processing(root->left_feild, f);
//    postorder_processing(root->right_feild, f);
//    f(root->k);
//}
//// ---------------------------------------------------------------
//template <class Item, class Key>
//template <class Param>
//bool process_node (bstNode<Item, Key>*&, Key k, Process f, Param p){
//    if (root == NULL) return false;
//    else if(k < root->k){
//        return process_node(node->left_feild, k, f, p);
//    }
//    else if(k > root->k){
//        return process_node(root->right_feild, k, f, p);
//    }
//    else{
//        f(root->it, p);
//        return true;
//    }
//}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::create_balanced_bst(bstNode<Item, Key>*& root, list<Key> key_list, list<Item> item_list){

    bstNode<Item, Key>* new_child;
    if (key_list.size() != 0 && item_list.size() != 0){

//        Key *key_low_list = new Key[size/2];
//        Key *key_high_list = new Key[size/2];
//        Item *item_low_list = new Item[size/2];
//        Item *item_high_list = new Item[size/2];

        std::list<Key> key_low_list;
        std::list<Key> key_high_list;
        std::list<Item> item_low_list;
        std::list<Item> item_high_list;

        for(unsigned int position = 0; position < key_list.size(); ++position) {
            typename list<Key>::iterator i = key_list.begin();
            typename list<Item>::iterator j = item_list.begin();
            if (position == key_list.size()/2){
                new_child = new bstNode<Item, Key>(*i, *j);
            }
            else if (position < key_list.size()/2){
//                key_low_list[i];
//                item_low_list[i];

                key_low_list.push_back(*i);
                item_low_list.push_back(*j);
            }
            else{
//                key_high_list[i - size/2 - 1];
//                item_high_list[i - size/2 - 1];
                key_high_list.push_back(*i);
                item_high_list.push_back(*j);
            }
            ++i;
            ++j;
        }

        create_balanced_bst(root->left_feild, key_low_list, item_low_list);
        create_balanced_bst(root->right_feild, key_high_list, item_high_list);


//        for (unsigned int i = 0; i < size; ++i) {
//            delete [] key_low_list;
//            delete [] key_high_list;
//            delete [] item_low_list;
//            delete [] item_high_list;
//        }
//        delete key_low_list;
//        delete key_high_list;
//        delete item_low_list;
//        delete item_high_list;
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::create_array(bstNode<Item, Key>* root, list<Key>& key_list, list<Item>& item_list){
    if (root != NULL) {
        create_array(root->left_feild, key_list, item_list);
        create_array(root->right_feild, key_list, item_list);

        key_list.push_back(root->k);
        item_list.push_back(root->it);
//        key_array[size] = root->k;
//        item_array[size] = root->it;
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::balance_bst(bstNode<Item, Key>*& root)
{
    //    unsigned int size = root->tree_size(root) - 1;
//    Key* key_array = new Key[size];
//    Item* item_array = new Item[size];

    list<Key> key_list;
    list<Item> item_list;


    create_array(root, key_list, item_list);

    root->tree_clear(root);

    create_balanced_bst(root, key_list, item_list);

//    for (unsigned int i = 0; i < size; ++i) {
//        delete [] key_array;
//        delete [] item_array;
//    }
//    delete key_array;
//    delete item_array;
}
// ---------------------------------------------------------------
// ---------------------------------------------------------------













#endif
