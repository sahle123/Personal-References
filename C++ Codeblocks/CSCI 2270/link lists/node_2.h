#ifndef NODE_2_H_INCLUDED
#define NODE_2_H_INCLUDED

/*
*
*    Code written by: born2c0de (From dream in code.net)
*
*/
#include<iostream>
using namespace std;

class linklist {

private:
     struct node
     {
          int data;
          node *link;
     }*p;

public:
     // Constructor
     linklist();

     // Destructor
     ~linklist();

     // Mod Functions
     void append( int num );
     void add_as_first( int num );
     void addafter( int c, int num );
     void del( int num );
     void display();
     int count();
};

// Constructor
linklist::linklist()
{
     p=NULL;
}

// Destructor
linklist::~linklist()
{
     node *q;
   if( p == NULL )
        return;

   while( p != NULL )
   {
        q = p->link;
      delete p;
      p = q;
   }
}

void linklist::append(int num)
{
     node *q,*t;

   if( p == NULL )
   {
        p = new node;
      p->data = num;
      p->link = NULL;
   }
   else
   {
     q = p;
     while( q->link != NULL )
     {
          q = q->link;
     }

     t = new node;
     t->data = num;
     t->link = NULL;
     q->link = t;
   }
}

void linklist::add_as_first(int num)
{
     node *q;

   q = new node;
   q->data = num;
   q->link = p;
   p = q;
}

void linklist::addafter( int c, int num)
{
     node *q,*t;
   int i;
   for(i=0,q=p;i<c;i++)
   {
        q = q->link;
      if( q == NULL )
      {
           cout<<"\nThere are less than "<<c<<" elements.";
         return;
      }
   }

   t = new node;
   t->data = num;
   t->link = q->link;
   q->link = t;
}

void linklist::del( int num )
{
     node *q,*r;
   q = p;
   if( q->data == num )
   {
        p = q->link;
      delete q;
      return;
   }

   r = q;
   while( q!=NULL )
   {
        if( q->data == num )
      {
           r->link = q->link;
         delete q;
         return;
      }

      r = q;
      q = q->link;
   }
   cout<<"\nElement "<<num<<" not Found.";
}

void linklist::display()
{
     node *q;
   cout<<endl;

   for( q = p ; q != NULL ; q = q->link )
        cout<<endl<<q->data;

}

int linklist::count()
{
     node *q;
   int c=0;
   for( q=p ; q != NULL ; q = q->link )
        c++;

   return c;
}

#endif // NODE_2_H_INCLUDED
