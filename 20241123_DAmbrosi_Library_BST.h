#include <iostream>
using namespace std;
#ifndef _DAMBROSI_LIBRARY_BST_H_
// crea nodo generale
#define _DAMBROSI_LIBRARY_BST_H_
class Node {
    private:
    int data;
    int weight;
    Node *lchild;
    Node *rchild;
    public:
    Node (int key){
        data = key;
        weight = 1;
        lchild = nullptr;
        rchild = nullptr;
    }
    Node* insertR(int k);
    void inOrder();
    bool searchI(int k);
    bool searchR(int k);
    Node* insertI(int k);
};
#endif