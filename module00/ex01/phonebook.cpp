#include "Phonebook.h"
#include "Contact.h"

Phonebook::Phonebook() {
    index = 0;
    contact_count = 0;
}

void Phonebook::add() {
    Contact contact;

    if (index >= 8)
        index = 0;
    std::cout << "first name: ";
    std::cin >> contact.f_name;
    std::cout << "last name: ";
    std::cin >> contact.l_name;
    std::cout << "nickname: ";
    std::cin >> contact.nickname;
    std::cout << "phn number: ";
    while (true) {
        std::cin >> contact.number;
        if (!valid_number(contact.number)) {
            std::cout << "Enter correctly" << std::endl;
        } else 
            break ;
    }
    std::cout << "Darkest Secret: ";
    std::cin >> contact.secret;
    contacts[index] = contact;
    if (contact_count < 8)
        contact_count++;
    index++;
    std::cout << "Contact SAVED!" << std::endl;
}

void Phonebook::search() {
    int     i; 

    display_contacts();
    while(true) {
        std::cout << "Enter an index to view details or -1 to go back: ";
        if (!(std::cin >> i)) {
            std::cin.clear(); // clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the buffer
            std::cout << "Enter Valid index" << std::endl;
        }
        else if (i == -1)
            break ;
        else if (i <= contact_count && i > 0) {
            display_single_contact(i - 1, contacts);
            break ;
        }
        else    
            std::cout << "Index Doesn't exist" << std::endl;
    }
}

void Phonebook::display_single_contact(int index, Contact *contacts) {
    std::cout << "First Name  : " << contacts[index].f_name << std::endl
    << "Last Name   : " << contacts[index].l_name << std::endl
    << "Nickname    : " << contacts[index].nickname << std::endl
    << "Phn Number  : " << contacts[index].number << std::endl
    << "Secret      : " << contacts[index].secret << std::endl;
}

void Phonebook::display_contacts() {
    int i = 0;

    std::cout << "     INDEX|" << "FIRST NAME|" << " LAST NAME|" << "  NICKNAME|"
    << std::endl;

    while (i < contact_count) {
        display_truncated(std::to_string(i + 1));
        std::cout << "|";
        display_truncated(contacts[i].f_name);
        std::cout << "|";
        display_truncated(contacts[i].l_name);
        std::cout << "|";
        display_truncated(contacts[i].nickname);
        std::cout << "|" << std::endl;
        i++;
    }
}

int Phonebook::valid_number(std::string number) {
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

void Phonebook::display_truncated(std::string str) {
    int i = 0;
    int len = str.length();
    
    if (len < MAX_TRUNC)
    {
        while (MAX_TRUNC - len) {
            std::cout << " ";
            len++;
        }
    }
    while (i < MAX_TRUNC - 1)
    {
        if (str[i]) {
            std::cout << str[i];
            i++;
        } else 
            break ;
    }
    if (str[i])
        std::cout << ".";
}