/*
!   CLASSES_CPP : Contains all the class definitions....
*/
#ifndef CLASSES_CPP
#define CLASSES_CPP

    // pre-defined headers....
    #include <vector>
    #include <iomanip>
    #include <fstream>
    #include <iostream>
    #include <windows.h>

    // user-defined headers....
    #include "classes.h"
    #include "arrow_menu.h"

static int studentID = 0;
static int teacherID = 0;

/**
 * The function "setDetails" assigns a unique student ID, prompts the user to enter name, roll number,
 * email, and branch, and stores the input values.
 * 
 * @param choice The parameter "choice" is an integer that represents the user's choice for the branch
 * of the college student.
 */
void CollegeStudents :: setDetails(int choice) {
        
    studentID = countEntries(choice);
    if((last_entry_comp != true) && (choice == 0)) { studentID++; }
    else if((last_entry_mech != true) && (choice == 1)) { studentID++; }
    else if((last_entry_elec != true) && (choice == 2)) { studentID++; }

    std::cin.ignore();
    std::cout << "\n\t\t\tEnter Name            : "; getline(std::cin, name);

    if(choice == 0) {
        if(studentID < 10) { std::cout << "\t\t\tRoll Number Assigned* : " << "21co0" << studentID << std::endl; } // display and Storing purpose.....for those who prefer '21co01' more than '21co1'
        else { std::cout << "\t\t\tRoll Number Assigned* : "; std::cout << "21co" << studentID << std::endl; }
    }
    else if(choice == 1) {
        if(studentID < 10) { std::cout << "\t\t\tRoll Number Assigned* : " << "21me0" << studentID << std::endl; } // display and Storing purpose.....for those who prefer '21co01' more than '21co1'
        else { std::cout << "\t\t\tRoll Number Assigned* : "; std::cout << "21me" << studentID << std::endl; }
    }
    else {
        if(studentID < 10) { std::cout << "\t\t\tRoll Number Assigned* : " << "21ec0" << studentID << std::endl; } // display and Storing purpose.....for those who prefer '21co01' more than '21co1'
        else { std::cout << "\t\t\tRoll Number Assigned* : "; std::cout << "21ec" << studentID << std::endl; }
    }
    std::cout << "\t\t\tEnter Email           : "; getline(std::cin, email);
    std::cout << "\t\t\tEnter Branch          : "; getline(std::cin, branch);
}
/**
 * The function "createFile" writes student information to a file named "Students.txt" based on the
 * given choice of branch.
 * 
 * @param choice The "choice" parameter is an integer that determines the branch of the student.
 */
void CollegeStudents :: createFile(int choice) {  //FOR STUDENTS

    std::ofstream out;
    out.open("Students.txt", std::ios::app);
    out << name << std::endl;

    if(choice == 0) {
        if(studentID < 10) { out << "21co0" << studentID << std::endl; }
        else { out << "21co" << studentID << std::endl; }
    }
    else if(choice == 1) {
        if(studentID < 10) { out << "21me0" << studentID << std::endl; }
        else { out << "21me" << studentID << std::endl; }
    }
    else {
        if(studentID < 10) { out << "21ec0" << studentID << std::endl; }
        else { out << "21ec" << studentID << std::endl; }
    }
    out << email << std::endl
        << branch << std::endl;
    out.close();
}
/**
 * The function "searchDetails" allows the user to search for student details based on different
 * criteria such as name, roll number, email, and branch.
 * 
 * @return The function does not have a return type specified, so it does not return anything.
 */
void CollegeStudents :: searchDetails() {  //FOR STUDENTS

    std::ifstream in;
    std::string searchName, searchRollno, searchBranch, searchEmail;
    std::string str, str1, str2, str3, str4;
    in.open("Students.txt");
    int count = {};
    std::vector <std::string> search_menu {
        "Search student by 'Name'",
        "Search student by 'Roll number'",
        "Search student by 'Email'",
        "Search student by 'Branch'",
        "Return to previous page"
    };
    choice = menu::arrowMenu(search_menu); 
    if(choice == 0) {
        system("clear");    
        printHeader();
        std::cout << "\n\n\n\t\t\tEnter Name of student to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchName);
        while(!in.eof() && !in.fail()) {          /* MAIN CORRECT CODE, commented to try something diff...below!! */
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(searchName == str1) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                std::cout << "\n"
                            << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "\t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                            << "\t\t\t\tEmail ID      : " << std::setw(28) << str3 << std::endl
                            << "\t\t\t\tBranch        : " << std::setw(28) << str4 << std::endl;
                return;// break; // since using full names, cannot be same....
            } 
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 1) {
        system("clear");    
        printHeader();
        std::cout << "\n\n\n\t\t\tEnter Roll Number of student to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchRollno);
        while(!in.eof() && !in.fail()) {
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(searchRollno == str2) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...

                if(str1 == " ") {
                    std::cout << "\n\n\t\t\t\t\t\t . . . Entry Deleted ! . . .";
                    count++;
                    break;
                }
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                std::cout << "\n"
                            << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "\t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                            << "\t\t\t\tEmail ID      : " << std::setw(28) << str3 << std::endl
                            << "\t\t\t\tBranch        : " << std::setw(28) << str4 << std::endl;
                return;// break; // cannot be same...
            } 
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 2) {
        system("clear");    
        printHeader();
        std::cout << "\n\n\n\t\t\tEnter Email of student to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchEmail);
        for(int i=0; i<countEntAll(); i++) {
            while(!in.eof() && !in.fail()) {
                getline(in, str1);
                getline(in, str2);
                getline(in, str3);
                getline(in, str4);
                if(searchEmail == str3) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                    count++;
                    if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                    std::cout << "\n"
                                << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                                << "\t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                                << "\t\t\t\tEmail ID      : " << std::setw(28) << str3 << std::endl
                                << "\t\t\t\tBranch        : " << std::setw(28) << str4 << std::endl;
                    return;// break; // cannot be same...
                } 
            }
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 3) {
        system("clear");    
        printHeader();
        std::cout << "\n\n\n\t\t\tEnter Branch of student to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchBranch);
        for(int i=0; i<countEntAll(); i++) { //(countEntries) checks the no. of lines in the Students.txt file, and returns the count when divided by 4(no. of details asked)....to give, total no. of students registered....
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(searchBranch == str4) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }

                if(str1 == " ") {
                    std::cout << "\n"
                                << "  \t\t\t\tName          : " << std::setw(28) << "----------" << std::endl
                                << "  \t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                                << "  \t\t\t\tEmail ID      : " << std::setw(28) << "----------" << std::endl
                                << "  \t\t\t\tBranch        : " << std::setw(28) << "----------" << std::endl;
                    continue;
                }
                std::cout << "\n"
                            << "  \t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "  \t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                            << "  \t\t\t\tEmail ID      : " << std::setw(28) << str3 << std::endl
                            << "  \t\t\t\tBranch        : " << std::setw(28) << str4 << std::endl;
            }
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 4) {
        return;
    }
    else {
        std::cout << std::endl << "Incorrect Choice Entered ! " << std::endl; //break;
    }       
}
/**
 * The function "deleteDetails" deletes a student's details from a file based on their name, roll
 * number, or email.
 * 
 * @return The function is not returning any value. It has a void return type.
 */
void CollegeStudents :: deleteDetails() {

    studentID--;
    std::string str, str1, str2, str3, str4;

    std::ifstream in; in.open("Students.txt");
    std::ofstream out; out.open("Temporary.txt");

    std::string deleteName, deleteRollno, deleteEmail;
    int count = {};
    std::vector <std::string> delete_menu {
        "Delete student by 'Name'",
        "Delete student by 'Roll number'",
        "Delete student by 'Email'",
        "Return to previous page"
    };
    choice = menu::arrowMenu(delete_menu);
    if(choice == 0) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Name of student to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteName);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(deleteName == str1) { 
                count++; 
                str1 = " ";
                str3 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Students.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {
            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
    }
    else if(choice == 1) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Roll number of student to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteRollno);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(deleteRollno == str2) { 
                count++; 
                str1 = " ";
                str3 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Students.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {

            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
    }
    else if(choice == 2) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Email ID of student to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteEmail);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            if(deleteEmail == str3) { 
                count++; 
                str1 = " ";
                str3 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Students.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {

            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
    }
    else if(choice == 3) {
        return;
    }
    else {
        std::cout << std::endl << "Incorrect Choice Entered ! " << std::endl; //break;
    }       
}
/**
 * The function "editDetails" allows the user to edit the details of a college student by entering
 * their roll number and providing new information.
 * 
 * @return The function does not have a return type.
 */
void CollegeStudents :: editDetails() {

    std::string editRollno, str1, str2, str3, str4, str;
    std::string backUpRollno;

    std::ifstream in; in.open("Students.txt");
    std::ofstream out; out.open("Temporary.txt");
    system("clear");    
    printHeader();
    std::cout << "\n\t\t\tEnter Roll number of student to be edited : "; std::cin.ignore();  //FLUSHING STREAM...
    getline(std::cin, editRollno);
    for(int i=0; i<countEntAll(); i++) {   
        getline(in, str1);
        getline(in, str2);
        getline(in, str3);
        getline(in, str4);
        if(editRollno == str2) { // Since for edit/update, Roll Number will remain same...Hence roll no. is used when edit entry / update entry is desired...
            count++; 
            backUpRollno = editRollno;

            std::cout << "\n\t\t\t\t\t\tOld Entry : \n"
                        << "\t\t\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                        << "\t\t\t\t\t\tRoll no       : " << std::setw(28) << str2 << std::endl
                        << "\t\t\t\t\t\tEmail ID      : " << std::setw(28) << str3 << std::endl
                        << "\t\t\t\t\t\tBranch        : " << std::setw(28) << str4 << std::endl;


            std::cout << "\n\n\n\t\t\t\tEnter new Name   : "; getline(std::cin, str1);
            std::cout << "\t\t\t\tEnter new Email  : "; getline(std::cin, str3);
            std::cout << "\t\t\t\tEnter new Branch : "; getline(std::cin, str4);
        }
            out << str1 << std::endl;
            out << str2 << std::endl;
            out << str3 << std::endl;
            out << str4 << std::endl;
    }
    in.close();
    out.close();
    loading_refresh();
    if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; return; }

    out.open("Students.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
    in.open("Temporary.txt");
    if(in && out) 
    {
        while(getline(in, str)) { //Copies every line of the temporary file to the main file...
            out << str << std::endl;
        }
    }
    in.close();
    out.close();
}
/**
 * The function "countEntries" reads a file called "Students.txt" and counts the number of entries that
 * match a given choice.
 * 
 * @param choice The parameter "choice" is an integer that determines the search criteria for counting
 * entries. If "choice" is 0, the search criteria is set to "Computer". If "choice" is 1, the search
 * criteria is set to "Mechanical". If "choice" is any other value
 * 
 * @return the count of entries that match the specified choice.
 */
int CollegeStudents :: countEntries(int choice) {

    int countEntries = 0;
    std::string line, search;
    std::string s1, s2, s3, s4;

    if(choice == 0) { search = "Computer"; }
    else if(choice == 1) { search = "Mechanical"; }
    else { search = "Electronics"; }

    std::ifstream in;
    in.open("Students.txt");

    while(!in.eof() && !in.fail()) {          /* MAIN CORRECT CODE, commented to try something diff...below!! */
            getline(in, s1);
            getline(in, s2);
            getline(in, s3);
            getline(in, s4);
            if(search == s4) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                countEntries++;
            } 
            if(s4 == "Computer") { 
                last_entry_comp = true; 
                last_entry_elec = false; 
                last_entry_mech = false; 
            }
            else if(s4 == "Electronics") {
                last_entry_elec = true; 
                last_entry_comp = false; 
                last_entry_mech = false; 
            }
            else {
                last_entry_mech = true; 
                last_entry_comp = false; 
                last_entry_elec = false; 
            }
    }
    in.close();
    return(countEntries);
}
/**
 * The function counts the number of entries in a file and returns the count divided by 4.
 * 
 * @return the count of entries in the "Students.txt" file divided by 4.
 */
int CollegeStudents :: countEntAll() {
    int countEntries = 0;
    std::string line;
    std::ifstream in;
    in.open("Students.txt");

    while(getline(in, line)) { countEntries++; }
    return(countEntries/4);
}
void CollegeTeachers :: setDetails(int choice) {

        teacherID = countEntries(choice);
        if((last_entry_comp != true) && (choice == 0)) { teacherID++; }
        else if((last_entry_mech != true) && (choice == 1)) { teacherID++; }
        else if((last_entry_elec != true) && (choice == 2)) { teacherID++; }

        std::cin.ignore();
        std::cout << "\n\t\t\tEnter Name           : "; getline(std::cin, name);

        if(choice == 0) {
            if(teacherID < 10) { std::cout << "\t\t\tID Assigned*         : " << "AITDco0" << teacherID << std::endl; }
            else { std::cout << "\t\t\tID Assigned*         : " << "AITDco" << teacherID << std::endl; }
        }
        else if(choice == 1) {
            if(teacherID < 10) { std::cout << "\t\t\tID Assigned*         : " << "AITDme0" << teacherID << std::endl; }
            else { std::cout << "\t\t\tID Assigned*         : " << "AITDme" << teacherID << std::endl; }
        }
        else {
            if(teacherID < 10) { std::cout << "\t\t\tID Assigned*         : " << "AITDec0" << teacherID << std::endl; }
            else { std::cout << "\t\t\tID Assigned*         : " << "AITDec" << teacherID << std::endl; }
        }
        std::cout << "\t\t\tEnter Email          : "; getline(std::cin, email);
        std::cout << "\t\t\tEnter Department     : "; getline(std::cin, department);
        std::cout << "\t\t\tEnter Qualification  : "; getline(std::cin, qualification);
}
void CollegeTeachers :: createFile(int choice) { //FOR TEACHERS
    std::ofstream out;
    out.open("Teachers.txt", std::ios::app);
    out << name << std::endl;

    if(choice == 0) {
        if(teacherID < 10) { out << "AITDco0" << teacherID << std::endl; }
        else { out << "AITDco" << teacherID << std::endl; }
    }
    else if(choice == 1) {
        if(teacherID < 10) { out << "AITDme0" << teacherID << std::endl; }
        else { out << "AITDme" << teacherID << std::endl; }
    }
    else {
        if(teacherID < 10) { out << "AITDec0" << teacherID << std::endl; }
        else { out << "AITDec" << teacherID << std::endl; }
    }
    out << email << std::endl
        << department << std::endl
        << qualification << std::endl;
    out.close();
}
void CollegeTeachers :: searchDetails() {  //FOR TEACHERS
    std::ifstream in;
    std::string searchName, searchID, searchDepartment, searchEmail;
    std::string str1, str2, str3, str4, str5;
    in.open("Teachers.txt");
    int count = {};
    std::vector <std::string> search_menu {
        "Search teacher by 'Name'",
        "Search teacher by 'ID'",
        "Search teacher by 'Email'",
        "Search teacher by 'Department'",
        "Return to previous page"
    };
    choice = menu::arrowMenu(search_menu);

    if(choice == 0) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Name of teacher to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchName);
        while(!in.eof() && !in.fail()) {          /* MAIN CORRECT CODE, commented to try something diff...below!! */
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(searchName == str1) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                std::cout << "\n"
                            << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                            << "\t\t\t\tEmail         : " << std::setw(28) << str3 << std::endl
                            << "\t\t\t\tDepartment    : " << std::setw(28) << str4 << std::endl
                            << "\t\t\t\tQualification : " << std::setw(28) << str5 << std::endl;
                return; // break;
            } 
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 1) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter ID of teacher to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchID);
        while(!in.eof() && !in.fail()) {
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(searchID == str2) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                
                if(str1 == " ") {
                    std::cout << "\n\n\t\t\t\t\t\t . . . Entry Deleted ! . . .";
                    count++;
                    break;
                }
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                std::cout << "\n"
                            << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                            << "\t\t\t\tEmail         : " << std::setw(28) << str3 << std::endl
                            << "\t\t\t\tDepartment    : " << std::setw(28) << str4 << std::endl
                            << "\t\t\t\tQualification : " << std::setw(28) << str5 << std::endl;
                return; // break;
            } 
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 2) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Email of teacher to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchEmail);
        for(int i=0; i<countEntAll(); i++) {
            while(!in.eof() && !in.fail()) {
                getline(in, str1);
                getline(in, str2);
                getline(in, str3);
                getline(in, str4);
                getline(in, str5);
                if(searchEmail == str3) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                    count++;
                    if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }
                    std::cout << "\n"
                                << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                                << "\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                                << "\t\t\t\tEmail         : " << std::setw(28) << str3 << std::endl
                                << "\t\t\t\tDepartment    : " << std::setw(28) << str4 << std::endl
                                << "\t\t\t\tQualification : " << std::setw(28) << str5 << std::endl;
                    return; // break;
                } 
            }
            in.close();
            if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
        }
    }
    else if(choice == 3) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Branch of teacher to be searched : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, searchDepartment);
        for(int i=0; i<countEntAll(); i++) { //(countEntries) checks the no. of lines in the Students.txt file, and returns the count when divided by 4(no. of details asked)....to give, total no. of students registered....
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(searchDepartment == str4) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
                count++;
                if(count < 2) { std::cout << "\n\n\t\t\tRequired Details : \n"; }

                if(str1 == " ") {
                    std::cout << "\n"
                                << "\t\t\t\tName          : " << std::setw(28) << "----------" << std::endl
                                << "\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                                << "\t\t\t\tEmail         : " << std::setw(28) << "----------" << std::endl
                                << "\t\t\t\tDepartment    : " << std::setw(28) << "----------" << std::endl
                                << "\t\t\t\tQualification : " << std::setw(28) << "----------" << std::endl;
                    continue;
                }
                std::cout << "\n"
                            << "\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                            << "\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                            << "\t\t\t\tEmail         : " << std::setw(28) << str3 << std::endl
                            << "\t\t\t\tDepartment    : " << std::setw(28) << str4 << std::endl
                            << "\t\t\t\tQualification : " << std::setw(28) << str5 << std::endl;
            } 
        }
        in.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 4) {
        return;
    }
    else {
        std::cout << std::endl << "Incorrect Choice Entered ! " << std::endl; //break;
    } 
}
void CollegeTeachers :: deleteDetails() {
    studentID--;
    std::string str, str1, str2, str3, str4, str5;
    
    std::ifstream in; in.open("Teachers.txt");
    std::ofstream out; out.open("Temporary.txt");

    std::string deleteName, deleteID, deleteEmail;
    int count = {};
    std::vector <std::string> delete_menu {
        "Delete teacher entry by 'Name'",
        "Delete teacher entry by 'ID'",
        "Delete teacher entry by 'Email'",
        "Return to previous page"
    };
    choice = menu::arrowMenu(delete_menu);

    if(choice == 0) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Name of teacher to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteName);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(deleteName == str1) { 
                count++; 
                str1 = " ";
                str3 = " ";
                str5 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
                out << str5 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Teachers.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {
            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
    }
    else if(choice == 1) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter ID of teacher entry to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteID);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(deleteID == str2) { 
                count++; 
                str1 = " ";
                str3 = " ";
                str5 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
                out << str5 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Teachers.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {

            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
    }
    else if(choice == 2) {
        system("clear");    
        printHeader();
        std::cout << "\n\t\t\tEnter Email ID of student to be deleted : "; std::cin.ignore();  //FLUSHING STREAM...
        getline(std::cin, deleteEmail);
        for(int i=0; i<countEntAll(); i++) {   
            getline(in, str1);
            getline(in, str2);
            getline(in, str3);
            getline(in, str4);
            getline(in, str5);
            if(deleteEmail == str3) { 
                count++; 
                str1 = " ";
                str3 = " ";
                str5 = " ";
            }
                out << str1 << std::endl;
                out << str2 << std::endl;
                out << str3 << std::endl;
                out << str4 << std::endl;
                out << str5 << std::endl;
        }
        in.close();
        out.close();
        loading_refresh();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }

        std::ofstream out; out.open("Teachers.txt");   //NEED TO SOLVE THIS MYTH !!! DIDNT DO PROPERLY TRY OTHER LOGIC
        std::ifstream in; in.open("Temporary.txt");
        
        if(in && out) 
        {
            while(getline(in, str)) { //Copies every line of the temporary file to the main file...
                out << str << std::endl;
            }
            if(count > 0) { std::cout << "\n\n\n\t\t\tDeletion successful !\n"; }
        }
        else {

            std::cout << "\n\t\t\t\tERROR ! Try again...\t\n";
        }
        in.close();
        out.close();
        if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; }
    }
    else if(choice == 3) {
        return;
    }
    else {
        std::cout << std::endl << "Incorrect Choice Entered ! " << std::endl; //break;
    }       
}
void CollegeTeachers :: editDetails() {

    std::string editID, str, str1, str2, str3, str4, str5;
    std::string backUpID;

    std::ifstream in; in.open("Teachers.txt");
    std::ofstream out; out.open("Temporary.txt");
    system("clear");    
    printHeader();
    std::cout << "\n\t\t\tEnter ID of teacher to be edited : "; std::cin.ignore();  //FLUSHING STREAM...
    getline(std::cin, editID);
    for(int i=0; i<countEntAll(); i++) {   
        getline(in, str1);
        getline(in, str2);
        getline(in, str3);
        getline(in, str4);
        getline(in, str5);
        if(editID == str2) { 
            count++; 
            backUpID = editID;

            std::cout << "\n\t\t\t\t\t\tOld Entry : \n"
                        << "\t\t\t\t\t\tName          : " << std::setw(28) << str1 << std::endl
                        << "\t\t\t\t\t\tID            : " << std::setw(28) << str2 << std::endl
                        << "\t\t\t\t\t\tEmail         : " << std::setw(28) << str3 << std::endl
                        << "\t\t\t\t\t\tDepartment    : " << std::setw(28) << str4 << std::endl
                        << "\t\t\t\t\t\tQualification : " << std::setw(28) << str5 << std::endl;
            continue;
        }
        else {
            out << str1 << std::endl;
            out << str2 << std::endl;
            out << str3 << std::endl;
            out << str4 << std::endl;
            out << str5 << std::endl;
        }
    }
    in.close();
    out.close();
    loading_refresh();
    if(count == 0) { std::cout << "\n\t\t\tNo such Entries found !\n"; return; } 

    out.open("Teachers.txt");
    in.open("Temporary.txt");
    
    if(in && out) 
    {
        while(getline(in, str)) {
            out << str << std::endl;
        }
    }
    in.close();
    out.close();

    // Setting new details...
    std::cout << "\n\t\t\t\tEnter new Name       : "; getline(std::cin, str1);
    std::cout << "\t\t\t\tEnter new Email      : "; getline(std::cin, str3);
    std::cout << "\t\t\t\tEnter new Department : "; getline(std::cin, str4);
    std::cout << "\t\t\t\tEnter new Qualificaiton  : "; getline(std::cin, str5);

    out.open("Teachers.txt", std::ios::app);
    out << str1 << std::endl;
    out << backUpID << std::endl;
    out << str3 << std::endl;
    out << str4 << std::endl;
    out << str5 << std::endl;
    out.close();

}
int CollegeTeachers :: countEntries(int choice) {
    int countEntries = 0;
    std::string line, search;
    std::string s1, s2, s3, s4, s5;

    if(choice == 0) { search = "Computer"; }
    else if(choice == 1) { search = "Mechanical"; }
    else { search = "Electronics"; }

    std::ifstream in;
    in.open("Teachers.txt");

    while(!in.eof() && !in.fail()) {          /* MAIN CORRECT CODE, commented to try something diff...below!! */
        getline(in, s1);
        getline(in, s2);
        getline(in, s3);
        getline(in, s4);
        getline(in, s5);
        if(search == s4) {  //CHECKS IF ENTERED NAME MATCHES THE NAMES IN FILE...
            countEntries++;
        } 
        if(s4 == "Computer") { 
            last_entry_comp = true; 
            last_entry_elec = false; 
            last_entry_mech = false; 
        }
        else if(s4 == "Electronics") {
            last_entry_elec = true; 
            last_entry_comp = false; 
            last_entry_mech = false; 
        }
        else {
                last_entry_mech = true; 
                last_entry_comp = false; 
                last_entry_elec = false; 
            }
    }
    in.close();
    return(countEntries);
}
int CollegeTeachers :: countEntAll() {
    int countEntries = 0;
    std::string line;
    std::ifstream in;
    in.open("Teachers.txt");

    while(getline(in, line)) { countEntries++; }
    return(countEntries/5);
}
void DataBase :: personalInfoPage() {
    
    printHeader();
    std::ifstream in;
    std::string content;
    in.open("PersonalDetails.txt");
    if(in.eof() == 0) {
        getline(in, content, '$');
        std::cout << content;
    }
    in.close();
    std::cout << "\n\n\t\t\t\t\t\t\t\t    "; system("pause");
}
void DataBase :: externalPage() {  //DEFAULT PAGE

    int choice;
    while(true) {
        system("cls");
        printHeader();
        std::vector <std::string> main_menu {
            "Enter Login Page",
            "Know more about program",
            "Reset the password",
            "Exit program"
        };
        choice = menu::arrowMenu(main_menu);
        
        loading_refresh();
        switch(choice) {
            case 0 :loginPage();
                    break;
            case 1 :system("cls");
                    personalInfoPage();
                    break;
            case 2 :system("cls");
                    resetPass();
                    break;
            case 3 :system("cls");
                    printHeader();
                    std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t        .....THANK YOU !.....\n\n\n\n\n";
                    exit(1);
            default:std::cout << std::endl << "\n\t\t\t\t\t\t\t Incorrect Choice Entered ! \n\t\t\t\t\t\t\t "; 
                    system("pause");
        }
    }
}
void DataBase :: loginPage() {  //TO SIGN IN TO THE SYSTEM

    system("cls");
    printHeader();
    std::string pass;
    int ch;
    std::cout << "\n\n\t\tEnter Password : "; pass = encriptPass();
    if(pass == "User123") {

        system("Clear");
        printHeader();
        system("COLOR 0A"); // Sets the text color to green...
        int credDOB, credOTP;
        std::cout << "\n\t\t\t     .................>>>>> WELCOME BOSS <<<<<.................\t\n";
        std::cout << "\n\t\t...Please verify yourself !...\n"
                  << "\n\n\n\t\t\t\tEnter Security Credentials : "; std::cin >> credDOB >> credOTP;
        
        if((credDOB == 1111) && (credOTP == 2222)) { 
            std::cout << "\n\t\t\t\tGranted security access..." 
                      << "\n\t\t\t\tDo you wish to check set password ? [Y/N] ";
            std::string c;
            std::cin >> c;
            if((c == "Y") || (c == "y")) {
                std::cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tSet Password is : ";
                std::cout << password << "  ";
            }
        }
        else { 
            system("COLOR 0C");
            std::cout << "\n\n\t\t\t\tDenied Access :: SYSTEM LOCKED ::"; 
            exit(1);
        }
        std::cout << "\n\n\t\t\t\t";
        system("pause");
        system ("cls");
        system("COLOR 0F"); // Resets the default text color...
    }
    else if(pass == password) {
        std::cout << "\n\n\n\t\t\tAccess Granted ! \n\t\t\t";
        system("pause");
        system ("cls");
    }
    else {
        static int count = {}; // static int count -> cuz, we need to set it only once and not everytime function is called....if not, it will be initialized to 0, everytime the function is called...
        count ++;
        std::cout << "\tAttempt..." << count ;
        std::cout << "\n\n\n\t\t\tAccess Denied ! . . . \n\t\t\t\t";
        if(count == 15) {
            loading_refresh();
            system("clear");
            printHeader();
            std::cout << "\n\n\n\n\t\t\t\tTo check set Password, contact * HAYSTEN D'COSTA * coder\n\n"
                      << "\n\t\t\t\t\t\t. . .SYSTEM LOCKED. . ."; 
            exit(1);
        }
        if((count%5) == 0) {
            // int static seconds_multiples = 1;
            for(int i=15; i>=0; i--) {
                system("cls");
                printHeader();
                std::cout << "\n\n\n\n\n\n\t\t\tTry Again after : " << i <<"s . . .\n\t\t\t";
                Sleep(1000);
            }
            // seconds_multiples++;
        }
        system("pause");
        system("cls");
        loginPage();
    }
    mainPage();
}
void DataBase :: resetPass() {

    printHeader();
    std::string confirm;
    std::cout << "\n\n\n\t\t\t\tDo you wish to reset the password ? [Y/N] : ";
    std::cin >> confirm;
    if((confirm == "Y") || (confirm == "y")) {
        std::cout << "\n\n\n\t\t\t\tEnter your previous password : ";
        std::cin >> confirm;
        if(confirm == password) {
            do {
                std::cout << "\n\t\t\t\tPlease type 'CONFIRM', to proceed : ";
                std::cin >> confirm;
            } while(confirm != "CONFIRM");
            
            std::cout <<"\t\t\t\tEnter new password : ";
            password = encriptPass();
            DataBase D(password);
            externalPage();
        }
        else {
            std::cout << "\n\t\t\tIncorrect password Entered !";
        }
    }
    else {
        externalPage();
    }
}
void DataBase :: mainPage()  {  //MAIN REGISTRATION FUNCTION

    int section_choice;

    while(section_choice != 2) {
        system("cls");
        printHeader();
        std::vector <std::string> section_menu {
            "Enter Students Section",
            "Enter Teachers Section",
            "Log Out"
        };
        section_choice = menu::arrowMenu(section_menu);
        
        loading_refresh();

        switch(section_choice) {
            case 0 : {
                
                int reg_choice {1}; // initialized to 1. If not, we wont enter The registration section.... 

                while(reg_choice != 0) {

                    
                    system("cls");
                    printHeader();
                    CollegeStudents s;
                    CollegeDetails *p = &s;
                    std::cout << "\n\t\t\t1 -> Register New Student....." << std::endl
                              << "\t\t\t2 -> Search For Student..... " << std::endl
                              << "\t\t\t3 -> Delete Student Entry..... " << std::endl
                              << "\t\t\t4 -> Edit Student Entry....." << std::endl
                              << "\t\t\t0 -> Exit Page....." << std::endl
                              << "\n\t\t   .....Enter your choice : "; std::cin >> reg_choice;
                    std::cout << "\n\n\n\t\t\t";
                    system("pause");
                    loading_refresh();
                    switch(reg_choice) {

                        case 1 :

                                system("cls");
                                printHeader();
                                std::cout << "\t\t\t0 -> Register a Computer Student..." << std::endl
                                          << "\t\t\t1 -> Register a Mechanical Student..." << std::endl
                                          << "\t\t\t2 -> Register a Electronics Student..." << std::endl
                                          << "\n\t\t   .....Enter your choice : "; std::cin >> reg_choice;
                                std::cout << "\n\n\n\t\t\t";
                                std::cout << "\n\t\t\tEnter no. of Entries : "; std::cin >> n;
                                for(int i=0; i<n; i++) {

                                    p-> setDetails(reg_choice);
                                    p-> createFile(reg_choice);
                                }
                                std::cout << "\n\t\t\t";
                                system("pause");
                                break;
                        case 2 :
                                system("cls");
                                printHeader();
                                p-> searchDetails(); 
                                std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 3 : 
                                system("cls");
                                printHeader();
                                p-> deleteDetails(); std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 4 : 
                                system("cls");
                                printHeader();
                                p-> editDetails(); std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 0 :break;
                        default:std::cout << "\n\t\t\t    Incorrect Choice Entered !.....\t\t\t " << std::endl;
                                std::cout << "\n\t\t\t";
                                system("pause"); 
                    }
                }

            } break;         
            case 1 : {

                int reg_choice = 1;

                while(reg_choice != 0) {
                    system("cls");
                    printHeader();
                    CollegeTeachers t;
                    CollegeDetails *q = &t;
                    std::cout << "\n\t\t\t1 -> Register New Teacher....." << std::endl
                              << "\t\t\t2 -> Search For Teacher..... " << std::endl
                              << "\t\t\t3 -> Delete Teacher Entry..... " << std::endl
                              << "\t\t\t4 -> Edit/Update Teacher Entry..... " << std::endl
                              << "\t\t\t0 -> Exit Page....." << std::endl
                              << "\n\t\t   .....Enter your choice : "; std::cin >> section_choice;
                    std::cout << "\n\n\n\t\t\t";
                    system("pause");
                    loading_refresh();
                    switch(reg_choice) {
                        case 1 :

                                system("cls");
                                printHeader();
                                std::cout << "\t\t\t0 -> Register a Computer Teacher..." << std::endl
                                          << "\t\t\t1 -> Register a Mechanical Teacher..." << std::endl
                                          << "\t\t\t2 -> Register a Electronics Teacher..." << std::endl
                                          << "\n\t\t   .....Enter your choice : "; std::cin >> reg_choice;
                                std::cout << "\n\n\n\t\t\t";
                                std::cout << "\n\t\t\tEnter no. of Entries : "; std::cin >> n;
                                for(int i=0; i<n; i++) {

                                    q-> setDetails(reg_choice);
                                    q-> createFile(reg_choice);
                                }
                                std::cout << "\n\t\t\t";
                                system("pause");
                                break;
                        case 2 :
                                system("cls");
                                printHeader();
                                q-> searchDetails(); std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 3 : 
                                system("cls");
                                printHeader();
                                q-> deleteDetails(); std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 4 : 
                                system("cls");
                                printHeader();
                                q-> editDetails(); std::cout << "\n\n\t\t\t\t\t\t\t\t";
                                system("pause");
                                break;
                        case 0 :break;
                        default:std::cout << "\n\t\t\t    Incorrect Choice Entered !.....\t\t\t " << std::endl;
                                std::cout << "\n\t\t\t";
                                system("pause"); 
                    }
                }
            } break;
            case 2 :return;
            default:std::cout << "\n\t\t\t    Incorrect Choice Entered !.....\t\t\t " << std::endl;
                    std::cout << "\n\t\t\t";
                    system("pause"); 
        }
    }
}
#endif