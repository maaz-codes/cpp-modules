#include <iostream>

void megaphone(char *str)
{
    int i = 0;

    while (str[i])
    {
        std::cout << static_cast<char>(std::toupper(str[i]));
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc > 1)
    {
        while (i < argc)
        {
            megaphone(argv[i]);
            i++;
        }
        std::cout << std::endl;
    }
    else 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
}
