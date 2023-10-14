/*
    !   GLObAL_VAR_FUNC_CPP : This is the main cpp file.....
*/
#ifndef GLOBAL_VAR_FUNC_CPP
#define GLOBAL_VAR_FUNC_CPP
    
    // pre-defined directives....
    #include <conio.h>
    #include <iostream>
    #include <windows.h>
    #include "textstyling.h"

bool last_entry_comp = false; // Aids in finding the count of entries for respective branches...
bool last_entry_mech = false;
bool last_entry_elec = false;
bool remember_password = false; //todo remembr_password feature...

int n; 
int choice;
int count;
int test = 0;

void printHeader() {
    std::cout << "\n\n\n\t\t-------------------------------------------------------------------------------------" << std::endl
              << "\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<| COLLEGE MANAGEMENT SYSTEM |>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl
              << "\t\t-------------------------------------------------------------------------------------" << std::endl
              << "\t\t\t\t\t\t\t\t\t    Creator : Haysten_D_Costa\n"
              << "\t\t\t\t\t\t\t\t\t\t\t       21co56\n";
}
void loading() {/* FUNCTION TO DISPLAY LOADING PROCESS IN ANY PAGE.... */
 
    char x = 219;
    std::cout << "\n\n\n\n\t\t\tLoading ";
    for(int i=0; i< 55; i++) 
    {
        std::cout << GREEN_TEXT << x;
        if(i < 10) { Sleep(300); }
        if(i>=10 && i<20) { Sleep(150); }
        if(i >= 10) { Sleep(25); }
    }
    system("cls");
    std::cout << RESET;
}
std::string encriptPass() {  // A simple call/pass by value function to encript characters during entering password...
    int ch;
    std::string password;
    ch = getch();
    while(ch != 13) {
        password.push_back(ch);
        std::cout << '*';
        ch = getch();
    }
    return(password);
}
void loading_refresh() {
    std::cout << "\n\n\n\t\t\t"
              << "<";
    for(int i=0; i<65; i++) { 
        std::cout << "-"; 
        Sleep(1);
    }
    std::cout << ">";
}

#endif