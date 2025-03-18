#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <sstream>
#include <cstdio>
#include "Contact.h"


#define MAX_TRUNC       10
#define MAX_CONTACTS    8

class Phonebook {
    private:
    int                 valid_number(std::string &number);
    void                display_single_contact(int index, Contact *contacts);
    void                display_contacts();
    void                display_truncated(std::string str);

    public :
    Contact             contacts[MAX_CONTACTS];
    int                 contact_count;
    int                 index;

    void                add();
    void                search();
    static bool         ft_getline(std::string &input);
    static bool         str_to_int(const std::string &str, int &result);
    static std::string  int_to_str(int num);
    Phonebook();
};


#endif