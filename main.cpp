#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <locale>
#include "student.h"
#include "bst.h"

void makeSchedule(std::string file_name,BST* tree);
std::string uppercase(std::string command);
std::string openFile();
int main() {
    //open file
    std::string file_name = openFile();

    BST tree;

    makeSchedule(file_name, &tree);

    std::string out_file;
    std::cout << "Enter name of output file (.csv):" << std::endl;
    std::cin >> out_file;
    std::ofstream os;
    bool cont = true;
    std::string command;
    while (cont) {
        std::cout << "If you want to print out all students' schedules, enter 'ALL'" << std::endl;
        std::cout << "If you want to see the amount of students in a course, enter 'COURSE'" << std::endl;
        std::cout << "If you want to search and print a student's schedule, enter 'SEARCH'" << std::endl;
        std::cout << "If you want to add a new student and their schedule, enter 'ADD'" << std::endl;
        std::cout << "If you want to delete a student, enter 'DELETE'" << std::endl;
        std::cout << "If you want to enroll a student in an additional course, enter 'ENROlL'" << std::endl;
        std::cout << "If you want to unenroll a student from a course, enter 'UNENROLL'" << std::endl;
        std::cout << "If you want to stop program, enter 'QUIT'" << std::endl;
        std::cin >> command;
        command = uppercase(command);
        //Adding code to allow these commands to run
        if (command == "ALL") {
            os.open(out_file);
            tree.inorder(os);
            os.close();
        }

        else if (command == "COURSE") {
            std::string course;
            std::cout << "Enter the course title:" << std::endl;
            std::cin >> course;
            std::cout << "The number of students in this course is " << tree.courseCount(course);
        }
        
        else if (command == "COURSE") {
            std::string course;
            std::cout << "Enter the course title:" << std::endl;
            std::cin >> course;
            std::cout << "The number of students in this course is " << tree.courseCount(course);
        }

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

        }
        else if (command == "ADD") {
            std::string out_put;
            std::cout << "To enter new student's data by terminal, enter 'TERMINAL', to enter by csv file, enter 'FILE'" << std::endl;
            std::cin >> out_put;
            bool cont_add = true;

            while (cont_add) {
                if (out_put == "TERMINAL") {
                    int id_num;
                    std::string last_name;
                    std::string first_name;
                    std::vector<std::string> classes;
                    std::string temp;

                    std::cout << "Enter new student's ID number:" << std::endl;
                    std::cin >> temp;
                    id_num = stoi(temp);
                    std::cout << "Enter new student's Last Name:" << std::endl;
                    std::cin >> last_name;
                    std::cout << "Enter new student's First Name:" << std::endl;
                    std::cin >> first_name;

                    std::cout << "Enter new student's class:" << std::endl;
                    while (std::cin >> temp) {
                        if (temp == "QUIT") {
                            break;
                        }
                        classes.push_back(temp);
                        std::cout << "Enter new student's class or enter 'QUIT' to quit:" << std::endl;
                    }

                    Student new_student(id_num, first_name, last_name, classes);
                    tree.insert(new_student);
                    cont_add = false;
                } else if (out_put == "FILE") {
                    std::string file;
                    std::cout << "Enter file name:" << std::endl;
                    std::cin >> file;
                    makeSchedule(file, &tree);
                    cont_add = false;
                } else {
                    std::cout << "Wrong command inputted, try again" << std::endl;
                }
            }
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

        }
        else if (command == "UNENROLL") {
            int id_num;
            std::string temp;

            std::cout << "Enter student's ID number:" << std::endl;
            std::cin >> temp;
            id_num = stoi(temp);

            if (tree.search(id_num) != nullptr) {
                std::cout << "Enter course to unenroll:" << std::endl;
                std::cin >> temp;
                tree.remove_course(tree.search(id_num), temp);
            }
            else {
                std::cout << "Student ID not found" << std::endl;
            }
        }
        else if (command == "QUIT") {
            cont = false;
        }
        else {
            std::cout << "Wrong command inputted, try again." << std::endl;
        }
        os << "\n";
    }
    //os.close();

    return 0;
}
void makeSchedule(std::string file_name,BST* tree){
    std::fstream file;
    file.open(file_name, std::ios::in);
    int num;
    std::string line, temp, last_name, first_name, class_name;
    std::getline(file, line);
    while(std::getline(file, line)) {
        std::vector<std::string> classes;
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        std::getline(ss, last_name, ',');
        std::getline(ss, first_name , ',');
        while(std::getline(ss,class_name, ',')){
            //add to class student
            classes.push_back(class_name);
        }
        long int id = stoi(temp);
        Student new_student(id, first_name, last_name, classes);
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
    std::locale loc;
    std::string temp = command;
    for(int i = 0; i < command.length(); i++){
        std::toupper(temp[i], loc);
    }
    return temp;
}
