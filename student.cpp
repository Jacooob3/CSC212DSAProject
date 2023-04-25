#include "student.h"

Student::Student(){};
//establish student object -constructor
Student::Student(int num, std::string firstname, std::string lastname, std::string email, std::vector<std::string> classes_temp){
    this->id = num;
    this->first_name = firstname;
    this->last_name = lastname;
    for(int i = 0; i < classes_temp.size(); i++){
        this->classes.push_back(classes_temp[i]);
    }
}

//retrieves student id number
int Student::get_id(){
    return this->id;
}

//retrieves student email
std::string Student::get_email(){
    return this->email;
}

//retrieves list of classes of a student
std::vector<std::string> Student::get_classes() {
    return this->classes;
}

//gets student name by pair first name and last name together
std::pair<std::string, std::string> Student::get_name() {
    std::pair<std::string, std::string> temp(this->first_name,this->last_name);
    return temp;
}
//add classes to student
void Student::add_classes(std::string class_name) {
    this->classes.push_back(class_name);
}

//remove classes from student
void Student::remove_classes(std::string class_name) {
    std::vector<std::string> temp;
    //go through list of classes
    for (int i = 0; i < this->classes.size(); i++) {
        if (this->classes[i] == class_name) {
            continue;
        }
        //reassigns each class in list to remove
        else{
            temp.push_back(this->classes[i]);
        }
    }
    this->classes = temp;
}
