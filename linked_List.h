#ifndef DATASTRUCTURE_LINKED_LIST_H
#define DATASTRUCTURE_LINKED_LIST_H
#endif //DATASTRUCTURE_LINKED_LIST_H

#include "iostream"
using namespace std;
template <class T>
struct node{
    T data;
    node *next;
};

template <class T>
class linked_List{
private:
    node<T> *head;
public:
    linked_List();
    void prt_linked_List();
    void ins_linked_List(T,T);
    int del_linked_List(T);
};
//create
template <class T>
linked_List<T>::linked_List() {
    head=NULL;
    return;
}
//print
template <class T>
void linked_List<T>::prt_linked_List() {
    node<T> *pointer;
    pointer=head;
    if(pointer==NULL){cout<<"Empty Linked List!"<<endl;return;}
    do{cout<<pointer->data<<endl;
    pointer=pointer->next;}while(pointer!=NULL);
    return;
}
//insert
template <class T>
void linked_List<T>::ins_linked_List(T old_data, T ins_data) {
    node<T> *new_pointer,*tmp_pointer;
    new_pointer=new node<T>;
    new_pointer->data=ins_data;
    if(head==NULL){
        head=new_pointer;
        new_pointer->next=NULL;
        return;
    }
    
    if(head->data==old_data){
        new_pointer->next=head;
        head=new_pointer;
        return;
    }
    tmp_pointer=head;
    while((tmp_pointer->next!=NULL) && (((tmp_pointer->next)->data)!=old_data)){
        tmp_pointer=tmp_pointer->next;
    }
    new_pointer->next=tmp_pointer->next;
    tmp_pointer->next=new_pointer;
}
//delete
template <class T>
int linked_List<T>::del_linked_List(T del_data) {
    node<T> *tmp_pointer,*pointer;
    if(head==NULL) return 0;
    if((head->data)==del_data){
        tmp_pointer=head->next;
        delete head;
        head=tmp_pointer;
        return 1;
    }
    pointer=head;
    while((pointer->next!=NULL)&&(((pointer->next)->data)!=del_data)){
        pointer=pointer->next;
    }
    if(pointer->next==NULL) return 0;
    tmp_pointer=pointer->next;
    pointer->next=tmp_pointer->next;
    delete tmp_pointer;
    return 1;
}
