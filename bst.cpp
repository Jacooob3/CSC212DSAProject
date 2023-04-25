#include "bst.h"
#include <vector>
#include <iostream>
#include <ostream>

BSTNode::BSTNode(Student student) {
    this->data = student;
    this->left = nullptr;
    this->right = nullptr;
}
BSTNode::~BSTNode(){
    if(this->left != nullptr && this->right != nullptr){
        delete this->left;
        delete this->right;
    }
}
BST::BST() {
    this->root = nullptr;
}
BST::~BST() {
    destroy(this->root);
}

//takes a Student object and inserts it into the tree in the appropriate place
BSTNode* BST::insert(Student student, BSTNode* p){
    if(p == nullptr){
        BSTNode *q = new BSTNode(student);
        return q;
    }
    if(student.get_id() < p->data.get_id()){
        p->left = insert(student, p->left);
    }
    else if(student.get_id() > p->data.get_id()){
        p->right = insert(student, p->right);
    }
    //Rotate
    int leftH = getHeightRec(p->left);
    int rightH = getHeightRec(p->right);
    if(leftH >= rightH + 2){
        p = rotateRight(p);
    }
    else if(rightH >= leftH + 2){
        p = rotateLeft(p);
    }
    return p;
}

void BST::insert(Student student) {
    this->root = insert(student, this->root);
}

//Takes a specfic class from the user and searches through each students' list of classes to determine how many of them are in that specific class.
int BST::courseCount(std::string courseName) {
    return courseCountRec(this->root, courseName);
}
int BST::courseCountRec(BSTNode *tmp, std::string courseName) {
    if (tmp == nullptr){
        return 0;
    }
    int count = 0;
    int i = 0;
    while(i < tmp->data.get_classes().size()){
        if(tmp->data.get_classes()[i] == courseName){
            count+= 1;
        }
        i++;
    }
    return count + courseCountRec(tmp->left, courseName) + courseCountRec(tmp->right, courseName);
}
//takes an ID and returns the node in the tree that corresponds to that ID, or nullptr if the ID is not found in the tree
BSTNode* BST::search(int d) {
    //BSTNode* tmpParent = this->root;
    if(this->root->data.get_id() == d){
        return this->root;
    }
    else{
        BSTNode* tmp = this->root;
        while(true){
            //Student ID does not exist
            if(tmp == nullptr){
                return nullptr;
            }
                //we have found the correct student ID
            else if(tmp->data.get_id() == d){
                return tmp;
            }
                //look to the node to the right
            else if(tmp->data.get_id() < d){
                //tmpParent = tmp;
                tmp = tmp->right;
            }
                //look to the node to the left
            else{
                //tmpParent = tmp;
                tmp = tmp->left;
            }
        }
    }
}
//Rotate
BSTNode* BST::rotateLeft(BSTNode* tmp){
    BSTNode* p = tmp->right;
    tmp->right = p->left;
    p->left = tmp;
    return p;
}
BSTNode* BST::rotateRight(BSTNode* tmp) {
    BSTNode *p = tmp->left;
    tmp->left = p->right;
    p->right = tmp;

    return p;
}
//Print
void BST::inorder(std::ofstream &os) {
    std::cout << "Succesfully added the following students to your output file: \n";
    os << "Student ID, FirstName LastName, Classes\n";
    BST::printInOrderRec(this->root, os);
    os << " \n";
}
void BST::printInOrderRec(BSTNode *p, std::ofstream &os){
    if(p == nullptr){
        return;
    }
    printInOrderRec(p->left,os);
    os << p->data.get_id() << ",";
    std::cout << p->data.get_id() << " " << p->data.get_name().first << " " << p->data.get_name().second << " " << p->data.get_email();
    int i = 0;
    while(i < p->data.get_classes().size()){
        std::cout << " " << p->data.get_classes()[i];
        i++;
    }
    std::cout << "\n";
    std::vector<std::string> temp = p->data.get_classes();
    os << p->data.get_name().first << " " << p->data.get_name().second << ", ";
    for (int i = 0; i < temp.size(); i++) {
        os << temp[i] << " ";
    }
    os << "\n";
    printInOrderRec(p->right,os);
}

//returns the height of the tree
int BST::getHeightRec(BSTNode* tmp) {
    if(tmp == nullptr){
        return 0;
    }
    int lh = getHeightRec(tmp->left);
    int rh = getHeightRec(tmp->right);
    if(lh > rh){
        return lh + 1;
    }
    else{
        return rh + 1;
    }
}
int BST::getHeight() {
    return getHeightRec(this->root);
}
//called by the destructor to free the memory allocated by the nodes
void BST::destroy(BSTNode *p) {
    delete p;
}
//print node/Student information
void BST::print_node(BSTNode *tmp, std::ofstream &os) {
    os << tmp->data.get_id() << ", " << tmp->data.get_name().first << " " << tmp->data.get_name().second << ", ";
    std::cout << tmp->data.get_id() << ", " << tmp->data.get_name().first << " " << tmp->data.get_name().second << ", ";
    std::vector<std::string> temp = tmp->data.get_classes();
    for (int i = 0; i < temp.size(); i++) {
        os << temp[i] << " ";
        std::cout <<temp[i]<< " ";
    }
    os << "\n";
    std::cout << "\n";
}
//adds course to student's list of classes.
void BST::add_course(BSTNode *tmp, std::string course) {
    tmp->data.add_classes(course);
    std::cout << tmp->data.get_name().first << " " << tmp->data.get_name().second << " has been successfully enrolled in " << course << "\n";
}
//removes course from student's list of classes
void BST::remove_course(BSTNode *tmp, std::string course) {
    tmp->data.remove_classes(course);
}
void BST::delete_student(int id) {
    root = delete_rec(root, id);
}

BSTNode* BST::delete_rec(BSTNode* node, int id) {
    if (node == nullptr) {
        return node;
    }

    if (id < node->data.get_id()) {
        node->left = delete_rec(node->left, id);
    } else if (id > node->data.get_id()) {
        node->right = delete_rec(node->right, id);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        node->data = find_min_value(node->right);
        node->right = delete_rec(node->right, node->data.get_id());
    }
    return node;
}

Student BST::find_min_value(BSTNode* node) {
    Student min_val = node->data;
    while (node->left != nullptr) {
        min_val = node->left->data;
        node = node->left;
    }
    return min_val;
}
