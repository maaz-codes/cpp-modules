#include "Phonebook.h"
#include "Contact.h"

int valid_number(std::string number)
{
    int i = 0;

    while (number[i]) 
    {
        if (number[0] == '+') 
        {
            i++;
            continue ;
        }
        if (!(number[i] >= '0' && number[i] <= '9'))
            return (0);
        i++;
    }
    if (i > 17)
        std::cout << "Woah! That's not a phone number anymore, but alright." << std::endl;
    return (1);
}

void Phonebook::add() {
    Contact contact;
    int check = true;

    if (contact_count >= 8)
        contact_count = 0;
    std::cout << "first name: ";
    std::cin >> contact.f_name;
    std::cout << "last name: ";
    std::cin >> contact.l_name;
    std::cout << "nickname: ";
    std::cin >> contact.nickname;
    std::cout << "phn number: ";
    while (check) {
        std::cin >> contact.number;
        if (!valid_number(contact.number)) {
            std::cout << "Enter correctly" << std::endl;
        } else 
            check = false;
    }
    std::cout << "Darkest Secret: ";
    std::cin >> contact.secret;
    contacts[contact_count] = contact;
    contact_count++;
}

void Phonebook::display_contacts() {
    int i = 0;

    while (i <= 8) {
        std::cout << i + 1 << "|"
        << contacts[i].f_name << "|"
        << contacts[i].l_name << "|"
        << contacts[i].nickname << "|"
        << std::endl;
        i++;
    }
}
