#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <locale>

#include "bst.h"

void makeSchedule(std::string file_name,BST tree) {};
std::string uppercase(std::string command);
std::string openFile();

int main() {
    //open file
    std::string file_name = openFile();

    BST tree;

    makeSchedule(file_name, tree);

    std::string out_file;
    std::cout << "Enter name of output file (.csv):" << std::endl;
    std::cin >> out_file;

    bool cont = true;
    std::string command;
    while (cont) {
        std::cout << "If you want to print out all students' schedules, enter 'ALL'" << std::endl;
        //Maybe can add this as an option
        //std::cout << "If you want to see the amount of students in a course, enter 'COURSE'" << std::endl;
        std::cout << "If you want to search and print a student's schedule, enter 'SEARCH'" << std::endl;
        std::cout << "If you want to add a new student and their schedule, enter 'ADD'" << std::endl;
        std::cout << "If you want to delete a student, enter 'DELETE'" << std::endl;
        std::cout << "If you want to enroll a student in an additional course, enter 'ENROlL'" << std::endl;
        std::cout << "If you want to unenroll a student from a course, enter 'UNENROLL'" << std::endl;
        std::cin >> command;
        command = uppercase(command);
        //Adding code to allow these commands to run
        if (command == "ALL") {

        }
        else if (command == "SEARCH") {
            int id_num;
            std::string id_string;

            std::cout << "Enter new student's ID number:" << std::endl;
            std::cin >> id_string;

        }
        else if (command == "ADD") {
            int id_num;
            std::string id_string;

            std::cout << "Enter new student's ID number:" << std::endl;
            std::cin >> id_string;

            //can either continue with this and take inputs 1 by 1, or have user input a csv file with new student's details

        }
        else if (command == "DELETE") {
            int id_num;
            std::string id_string;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> id_string;

            //delete function here

        }
        else if (command == "ENROLL") {
            int id_num;
            std::string id_string;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> id_string;

        }
        else if (command == "UNENROLL") {
            int id_num;
            std::string id_string;

            std::cout << "Enter new student's ID number:" << std::endl;
            std::cin >> id_string;

        }
        else {
            std::cout << "Wrong command inputted, try again." << std::endl;
        }
    }
    return 0;
}
std::string openFile(){
    std::string file_name;
    bool correct_file = false;
    while (!correct_file) {
        std::cout << "Enter file name:" << std::endl;
        std::cin >> file_name;

        std::fstream file(file_name);

        if (file.is_open()) {
            return file_name;
        }
        else {
            std::cout << "File " << file_name << " cannot be found. Try again" << std::endl;
        }
    }
}
std::string uppercase(std::string command){
    std::locale loc;
    std::string temp = command;
    for(int i = 0; i < command.length(); i++){
        std::toupper(temp[i], loc);
    }
    return temp;
}
