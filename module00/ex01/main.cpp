#include "Phonebook.h"
#include "Contact.h"

int main(void)
{
    std::string option;
    Phonebook phonebook;

    std::cout << "Enter one of these cmds:" << std::endl << "ADD, SEARCH, EXIT:" << std::endl;
    while (true)
    {
        std::cout << "CMD: ";
        std::cin >> option;
        if (option == "ADD")
            phonebook.add();
        if (option == "SEARCH")
            phonebook.search();
        if (option == "EXIT")
            break ;
    }
    return (0);
}