#pragma once
#include <string>
#include <vector>
class Student{
private:
    int id;
    std::string first_name, last_name;
    std::vector<std::string> classes;
public:
    Student();
    Student(int id, std::string firstname, std::string lastname, std::vector<std::string> classes);
    int get_id();
    void change_id(int num);
    void change_first(std::string first);
    void change_last(std::string last);
    void add_classes(std::string class_name);
};