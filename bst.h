#pragma once
#include "student.h"
#include <fstream>
#include <sstream>
#include <ostream>

class BSTNode{
private:
    Student data;
    BSTNode* left;
    BSTNode* right;
    friend class BST;
public:
    // Overloading
    BSTNode();
    BSTNode(Student student);
    ~BSTNode();

};
class BST{
private:
    BSTNode *root;
    void destroy(BSTNode *p);
    BSTNode* insert(Student student, BSTNode *p);
    void printPreOrderRec(BSTNode *root, std::ofstream &os);
    void printInOrderRec(BSTNode *root, std::ofstream &os);
    void printPostOrderRec(BSTNode *root, std::ofstream &os);
    int getHeightRec(BSTNode* root);
    BSTNode* delete_rec(BSTNode* node, int id);

public:
    BST();
    ~BST();
    void preorder(std::ofstream &os);
    void inorder(std::ofstream &os);
    void postorder(std::ofstream &os);
    void insert(Student student);
    BSTNode* rotateLeft(BSTNode* tmp);
    BSTNode* rotateRight(BSTNode* tmp);
    BSTNode* search(int d);
    int courseCount(std::string courseName);
    int courseCountRec(BSTNode* tmp, std::string courseName);
    void print_node(BSTNode* tmp, std::ofstream &os);
    int getHeight();
    void add_course(BSTNode* tmp, std::string course);
    void remove_course(BSTNode* tmp, std::string course);
    void delete_student(int id);
    Student find_min_value(BSTNode* node);
}
};
