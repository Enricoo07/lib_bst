#include <iostream>
#include "20241123_DAmbrosi_Library_BST.h"
#include "20241123_DAmbrosi_Library_BST.cpp"
using namespace std;

int main(){
    Node *root=new Node(50);
    root=root->insertR(23);
    root=root->insertR(25);
    root=root->insertR(10);
    root=root->insertI(104);
    root=root->insertI(53);
    root=root->insertI(208);
    cout << "iterativo" << endl;
    cout << root->searchI(40) << endl;
    cout << root->searchI(25) << endl;
    cout << "ricorsivo" << endl;
    cout << root->searchR(40) << endl;
    cout << root->searchR(25) << endl;
    cout << "stampa inorder" << endl;
    root->inOrder();

    Node *n=new Node(34);
    cout << "Il nodo è:" << n << endl;
    cout << "dammi un nuovo valore" << endl;
    cin >> n;
    cout << "ora il valore del nodo è:" << n << endl; 
    return 0;
}