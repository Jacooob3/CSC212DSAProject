#include "student.h"

Student::Student(){};
Student::Student(int num, std::string firstname, std::string lastname, std::vector<std::string> classes_temp){
    this->id = num;
    this->first_name = firstname;
    this->last_name = lastname;
    for(int i = 0; i < classes_temp.size(); i++){
        this->classes.push_back(classes_temp[i]);
    }
}

int Student::get_id(){
    return this->id;
}