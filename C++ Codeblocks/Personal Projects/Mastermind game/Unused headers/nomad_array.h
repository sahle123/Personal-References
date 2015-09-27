#ifndef NOMAD_ARRAY_H_INCLUDED
#define NOMAD_ARRAY_H_INCLUDED

#include "peg_class.h"

/*
*   Author: Sahle "Nomad" Alturaigi
*   Date: Nov. 26th, 2012
*
*   Dynamic array with individual elements that may be deleted.
*/

/// Needs to be refactored later for template function

class nomad_array{
    private:
        int *_array;
        int count;
        int size;

    public:
        // Constructor
        nomad_array(int given_size);

        // Copy Constructor

        //Destructor
        ~nomad_array();

        // Modifiers
        void add_element(int element);
        void remove_element(int index);
        int get_value(int index);
        void close_array();
};

nomad_array::nomad_array(int given_size)
{
    size = given_size;
    count = 0;
    _array = new int[size];
}

nomad_array::~nomad_array()
{
    delete[]_array;
    _array = NULL;
}

void nomad_array::add_element(int element)
{
    if(count >= size)
        return;

    _array[count] = element;
    ++count;
}

void nomad_array::remove_element(int index)
{
    if(count <= 0)
        return;

    int *temp_array;
    temp_array = new int[size-1];

    // Store array in temp array.
    for(int i = 0; i < size; ++i)
    {
        if(i == index)
            continue;
        temp_array[i] = _array[i];
    }

    // Make new array without the old index.
    delete[]_array;
    _array = NULL;

    // Remake array.
    --size;
    _array = new int[size];

    // Refill array.
    for(int i = 0; i < size; ++i)
    {
        _array[i] = temp_array[i];
    }

    // Deallocate temp array.
    delete[]temp_array;
    temp_array = NULL;

}

int nomad_array::get_value(int index)
{
    return _array[index];
}

void nomad_array::close_array()
{
    delete[]_array;
    _array = NULL;
}
#endif // NOMAD_ARRAY_H_INCLUDED
