#include "Phonebook.h"
#include "Contact.h"

int main(void)
{
    std::string option;
    Phonebook phonebook;

    while (true)
    {
        std::cout << "Enter one of these cmds:" << std::endl << "ADD, SEARCH, EXIT:" << std::endl;
        std::cin >> option;
        if (option == "ADD")
            phonebook.add();
        phonebook.display_contacts();
    }
}