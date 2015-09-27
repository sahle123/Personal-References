#include"node.h"

//*****************************************************************************

int main( )
{
    node* a;
    node* b;
    node* c;
    a = new node(-1, NULL);
    b = new node(2, NULL);
    c = new node(3, NULL);

    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;

    // set_data and set_link mod functions: WORKING
    (*a).set_data(1);
    a->set_link(b);
    (*b).set_link(c);

    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;
   
    cout << "\nList Size: " << a->list_size(a) << endl;
    // list_print and list_head_erase member functions: WORKING

    cout << "Printing lists:\n";
    (*a).list_print(a);

    cout <<"\n" << "printing list after A got deallocated." << endl;
    (*a).list_head_erase(a);
    (*a).list_print(a);


    // Assignment test: WORKING
    a = b;
    c = b;
    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;


    // list_head_insert test: Checking...
    (*a).list_head_insert(a, 4);
    (*a).list_print(a);
    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;
    (*a).list_head_insert(a, 5);
    (*a).list_print(a);

    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;

    (*a).list_head_erase(a);
    (*a).list_print(a);

    cout << "a = " << *a << ", b = " << *b << ", c = " <<  *c <<  endl;

    
    /*delete a;
    cout << "A deleted \t";
    delete b;
    cout << "B deleted \t";
    delete c;
    cout << "C deleted" << endl;*/

    //cout << "\nSUCCESSFUL EXIT! (^O^)/." << endl;
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Other Functions:

//------------------------------------------------------------------------------

