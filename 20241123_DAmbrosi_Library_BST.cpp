#include <iostream>
#include "20241123_DAmbrosi_Library_BST.h"
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

//scorrimento ricorsivo Preorder traversal

void Node:: preOrder(){
    cout<<this->data<<" ";
    if(this->lchild!=NULL){
        this->lchild->preOrder();
    }
    if(this->rchild!=NULL){
        this->rchild->preOrder();
    }
}

//scorrimento ricorsivo Postorder traversal

void Node:: postOrder(){
    if(this->lchild!=NULL){
        this->lchild->postOrder();
    }
    if(this->rchild!=NULL){
        this->rchild->postOrder();
    }
    cout<<this->data<<" ";
}

//delete ricorsivo di un nodo con this

Node* Node::deleteNode(int k) {
    if (this->data==NULL){
        cout << "non posso cancellare un nodo che non c'è" << endl;
        return this;
    }
    if (k==this->data){
        if (this->lchild==NULL && this->rchild==NULL){
            delete [] this;
            return this;
        } else if(this->lchild!=NULL && this->rchild==NULL){
            Node* temp;
            temp->data=this->data;
            this->data=this->lchild->data;
            this->lchild->data=temp->data;
            delete [] this->lchild;
            return this;
        } else if(this->lchild==NULL && this->rchild!=NULL){
            Node* temp;
            temp->data=this->data;
            this->data=this->rchild->data;
            this->rchild->data=temp->data;
            delete [] this->rchild;
            return this;
        }
    }
    if (k<this->data){
        this->lchild= this->lchild->insertR(k);
    } else {
        this->rchild= this->rchild->insertR(k);
    }
    return this;
}    

// verifico se è un bst

bool Node:: isBst(){
    if(this==NULL){
        cout << "l'albero e vuoto";
        return true;
    }
    if(this->lchild!=NULL && this->lchild->data<this->data){
        return this->lchild->isBst();
    }else if(this->lchild!=NULL && this->lchild->data>this->data){
        return false;
    }
    if(this->rchild!=NULL && this->rchild->data>this->data){
        return this->rchild->isBst();
    }else if(this->rchild!=NULL && this->rchild->data<this->data){
        return false;
    }
    return true;
}
