/*
     Assignment 3 homework for CSCI 2270.

     Written by: Sahle A. Alturaigi
     Data: 03-27-12

     Test inputs for sorted_bag.h.
*/
#include<iostream>
#include<cstdlib>
#include<list>
#include"sorted_bag.h"
using namespace std;

int main ()
{
     sorted_bag<int> int_bag;

     int_bag.insert_item(19);
     int_bag.insert_item(-10);
     int_bag.insert_item(28);
     int_bag.insert_item(42);
     int_bag.insert_item(0);
     int_bag.insert_item(-10);
     int_bag.insert_item(19);
     int_bag.insert_item(-10);
     int_bag.insert_item(19);

     int_bag.find_copies(-10);
     int_bag.find_copies(100);

     int_bag.remove_item(19);
     int_bag.find_copies(19);
     int_bag.find_copies(-10);
     int_bag.remove_item(200);
     cout << int_bag << endl;

     sorted_bag<int> int_bag2(int_bag);
     cout <<int_bag2 << endl;
     if(int_bag2 == int_bag)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     int_bag2.remove_item(-10);
     int_bag.find_copies(-10);
     int_bag2.find_copies(-10);

     if(int_bag2 == int_bag)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     sorted_bag<int> int_bag3;

     int_bag3 = int_bag2;
     cout << int_bag3 << endl;

     if(int_bag == int_bag3)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     if(int_bag2 == int_bag3)
          cout << "true" << endl;
     else
     cout << "false" << endl;
     //---

     sorted_bag<int> *int_p;
     int_p = new sorted_bag<int>;

     int_p->insert_item(100);
     int_p->insert_item(200);
     int_p->insert_item(50);
     int_p->insert_item(20);
     int_p->insert_item(60);
     cout << *int_p << endl;

     sorted_bag<int> *int_q;
     int_q = new sorted_bag<int>;

     *int_q = *int_p;

     if(*int_q == *int_p)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     if(*int_p == int_bag2)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     int_bag2 = *int_p;
     if(int_bag2 == *int_p)
          cout << "true" << endl;
     else
     cout << "false" << endl;
     //---

     int_p->remove_item(200);
     if(int_bag2 == *int_p)
          cout << "true" << endl;
     else
     cout << "false" << endl;

     delete int_p;
     delete int_q;

     cout << int_bag2 << endl;

     int_bag += int_bag2;
     cout << int_bag << endl;
     cout << int_bag2 << endl;

     int_bag += int_bag;
     cout << int_bag << endl;

     sorted_bag<char> char_bag;
     char_bag.insert_item('a');
     char_bag.insert_item('2');
     char_bag.insert_item('d');
     char_bag.insert_item('?');
     cout << char_bag << endl;
     char_bag.insert_item('a');
     char_bag.insert_item('2');
     char_bag.insert_item('d');
     char_bag.insert_item('?');
     cout << char_bag << endl;

     list<int> l1;
     l1.push_back(10);
     l1.push_back(20);
     l1.push_back(30);
     l1.push_back(1);
     l1.push_back(01);
     l1.push_back(17);

     list<int> l2;
     l2.push_back(10);
     l2.push_back(20);
     l2.push_back(33);
     l2.push_back(1);
     l2.push_back(100);

     list<int> *lp;
     //lp = new sorted_bag<int>;
     list<int> l3;
     lp = &l3;
     l3.push_back(-10);
     l3.push_back(-19);
     l3.push_back(30);
     l3.push_back(19);
     l3.push_back(-10);

     sorted_bag< list<int> > *sb_p;
     sb_p = new sorted_bag< list<int> >;
     sb_p->insert_item(l1);
     sb_p->insert_item(l2);

     sorted_bag< list<int> > *sb_p2;
     sb_p2 = new sorted_bag< list<int> >;
     sb_p2->insert_item(*lp);

     if(*sb_p2 == *sb_p)
     cout << "True" << endl;
     else
     cout << "False" << endl;

     sb_p->insert_item(*lp);
     sb_p2->insert_item(l1);
     sb_p2->insert_item(l2);

     if(*sb_p2 == *sb_p)
     cout << "True" << endl;
     else
     cout << "False" << endl;

     sb_p->remove_item(l1);

     if(*sb_p2 == *sb_p)
     cout << "True" << endl;
     else
     cout << "False" << endl;

    return EXIT_SUCCESS;
}
