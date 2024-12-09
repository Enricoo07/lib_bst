#include "20241123_DAmbrosi_Library_BST.h"
#include "20241123_DAmbrosi_Library_BST.cpp"
#include <iostream>
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

    cout << endl;
    cout << root;
    cin >> root;
    cout << root << ""; 

    Node *n;
    cin>>n;
    // cout << n << "";
    return 0;
}