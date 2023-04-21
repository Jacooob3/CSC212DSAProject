#pragma once
#include <string>
#include <vector>
class student{
private:
    int id;
    std::string first_name, last_name;
    std::vector<std::string> classes;
public:
    void change_id(int num);
    void change_first(std::string first);
    void change_last(std::string last);
    void add_classes(std::string class_name);
};