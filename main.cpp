#include <iostream>
#include "20241123_DAmbrosi_Library_BST.h"
#include "20241123_DAmbrosi_Library_BST.cpp"
using namespace std;

int main(){
    Node *root=new Node(50);
    root=root->insertR(23);
    root=root->insertR(25);
    root=root->insertR(10);
    root=root->insertR(104);
    root=root->insertR(53);
    root=root->insertR(208);
    root->inOrder();
    return 0;
}