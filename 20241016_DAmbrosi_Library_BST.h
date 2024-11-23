#include <iostream>
using namespace std;

// crea nodo generale

struct node {
    int data;
    int weight;
    node *lchild;
    node *rchild;
    node (int key){
        data = key;
        weight = 1;
        lchild = nullptr;
        rchild = nullptr;
    }
};

//crea nodo con ricorsione

node *insertR(node *r, int key){
    if(r == nullptr){
        return new node(key);
    }
    if(r->data == key){
        r->weight++;
        return r;
    }
    if(r->data>key){
        r->lchild = insertR(r->lchild,key);
    }else{
        r->rchild = insertR(r->rchild,key);
    }
    return r;
}

//crea nodo con iterazione

node* insertI(node* r, int key){
    bool check {true};
    node* current {r};
    node* father {nullptr};
    while (check){
        if(current==NULL){
            if(father->data>key){
                father->lchild = new node(key);
                check = false;
                return r;
            } else {
                father->rchild = new node(key);
                check = false;
                return r;
            }
        check = false;
        }
        if(current->data==key){
            check = false;
            current->weight++;
            return r;
        }
        if(current->data>key){
            father = current;
            current = current->lchild;
        } else {
            father = current;
            current = current->rchild;
        }
    }
    return r;
}

//cerca nodo con ricorsione

void searchR(node* r, int key){
    if(r==NULL){
        cout<<key<<" non è presente nel BST."<<endl;
    }
    if(r->data==key){
        cout<<key<<" è presente nel BST."<<endl;
    }
    if(r->data>key){
        searchR(r->lchild, key);
    } else{
        searchR(r->rchild, key);
    }
}

//cerca nodo con iterazione

void searchI(node *r, int key){
    bool check {true};
    node* current {r};
    node* father {nullptr};
    while (check){
        if(current==NULL){
            cout << "Non trovato" << endl;
            check = false;
            break;
        }
        if(current->data==key){
            cout << "Trovato!" << endl;
            check = false;
            break;
        }
        if(current->data>key){
            father = current;
            current = current->lchild;
        } else {
            father = current;
            current = current->rchild;
        }
    }
}

// cancellazione ricorsiva

node* cancelR(node* r, int key){
    if(r==NULL){
        cout<<key<<" non posso cancellarlo."<<endl;
        return r;
    }
    if(r->data == key){
        if(r->lchild==NULL && r->rchild==NULL){
            delete r;
            r->data = 0;
            r->lchild = nullptr;
            r->rchild = nullptr;
            return r;
        }
        if(r->lchild==NULL){
            node* temp = r->rchild;
            delete r;
            r->data = 0;
            r->lchild = nullptr;
            r->rchild = nullptr;
            return temp;
        }
        if(r->rchild==NULL){
            node* temp = r->lchild;
            delete r;
            r->data = 0;
            r->lchild = nullptr;
            r->rchild = nullptr;
            return temp;
        }
    }
    if(key<r->data){
        r->lchild = cancelR(r->lchild, key);
    } else{
        r->rchild = cancelR(r->rchild, key);
    }
    return r;
}

// cancellazione iterattiva

node *cancelI(node *r, int key){
    bool check {true};
    node *current {r};
    node *father {r};
    do{  
        if(current->data==key){
            if(current->rchild!=NULL){
                int temp = current->data;
                current->data = current->rchild->data;
                current->rchild->data = temp;
                current->rchild->data=0;
                current->rchild=nullptr;
                current->lchild=nullptr;
                delete current->rchild;
                check = false;
                return r;
            } else if(current->lchild!=NULL){
                int temp = current->data;
                current->data = current->lchild->data;
                current->lchild->data = temp;
                current->lchild->data=0;
                current->lchild=nullptr;
                current->rchild=nullptr;
                delete current->lchild;
                check = false;
                return r;
            }  else if(current->lchild==nullptr && current->rchild==nullptr){
                current->data=0;
                current=nullptr;
                delete current;
                check=false;
                return r;
            }
        }  else if(key<current->data){
            father = current;                       
            current = current->lchild;             
        } else {
            father = current;
            current = current->rchild;
        }
    }while(check);
    return r;
}

//scorrimento ricorsivo Preorder traversal

void Preorder_Traversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        cout<<r->data<<" ";
        if(r->lchild!=NULL){
            Preorder_Traversal(r->lchild );
        }
        if(r->rchild!=NULL){
            Preorder_Traversal(r->rchild );
        }
    }
}

//scorrimento ricorsivo Inorder traversal

void InorderTraversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        if(r->lchild!=NULL){
            InorderTraversal(r->lchild );
        }
        cout<<r->data<<" ";
        if(r->rchild!=NULL){
            InorderTraversal(r->rchild );
        }
    }
}

//scorrimento ricorsivo Postorder traversal

void PostorderTraversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        if(r->lchild!=NULL){
            PostorderTraversal(r->lchild );
        }
        if(r->rchild!=NULL){
            PostorderTraversal(r->rchild );
        }
        cout<<r->data<<" ";
    }
}

// calcolo dell'altezza ricorsiva

int max(int l,int rc){
    if (l>rc){
        return l;
    } else
    return rc;
}
int height(node *r){
    if(r==NULL){
        return 0;
    }
    int l=height(r->lchild);
    int rc=height(r->rchild);
    return max(l,rc)+1;
}

// verifico che un bst sia un bst

