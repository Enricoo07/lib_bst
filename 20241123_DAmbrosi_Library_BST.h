#include <iostream>
using namespace std;

// crea nodo generale

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
};

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
