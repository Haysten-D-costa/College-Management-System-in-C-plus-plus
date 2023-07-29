/*
!   ARROW_MENU_H : Provides functionality of arrow-button (keyboard) based menu handling....
*/
#ifndef ARROW_MENU_H
#define ARROW_MENU_H

    #include <conio.h> 
    #include <iostream>

    #include "textstyling.h"
    #include "global_var_func.h"

#endif

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
        
        if (color == 0) std::cout << BLACK_TEXT;
        else if (color == 1) std::cout << RED_TEXT;
        else if (color == 2) std::cout << GREEN_TEXT;
        else if (color == 3) std::cout << YELLOW_TEXT;
        else if (color == 4) std::cout << BLUE_TEXT;
        else if (color == 5) std::cout << MAGENTA_TEXT;
        else if (color == 6) std::cout << CYAN_TEXT;
        else if (color == 7) std::cout << WHITE_TEXT;
    #else
        // For Unix-based systems, you can use ANSI escape sequences to set text color....
        std::cout << "\033[38;5;" << color << "m";
    #endif
}
void resetTextColor() {
    #ifdef _WIN32
        // For Windows, reset the text color using ANSI escape sequences....
        std::cout << RESET;
    #else
        // For Unix-based systems, reset the text color using ANSI escape sequences....
        std::cout << RESET;
    #endif
}
namespace menu
{
    int arrowMenu(const std::vector<std::string>& menuOptions) { // Function creates a arrowMenu, for the passed vector(options_list)....
        int numOptions = menuOptions.size();
        int choice = 0;
        char ch;

        while (true) {
            // Display the menu options with highlighting....
            clearScreen();
            printHeader();
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
            ch = _getch(); // Wait for user input

            // Handle arrow key input....
            if (ch == 0 || ch == -32) {
                
                ch = _getch(); // Read the actual arrow key....
                
                if (ch == 72) { // Up arrow key....
                    choice = (choice - 1 + numOptions) % numOptions;
                } 
                else if (ch == 80) { // Down arrow key....
                    choice = (choice + 1) % numOptions;
                }
            } 
            else if (ch == 13) { // Enter key....
                return choice; // Return the index of the selected option....
            }
        }
    }
}
