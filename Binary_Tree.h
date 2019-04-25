#ifndef DATASTRUCTURE_BINARY_TREE_H
#define DATASTRUCTURE_BINARY_TREE_H
#endif //DATASTRUCTURE_BINARY_TREE_H

#include "iostream"
using namespace std;
template <class T>
struct btnode{
    T data;
    btnode* lchild;
    btnode* rchild;
};

template<class T>
class Binary_Tree{
private:
    btnode<T>* BT;
public:
    Binary_Tree(){BT=NULL;return;}
    void create_BT(T);
    void DLR_travBT();
    void LDR_travBT();
    void LRD_travBT();
};

template <class T>
void Binary_Tree<T>::create_BT(T end_flag) {
    btnode<T>* root;
    T data;
    cin>>data;
    if(data==end_flag) return;
    root=new btnode<T>;
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    BT=root;
    create(root,1,end_flag);
    create(root,2,end_flag);
    return;
}

template <class T>
static void create(btnode<T> *pnode,int pos,T end_flag){
    btnode<T> *new_node;
    T data;
    cin>>data;
    if(data!=end_flag){
        new_node=new btnode<T>;
        new_node->data=data;
        new_node->lchild=NULL;
        new_node->rchild=NULL;
        if(pos==1) pnode->lchild=new_node;
        if(pos==2) pnode->rchild=new_node;
        create(new_node,1,end_flag);
        create(new_node,2,end_flag);
    }
    return;
}
//pre-traversal
template <class T>
void Binary_Tree<T>::DLR_travBT() {
    btnode<T>* node;
    node=BT;
    DLR_trav(node);
    cout<<endl;
    return;
}

template <class T>
static void DLR_trav(btnode<T> *node){
    if(node!=NULL){
        cout<<node->data<<"    ";
        DLR_trav(node->lchild);
        DLR_trav(node->rchild);
    }
    return;
}
//int-traversal
template <class T>
void Binary_Tree<T>::LDR_travBT() {
    btnode<T>* node;
    node=BT;
    LDR_trav(node);
    cout<<endl;
    return;
}

template <class T>
static void LDR_trav(btnode<T> *node){
    if(node!=NULL){
        LDR_trav(node->lchild);
        cout<<node->data<<"    ";
        LDR_trav(node->rchild);
    }
    return;
}
//pos-traversal
template <class T>
void Binary_Tree<T>::LRD_travBT() {
    btnode<T>* node;
    node=BT;
    LRD_trav(node);
    cout<<endl;
    return;
}

template <class T>
static void LRD_trav(btnode<T> *node){
    if(node!=NULL){
        LRD_trav(node->lchild);
        LRD_trav(node->rchild);
        cout<<node->data<<"    ";
    }
    return;
}
