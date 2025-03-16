#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.h"

#define MAX_TRUNC 10

class Phonebook {
    private:
    int     valid_number(std::string number);
    void    display_single_contact(int index, Contact *contacts);
    void    display_contacts();
    void    display_truncated(std::string str);

    public :
    Contact contacts[8];
    int     contact_count;
    int     index;

    void    add();
    void    search();
    Phonebook();
};


#endif