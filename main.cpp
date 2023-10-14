/*
    !   MAIN_CPP : This is the main cpp file.....
*/
/* *****************************************************************************************************************
?   Lab ID        : 1.0 (Projects in C++)
?   Program Title : Basics to Advance of C++
?   Author        : Haysten D'costa
?   Roll No.      : 21co56
?   Class         : Comp B[Batch P3]
?   Language      : C++
?   Due Date      : --
--------------------------------------------------------------------------------------------------------------------
?   Description   : C++ Program to implement a college management system.....
?   Input         : --
?   Output        : --
?   Algorithm     : --
?   Prerequisites : Basics of C and C++
?   Known Bugs    :
?   Features To be added :
***************************************************************************************************************** */

    // pre-defined directives....
    #include <vector>
    #include <cstring>
    #include <iomanip>
    #include <fstream>
    #include <conio.h>
    #include <iostream>
    #include <stdlib.h>
    #include <windows.h>
    
    // user-defined directives....
    #include "classes.h"
    #include "textstyling.h"
    #include "global_var_func.h"

int main()
{
    int ch;
    std::string p, password, confirm;
    system("cls");
    printHeader();
    std::cout << "\n\t\t\t\t.................>>>>> WELCOME <<<<<.................\t\n";
    std::cout << "\n\t\t\t\t\t  Setting up the system for you !\n";

    std::cout << "\n\n\n\t\t\tAlready Signed in ? "; std::cin >> confirm;
    if((confirm == "Y") || (confirm == "y")) {
        std::ifstream in;
        std::string pswdStr;
        std::string searchPassword;
        in.open("Password.txt");
        int count = {};
        std::cout << "\n\n\t\t\tEnter previously entered password : "; std::cin.ignore();
        getline(std::cin, searchPassword);
        while(!in.eof() && !in.fail()) {
            getline(in, pswdStr);
            if(searchPassword == pswdStr) {
                count++;
            }
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such logins found !\n"; goto setNewPass; }
    }
    else {
        setNewPass : 
        std::cout << "\n\n\n\t\t\tSet up a strong password : "; 
        p = encriptPass();
        std::cout << "\n\t\t\tRe-Enter password : "; confirm = encriptPass();

        if(confirm == p) { 
            loading();
            printHeader();
            std::cout << "\n\n\n\n\t\t\t\t\t---- SYSTEM SET-UP SUCCESSFUL ----"
                      << "\n\n\n\n\n\t\t\tPassword successfully set !   \n\t\t\t. . . "; 
            password = p;

            //? Storing the password for next login....
            std::ofstream out;
            out.open("Password.txt", std::ios::app);
            out << password << std::endl;
        }
        else { 
            loading_refresh();
            system("cls");
            printHeader();
            std::cout << "\n\n\t\t\tPasswords dont match !  Try Again !!.....\n";
            std::cout << "\t\t\t"; system("pause");
            static int count = {};
            count ++;
            if((count%5) == 0) {
                for(int i=15; i>=0; i--) {
                    system("cls");
                    printHeader();
                    std::cout << "\n\t\t\t\t.................>>>>> WELCOME <<<<<.................\t\n";
                    std::cout << "\n\n\n\n\n\n\t\t\t\t\t\tTry Again after : " << i <<"s . . .\n\t\t\t";
                    Sleep(1000);
                }
            }
            main();
        }
    } 
    system("pause");
    DataBase D(password);
    D.externalPage();

    return(0);
}

// #endif