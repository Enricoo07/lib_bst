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
    cout << endl;
    cout << "stampa preorder" << endl;
    root->preOrder();
    cout << endl;
    cout << "stampa postorder" << endl;
    root->postOrder();
    cout << endl;
    cout << "cancella nodo iterativo" << endl;
    cout << root->deleteNode(208) << endl;
    cout << root->deleteNode(104) << endl;
    cout << "is bst" << endl;
    cout << root->isBst() << endl;
    return 0;
}