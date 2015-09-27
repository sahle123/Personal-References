#ifndef DAUGHTER_H
#define DAUGHTER_H

// Derived class.

class Daughter : public Father
{
    public:
        // Constructors.
        Daughter(int value);

        // Mod functions.
        void otherStuff();
        void set_daughter_number(int value);

        // Public variables.
        int daughter_number;
};

#endif // DAUGHTER_H
