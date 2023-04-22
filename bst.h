#pragma once
#include "student.h"
#include <fstream>
#include <sstream>

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

public:
    BST();
    ~BST();
    void preorder(std::ofstream &os);
    void inorder(std::ofstream &os);
    void postorder(std::ofstream &os);
    void insert(Student student);
    BSTNode* rotateLeft(BSTNode* tmp);
    BSTNode* rotateRight(BSTNode* tmp);
    BSTNode *search(int d);
    int getHeight();
};

