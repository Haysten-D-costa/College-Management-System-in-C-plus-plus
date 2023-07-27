#include <iostream>
#include <conio.h> 
#include <vector>

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // For Windows....
    #else
        std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence for clearing the screen (Unix-based systems)....
    #endif
}
void setTextColor(int color) {
    #ifdef _WIN32
        // For Windows, you can use ANSI escape sequences to set text color....
        
        if (color == 0) std::cout << "\033[30m"; // Black
        else if (color == 1) std::cout << "\033[31m"; // Red color
        else if (color == 2) std::cout << "\033[32m"; // Green color
        else if (color == 3) std::cout << "\033[33m"; // Yellow color
        else if (color == 4) std::cout << "\033[34m"; // Blue color
        else if (color == 5) std::cout << "\033[35m"; // Magenta color
        else if (color == 6) std::cout << "\033[36m"; // Cyan color
        else if (color == 7) std::cout << "\033[37m"; // White color
    #else
        // For Unix-based systems, you can use ANSI escape sequences to set text color....
        std::cout << "\033[38;5;" << color << "m";
    #endif
}
void resetTextColor() {
    #ifdef _WIN32
        // For Windows, reset the text color using ANSI escape sequences....
        std::cout << "\033[0m";
    #else
        // For Unix-based systems, reset the text color using ANSI escape sequences....
        std::cout << "\033[0m";
    #endif
}
void printHeader01() {
            std::cout << "\n\n\n\t\t-------------------------------------------------------------------------------------" << std::endl
                      << "\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<| COLLEGE MANAGEMENT SYSTEM |>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl
                      << "\t\t-------------------------------------------------------------------------------------" << std::endl
                      << "\t\t\t\t\t\t\t\t\t    Creator : Haysten_D_Costa\n"
                      << "\t\t\t\t\t\t\t\t\t\t\t       21co56\n";
}
namespace menu
{
    int arrowMenu(const std::vector<std::string>& menuOptions) { // Function creates a arrowMenu, for the passed vector(options)....
        int numOptions = menuOptions.size();
        int choice = 0;
        char ch;

        while (true) {
            // Display the menu options with highlighting....
            clearScreen();
            printHeader01();
            std::cout << std::endl << std::endl << std::endl;
            for (size_t i{0}; i<numOptions; i++) {

                if (i == choice) {
                    setTextColor(2); // Green color for the highlighted option....
                    std::cout << "\t\t\t\t -> " << menuOptions[i] << std::endl;
                    resetTextColor(); // Reset text color after printing the option....
                } else {
                    std::cout << "\t\t\t\t    " << menuOptions[i] << std::endl;
                }
            }
            // Wait for user input
            ch = _getch();

            // Handle arrow key input....
            if (ch == 0 || ch == -32) {
                ch = _getch(); // Read the actual arrow key....
                if (ch == 72) { // Up arrow key....
                    choice = (choice - 1 + numOptions) % numOptions;
                } else if (ch == 80) { // Down arrow key....
                    choice = (choice + 1) % numOptions;
                }
            } else if (ch == 13) { // Enter key....
                return choice; // Return the index of the selected option....
            }
        }
    }
}
