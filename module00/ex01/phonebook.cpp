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
    if (!Phonebook::ft_getline(contact.f_name))
            return ;
    std::cout << "last name: ";
    if (!Phonebook::ft_getline(contact.l_name))
            return ;
    std::cout << "nickname: ";
    if (!Phonebook::ft_getline(contact.nickname))
            return ;
    std::cout << "phn number: ";
    while (true) {
        if (!Phonebook::ft_getline(contact.number))
            return ;
        if (!valid_number(contact.number)) {
            std::cout << "Enter correctly" << std::endl;
        } else 
            break ;
    }
    std::cout << "Darkest Secret: ";
    if (!Phonebook::ft_getline(contact.secret))
            return ;
    contacts[index] = contact;
    if (contact_count < 8)
        contact_count++;
    index++;
    std::cout << "Contact SAVED!" << std::endl;
}

void Phonebook::search() {
    std::string     index;
    int             i; 

    display_contacts();
    while(true) {
        std::cout << "Enter an index to view details or ctrl + D to go back: ";
        if (!Phonebook::ft_getline(index))
            break ;
        try {
            if (!valid_number(index))
                throw std::invalid_argument("");
            i = stod(index);
        } catch (const std::exception&) {
            std::cout << "Enter valid Index" << std::endl;
            continue ; 
        }
        if (i <= contact_count && i > 0) {
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

int Phonebook::valid_number(std::string &number) {
    int num;

    std::istringstream iss(number);
    iss >> num;
    return !(iss.fail() || !iss.eof());
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

bool Phonebook::ft_getline(std::string &input) {
    if (!(std::getline(std::cin, input))) {
        std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        freopen("/dev/tty", "r", stdin);
        std::cout << "CTRL + D" << std::endl;
        return (false);
    }
    return (true);
}