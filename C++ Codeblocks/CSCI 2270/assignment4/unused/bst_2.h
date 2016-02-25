#ifndef BST_2_H_INCLUDED
#define BST_2_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <list>
#include <memory>
using namespace std;


template <class Item, class Key>
class bstNode{
public:

    // CONSTRUCTOR
    bstNode() {}
    bstNode(Key K, Item I){
        k = K;
        it = I;
        left_feild = NULL;
        right_feild = NULL;
    }

    bstNode<Item, Key>(bstNode<Item, Key>*& root){
        k = root->k;
        it = root->it;
        left_feild = root->left_feild;
        right_feild = root->right_feild;
    }

    // MEMBER FUNCTIONS
    std::size_t tree_size(const bstNode<Item, Key>* root);
    void tree_clear(bstNode<Item, Key>*& root);
    bstNode<Item, Key>* tree_copy(bstNode<Item, Key>*& root);
    std::size_t tree_depth(const bstNode<Item, Key>* root);
    bool validate_bst(const bstNode<Item, Key>* root);
    void insert_node(bstNode<Item, Key>*& root, const Key& number, const Item& entry);
    void remove_node(bstNode<Item, Key>*& root, const Key& number);
    bstNode<Item, Key>* get_node(bstNode<Item, Key>* root, const Key& k) const;

    template <class Process>
    void inorder_processing(bstNode<Item, Key>*& root, Process f);
    template <class Process>
    void preorder_processing(bstNode<Item, Key>*& root, Process f);
    template <class Process>
    void postorder_processing(bstNode<Item, Key>*& root, Process f);
    template <class Process, class Param>
    bool process_node (bstNode<Item, Key>*&, Key k, Process f, Param p);

    void balance_bst(bstNode<Item, Key>*& root);

    Key get_data() {return k;}
    bstNode<Item, Key>* left() {return left_feild;}
    bstNode<Item, Key>* right() {return right_feild;}

private:
    Key k;
    Item it;
    bstNode<Item, Key> *left_feild;
    bstNode<Item, Key> *right_feild;

    // PRIVATE FUNCTIONS
    void create_balanced_bst(bstNode<Item, Key>*& root, bstNode<Item,Key>** array,
                             int& begin, int& end);
    int create_array(bstNode<Item, Key>*& root, bstNode<Item,Key> **array,
                     int& size);
    void sort(bstNode<Item, Key>** a, int size);

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
bool bstNode<Item, Key>::validate_bst(const bstNode<Item, Key>* root){
    if (root == NULL) {
        return true;
    }

    return (validate_bst(root->left_feild) && validate_bst(root->right_feild));

    if (root->left_feild == NULL && root->right_feild == NULL) return true;
    if (root->left_feild->k > root->k || root->right_feild->k < root->k)
        return false;
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
bstNode<Item, Key>* bstNode<Item, Key>::get_node(bstNode<Item, Key>* root, const Key& number) const{
    if (root == NULL) return root;
    if (number == root->k) return root;
    else if (number < root->k){
        return get_node(root->left_feild, number);
    }
    else{
        return get_node(root->right_feild, number);
    }
}
// ---------------------------------------------------------------
template <class Item, class Key>
template <class Process>
void bstNode<Item, Key>::inorder_processing(bstNode<Item, Key>*& root,
                                            Process f){
    if (root == NULL) return;
    inorder_processing(root->left_feild, f);
    f(root->it, root->k);
    inorder_processing(root->right_feild, f);
}
// ---------------------------------------------------------------
template <class Item, class Key>
template <class Process>
void bstNode<Item, Key>::preorder_processing(bstNode<Item, Key>*& root,
                                             Process f){
    if (root == NULL) return;
    f(root->it, root->k);
    preorder_processing(root->left_feild, f);
    preorder_processing(root->right_feild, f);
}
// ---------------------------------------------------------------
template <class Item, class Key>
template <class Process>
void bstNode<Item, Key>::postorder_processing(bstNode<Item, Key>*& root,
                                              Process f){
    if (root == NULL) return;
    postorder_processing(root->left_feild, f);
    postorder_processing(root->right_feild, f);
    f(root-> it, root->k);
}
// ---------------------------------------------------------------
template <class Item, class Key>
template <class Process, class Param>
bool bstNode<Item, Key>::process_node (bstNode<Item, Key>*& root, Key k,
                                       Process f, Param p){
    if (root == NULL) return false;
    else if(k < root->k){
        return process_node(root->left_feild, k, f, p);
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
void bstNode<Item, Key>::balance_bst(bstNode<Item, Key>*& root)
{
    int zero = 0;

    int size = root->tree_size(root);
    bstNode<Item, Key>** array = new bstNode<Item, Key>*[size];
    size = root->create_array(root, array, zero);

    root->sort(array, size);

    size = root->tree_size(root);

    zero = 0;
    create_balanced_bst(root, array, zero, size);

   delete[]array;
}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item,Key>::create_balanced_bst(bstNode<Item, Key>*& root,
                                            bstNode<Item,Key> **array,
                                            int &begin, int& end)
{
    if (end < begin)
    {
        return;
    }
    int half = (begin + end)/2;

    root = array[half];

    --half;

    create_balanced_bst(root->left_feild, array, begin, half);
    half += 2;
    create_balanced_bst(root->right_feild, array, half, end);
}
// ---------------------------------------------------------------
template <class Item, class Key>
int bstNode<Item,Key>::create_array(bstNode<Item, Key>*& root,
                                    bstNode<Item,Key>** array, int& size)
{
    if(root == NULL) return size;
    array[size] = new bstNode<Item,Key>(root->k, root->it);

    int plus1 = size + 1;
    size = create_array(root->left_feild, array, plus1);
    size = create_array(root->right_feild, array, size);

    return size;

}
// ---------------------------------------------------------------
template <class Item, class Key>
void bstNode<Item, Key>::sort(bstNode<Item, Key>** a, int size){
    bstNode<Item, Key>* temp;
    for(int i = 0; i < size; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {

            if(a[i]->k < a[j]->k){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
// ---------------------------------------------------------------
// ---------------------------------------------

#endif // BST_2_H_INCLUDED
