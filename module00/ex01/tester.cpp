#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter input (or type EXIT to quit): ";

        if (!std::getline(std::cin, input)) {
            if (std::cin.eof()) {
                std::cout << "\nEOF detected. Resetting input stream.\n";
                std::cin.clear();  // Clear the EOF flag   
                freopen("/dev/tty", "r", stdin);
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore remaining invalid input
                continue;
            } else if (std::cin.fail()) {
                std::cout << "\nInput error occurred. Resetting input stream.\n";
                std::cin.clear();  // Clear the error flag
                std::cin.sync();
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the invalid input
                continue;
            }
        }

        if (input == "EXIT") {
            break;
        }

        std::cout << "You entered: " << input << std::endl;
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}
