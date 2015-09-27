#ifndef FATHER_H
#define FATHER_H

// Base class.
class Father
{
    public: // AVAILABLE TO ALL.
        // Constructor
        Father();
        Father(int value);

        // Mod functions
        void sayStuff();
        void our_secret(int value);
        void set_secret(int value);
        void print_our_secret();
        void print_dad_secret();

        // Public variables.
        int dad_number;

    protected: // ONLY BASE AND DERIVED CLASS.
        int var_our_secret;

    private: // ONLY AVAILABLE INSIDES THIS CLASS.
        int dad_secret_number;
        void yell_loudly(); // Note that Daughter class can't use this at all.
};

#endif // FATHER_H
