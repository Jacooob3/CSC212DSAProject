#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "student.h"
#include "bst.h"


void makeSchedule(std::string file_name,BST* tree);

std::string uppercase(std::string command);
//takes a string and returns a copy of the string with all characters converted to uppercase

std::string openFile();

int main() {
    //open file
    std::string file_name = openFile();

    BST tree;
    //creates a binary search tree
    makeSchedule(file_name, &tree);
    //Creates Output File
    std::string out_file;
    std::cout << "Enter name of output file (.csv):" << std::endl;
    std::cin >> out_file;
    std::ofstream os;

    bool cont = true;
    std::string command;
    //enters a loop that prompts the user for commands and executes the corresponding code based on the command entered
    while (cont) {
        std::cout << "If you want to print out all students' schedules, enter 'ALL'" << std::endl;
        std::cout << "If you want to see the amount of students in a course, enter 'COURSE'" << std::endl;
        std::cout << "If you want to search and print a student's schedule, enter 'SEARCH'" << std::endl;
        std::cout << "If you want to add a new student and their schedule, enter 'ADD'" << std::endl;
        std::cout << "If you want to delete a student, enter 'DELETE'" << std::endl;
        std::cout << "If you want to enroll a student in an additional course, enter 'ENROLL'" << std::endl;
        std::cout << "If you want to unenroll a student from a course, enter 'UNENROLL'" << std::endl;
        std::cout << "If you want to stop program, enter 'QUIT'" << std::endl;
        std::cin >> command;
        command = uppercase(command);
        std::cout << "\n";

        //Adding code to allow these commands to run
        if (command == "ALL") {
            os.open(out_file); //open an output file
            tree.inorder(os); //prints out all student's schedules by performing an inorder traversal of the BST
            os.close();
            std::cout << "\n";
        }
        //
        else if (command == "COURSE") {
            std::string course;
            std::cout << "Enter the course title:" << std::endl;
            std::cin >> course;
            std::cout << "There are " << tree.courseCount(course) << " in " << course << "\n";
            std::cout << "\n";
        }
        //
        else if (command == "SEARCH") {
            int id_num;
            std::string temp;
            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> temp;
            id_num = stoi(temp);

            if (tree.search(id_num) != nullptr) {
                os.open(out_file);
                tree.print_node(tree.search(id_num), os);
                os.close();
            }
            else {
                std::cout << "Student ID not found" << std::endl;
            }
            std::cout << "\n";
        }
        else if (command == "ADD") {
            bool cont_add = true;
            while (cont_add) {
                std::string out_put;
                std::cout << "To enter new student's data by terminal, enter 'TERMINAL', to enter by csv file, enter 'FILE'" << std::endl;
                std::cin >> out_put;
                out_put = uppercase(out_put);
                if (out_put == "TERMINAL") {
                    int id_num;
                    std::string last_name, first_name, email;
                    std::vector<std::string> classes;
                    std::string temp;

                    std::cout << "Enter new student's ID number:" << std::endl;
                    std::cin >> temp;
                    id_num = stoi(temp);
                    std::cout << "Enter new student's Last Name:" << std::endl;
                    std::cin >> last_name;
                    std::cout << "Enter new student's First Name:" << std::endl;
                    std::cin >> first_name;
                    std::cout << "Enter new student's email:" << std::endl;
                    std::cin >> email;

                    std::cout << "Enter new student's class:" << std::endl;
                    while (std::cin >> temp) {
                        temp = uppercase(temp);
                        if (temp == "QUIT") {
                            break;
                        }
                        classes.push_back(temp);
                        std::cout << "Enter new student's class or enter 'QUIT' to quit:" << std::endl;
                    }

                    Student new_student(id_num, first_name, email, last_name, classes);
                    tree.insert(new_student);
                    cont_add = false;
                }
                else if (out_put == "FILE") {
                    std::string file;
                    std::cout << "Enter file name:" << std::endl;
                    std::cin >> file;
                    makeSchedule(file, &tree);
                    cont_add = false;
                } else {
                    std::cout << "Wrong command inputted, try again" << std::endl;
                }
            }
            std::cout << "\n";
        }
        else if (command == "DELETE") {
            int id_num;
            std::string id_string;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> id_string;

            id_num = std::stoi(id_string);
            
            if (tree.search(id_num) != nullptr) {
                tree.delete_student(id_num);
            }
            else {
                std::cout << "Student ID not found" << std::endl;
            }
        }
        else if (command == "ENROLL") {
            int id_num;
            std::string temp;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> temp;
            id_num = stoi(temp);

            if (tree.search(id_num) != nullptr) {
                std::cout << "Enter enrolled course:" << std::endl;
                std::cin >> temp;
                tree.add_course(tree.search(id_num), temp);
            }
            else {
                std::cout << "Student ID not found" << std::endl;
            }
            std::cout << "\n";
        }
        else if (command == "UNENROLL") {
            int id_num;
            std::string temp;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> temp;
            id_num = stoi(temp);
            //find the student using student id
            if (tree.search(id_num) != nullptr) {
                std::cout << "Enter course to unenroll:" << std::endl;
                std::cin >> temp;
                tree.remove_course(tree.search(id_num), temp); //remove the course
            }
            else {
                std::cout << "Student ID not found" << std::endl;
            }
            std::cout << "\n";
        }
        else if (command == "QUIT") {
            cont = false;
            //the while loop to terminate and the program to exit
        }
        else {
            std::cout << "Wrong command inputted, try again." << std::endl;
        }
        os << "\n";
    }
    //os.close();

    return 0;
}

//takes a filename and a pointer to a binary search tree as arguments, reads the data from the
//file, and inserts the data into the tree
void makeSchedule(std::string file_name,BST* tree){
    std::fstream file;
    file.open(file_name, std::ios::in);
    int num;
    std::string line, temp, last_name, first_name, class_name, email;
    std::getline(file, line);
    while(std::getline(file, line)) {
        std::vector<std::string> classes;
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        std::getline(ss, last_name, ',');
        std::getline(ss, first_name , ',');
        std::getline(ss,email, ',');
        while(std::getline(ss,class_name, ',')){
            //add to class student
            classes.push_back(class_name);
        }
        long int id = stoi(temp);
        Student new_student(id, first_name, last_name, email, classes);
        tree->insert(new_student);
    }
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
    int i = 0;
    while(command[i]){
        command[i] = toupper(command[i]);
        i++;
    }
    return command;
}
