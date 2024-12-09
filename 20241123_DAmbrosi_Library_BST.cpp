#include "20241123_DAmbrosi_Library_BST.h"
#include <iostream>
using namespace std;

//crea nodo con ricorsione

Node* Node::insertR(int k) {
    if (k==this->data){
        this->weight++;
        return this;
    }
    if (k<this->data){
        if (this->lchild == NULL){
            this->lchild= new Node (k);
        } else{
            this->lchild= this->lchild->insertR(k);
        }
    } else if (this->rchild== NULL){
        this->rchild= new Node(k);
    } else {
        this->rchild= this->rchild->insertR(k);
    }
    return this;
}

//scorrimento ricorsivo Inorder traversal

void Node:: inOrder(){
    if(this->lchild!=NULL){
        this->lchild->inOrder();
    }
    cout<<this->data<<" ";
    if(this->rchild!=NULL){
        this->rchild->inOrder();
    }
}

//ricerca iterativa

bool Node:: searchI(int k){
    bool check{true};
    Node *current{this};
    while (check){

        if (current==NULL){
            cout << "non trovato" << " ";
            return false;
        }

        if(current->data==k){
            cout << "trovato" << " ";
            return true;
        }
        if (k<current->data){
            current = current->lchild;
        } else {
            current=current->rchild;
        }
    }
    return -1;
}

// ricerca ricorsiva di k

bool Node:: searchR(int k){
    if (this==NULL){
        cout << "non trovato" << " ";
        return false;
    }
    if (this->data==k){
        cout << "trovato" << " ";
        return true;
    }
    if (k<this->data){
        return this->lchild->searchR(k);
    } else {
        return this->rchild->searchR(k);
    }
}

// inserimento iterativo di k

Node* Node::insertI(int k) {
    Node *current{this};
    Node *parent{nullptr};
    while (current != NULL) {
        if (current->data == k) {
            current->weight++;
            return this;
        }
        if (k < current->data) {
            parent = current;
            current = current->lchild;
        } else {
            parent = current;
            current = current->rchild;
        }
    }

    Node *n = new Node(k);
    if (k < parent->data) {
        parent->lchild = n;
    } else {
        parent->rchild = n;
    }
    return this;
}

ostream& operator<<(ostream& o, const Node* node){
    o << "Data-> " << node->data << " (" << node->weight << ")" << " figlio sinistro: " << "";

    if(node->lchild!=nullptr){
        o << node->lchild->data<< ""; 
    }

    o << " || figlio destro: " << "";

    if(node->rchild!=nullptr){
        o << node->rchild->data << "";
    }

    o << endl;
    return o;
}

istream& operator>>(istream& i, Node* node){
    cout << "dammi un nuovo valore per il nodo" << endl;
    node->weight=1;
    i >> node->data;
    return i;
}