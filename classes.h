/*
!   CLASSES_H : Contains all the class declarations....
*/
#ifndef CLASSES_H
#define CLASSES_H

    #include <iostream>

class CollegeDetails {  // Class Template....
    protected :
        std::string name;
        std::string email;
        std::string branch;
        std::string department;
        std::string qualification;
        // roll_no <- in case of students and
        // id      <- in case of teachers, is 'automatically' generated/set based on the no. of students/teachers already registered....
    
    public : 
    //? These member functions can be defined in own way for students and teachers classes... 
    //? these are pure virtual functions which can be derived by any other class... to reduce redudancy and improve the code...

        virtual void setDetails(int choice) = 0; // Function sets required details (based choice of branch entered)....
        virtual void createFile(int choice) = 0; // Function creates and stores details set, to a database (text file)....
        virtual void searchDetails() = 0;  // Function searched for required entry from text file....
        virtual void deleteDetails() = 0;  // Function deletes required entry from txt file....
        virtual void editDetails() = 0;    // Function edits details of required entry from txt file....
};

class CollegeStudents : public CollegeDetails { //? College Students will derive all characteristics from College Details(abstract class)....

    public : 
        void setDetails(int choice); // We will define these functions as required by the CollegeStudents (classes.cpp)....
        void createFile(int choice);
        void searchDetails();
        void deleteDetails();
        void editDetails();
        int countEntries(int choice);
        int countEntAll();
};
class CollegeTeachers : public CollegeDetails { //? College Teachers will derive all characteristics from College Details(abstract class)....

    public : 
        void setDetails(int choice);
        void createFile(int choice);
        void searchDetails();
        void deleteDetails();
        void editDetails();
        int countEntries(int choice);
        int countEntAll();
};
class DataBase : public CollegeStudents, public CollegeTeachers { //? DataBase will derive from the CollegeStudents and CollegeTeachers class....

    private :
        std::string password; // password for the system....

    public :
        DataBase() = default; // default constructor set-up....
        DataBase(std::string password) // parameterized constructor....
        { 
            this -> password = password; 
        }
        void mainPage(); // these functions are defined in the classes.cpp file....
        void loginPage();
        void resetPass();
        void externalPage();
        void personalInfoPage();
};

#endif