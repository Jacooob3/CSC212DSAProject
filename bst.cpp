#include "bst.h"
#include <vector>
#include <iostream>

BSTNode::BSTNode() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}
BSTNode::BSTNode(int num) {
    this->data = num;
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
BSTNode* BST::insert(int data, BSTNode* p){
    if(p == nullptr){
        BSTNode *q = new BSTNode(data);
        return q;
    }
    if(data < p->data){
        p->left = insert(data, p->left);
    }
    else if(data > p->data){
        p->right = insert(data, p->right);
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

void BST::insert(int d) {
    this->root = insert(d, this->root);
}
BSTNode* BST::search(int d) {
    BSTNode* tmpParent = this->root;
    if(this->root->data == d){
        return this->root;
    }
    else{
        BSTNode* tmp = this->root;
        while(true){
            if(tmp == nullptr){
                return nullptr;
            }
            else if(tmp->data == d){
                return tmpParent;
            }
            else if(tmp->data < d){
                tmpParent = tmp;
                tmp = tmp->right;
            }
            else{
                tmpParent = tmp;
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
void BST::preorder(std::ofstream &os) {
    printPreOrderRec(this->root, os);
    os << " \n";
}
void BST::printPreOrderRec(BSTNode *p, std::ofstream &os){
    if(p == nullptr){
        return;
    }
    os << p->data << " ";
    printPreOrderRec(p->left, os);
    printPreOrderRec(p->right ,os);
}
void BST::inorder(std::ofstream &os) {
    BST::printInOrderRec(this->root, os);
    os << " \n";
}
void BST::printInOrderRec(BSTNode *p, std::ofstream &os){
    if(p == nullptr){
        return;
    }
    printInOrderRec(p->left,os);
    os << p->data << " ";
    printInOrderRec(p->right,os);
}
void BST::postorder(std::ofstream &os) {
    BST::printPostOrderRec(this->root, os);
    os << " \n";
}
void BST::printPostOrderRec(BSTNode *p, std::ofstream &os){
    if(p == nullptr){
        return;
    }
    printPostOrderRec(p->left,os);
    printPostOrderRec(p->right,os);
    os << p->data << " ";
}
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
void BST::destroy(BSTNode *p) {
    delete p;
}