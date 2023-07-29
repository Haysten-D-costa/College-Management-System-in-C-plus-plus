/*
    !   GLOBAL_VARIABLES_FUNCTIONS_H :     
*/
#ifndef GLOBAL_VARIABLES_FILES_H
#define GLOBAL_VARIABLES_FILES_H

    #include <iostream>

/* 
    Global variable declarations : 
*/
extern bool last_entry_comp; //These are only the declarations....definitions in the global_var_func.cpp files....
extern bool last_entry_mech;
extern bool last_entry_elec;
extern bool remember_password; //todo remembr_password feature...

extern int n;      // used for no. of students/teachers to be registered....
extern int count;  // used to keep count of the no. of enteries in student/teachers text files....
extern int choice; // used to hold the choice made by user....


/*
    Function declarations....
*/
void loading();         // Function to display the loading logo...
void loading_refresh(); // Function to diaplay short loading-refresh logo...

void printHeader();     // Function to display the deader for each page...
std::string encriptPass();   // Funtion to encode the characters while entering the password...

#endif