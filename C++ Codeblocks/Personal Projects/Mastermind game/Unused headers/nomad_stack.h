#ifndef NOMAD_STACK_H_INCLUDED
#define NOMAD_STACK_H_INCLUDED
/*
*   Author: Sahle "Nomad" Alturaigi
*   Date: Nov. 26th, 2012
*
*   My own implementation of the stack datatype. Still crude and not yet suited for
*   for general use.
*/

template<class datatype>
class nomad_stack {
    public:
        typedef datatype value_type;

    // Constructors
    nomad_stack(int max_size = 500);

    // Copy Constructor
    nomad_stack(const nomad_stack<datatype> &cSource);

    // Destructor
    ~nomad_stack();

    // Modifiers
    datatype pop();                                    // Returns top of the stack.
    void empty_pop();                               // Pops stack. Returns nothing.
    void push(const datatype &element); // Pushes element onto stack.
    datatype top();                                     // Shows the top element in stack.
    void print_stack();                               // Prints the current stack.
    void print_max_size();                        // Displays max size.
    bool is_alive();                                    // Check if stack is not empty
    void close_stack();                              // Manually deallocate stack

private:
    const int max;                   // How large stack may be. Const 500.
    short int height;                // How tall the currect stack is. Starts at 0.
    value_type *the_stack;    // The actual stack variable.
};

// Constructor
template<class datatype>
nomad_stack<datatype>::nomad_stack(int max_size):max(max_size)
{
    height = 0;
    the_stack = new datatype[max];
}

// Copy constructor
template<class datatype>
nomad_stack<datatype>::nomad_stack(const nomad_stack<datatype> &cSource)
{
    max = cSource.max;
    height = cSource.height;
    the_stack = new datatype[max];

    if(cSource.height <= 0)
        return;

    for(int i = 0; i < height; ++i)
        the_stack[i] = cSource[i].the_stack;
}

// Destructor
template<class datatype>
nomad_stack<datatype>::~nomad_stack()
{
    delete[]the_stack;
    the_stack = NULL;
}

// Pop()
template<class datatype>
datatype nomad_stack<datatype>::pop()
{
    int temp;

    if(height <= 0)
        return;

    --height;
    temp = the_stack[height + 1];
    return temp;
}

// empty_pop()
template<class datatype>
void nomad_stack<datatype>::empty_pop()
{
    if(height <= 0)
        return;

    --height;
}
// Push()
template<class datatype>
void nomad_stack<datatype>::push(const datatype &element)
{
    if(height >= max)
    {
        std::cout <<"Sorry bro, stack is full.\n";
        return;
    }

    the_stack[height] = element;
    ++height;
}

// Top()
template<class datatype>
datatype nomad_stack<datatype>::top()
{
    return the_stack[height - 1];
}

// Print_stack()
template<class datatype>
void nomad_stack<datatype>::print_stack()
{
    if(height <= 0)
        std::cout <<"Can't print stack... Height = 0" << std::endl;

    for(short int i = 0; i < height; ++i)
    {
        std:: cout << the_stack[i] << " ";
    }

    std::cout <<"\n";
}

// Print_max_size()
template<class datatype>
void nomad_stack<datatype>::print_max_size()
{
    std::cout << "Max = " << max << std::endl;
}

// is_alive()
template<class datatype>
bool nomad_stack<datatype>::is_alive()
{
    bool alive;
    if(height > 0)
        alive = true;
    else
        alive = false;
    return alive;
}


#endif // NOMAD_STACK_H_INCLUDED
