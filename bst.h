#pragma once
#include <fstream>
#include <sstream>

class BSTNode{
private:
    int data;
    BSTNode* left;
    BSTNode* right;
    friend class BST;
public:
    // Overloading
    BSTNode();
    BSTNode(int num);
    ~BSTNode();

};
class BST{
private:
    BSTNode *root;
    void destroy(BSTNode *p);
    BSTNode* insert(int d, BSTNode *p);
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
    void insert(int d);
    BSTNode* rotateLeft(BSTNode* tmp);
    BSTNode* rotateRight(BSTNode* tmp);
    BSTNode *search(int d);
    int getHeight();
};

