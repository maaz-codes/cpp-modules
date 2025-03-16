#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.h"

class Phonebook {
    public :
    Contact contacts[8];
    int     contact_count;

    void add();
    void display_contacts();
    // void search();
    // void exit();
};

#endif