#ifndef DATASTRUCTURE_CIR_LINKED_LIST_H
#define DATASTRUCTURE_CIR_LINKED_LIST_H
#endif //DATASTRUCTURE_CIR_LINKED_LIST_H

#include "iostream"

using namespace std;

template <class T>
struct node{
    T data;
    node *next;
};
template <class T>
class Cir_linked_List{
private:
    node<T> *head;
public:
    Cir_linked_List();
    void prt_Cir_linked_List();
    void ins_Cir_linked_List(T,T);
    int del_Cir_linked_List(T);
};
//建立空链表
template <class T>
Cir_linked_List<T>::Cir_linked_List() {
    node<T> *pointer;
    pointer=new node<T>;
    pointer->data=0;
    pointer->next=pointer;
    head=pointer;
    return;
}
//遍历
template <class T>
void Cir_linked_List<T>::prt_Cir_linked_List() {
    node<T>* pointer;
    pointer=head->next;
    if(pointer==head){
        cout<<"Empty Cir_Linked List!"<<endl;return;
    }
    do{cout<<pointer->data<<endl;
    pointer=pointer->next;}
    while(pointer!=head);
    return;
}
//插入
template <class T>
void Cir_linked_List<T>::ins_Cir_linked_List(T old_data, T ins_data) {
    node<T> *pointer,*new_point;
    new_point=new node<T>;
    new_point->data=ins_data;
    pointer=head;
    while((pointer->next!=head)&&(((pointer->next)->data)!=old_data))
        pointer=pointer->next;
    new_point->next=pointer->next;
    pointer->next=new_point;
    return;
}
//删除
template <class T>
int Cir_linked_List<T>::del_Cir_linked_List(T old_data) {
    node<T> *pointer,*del_point;
    pointer=head;
    while((pointer->next!=head)&&(((pointer->next)->data)!=old_data))
        pointer=pointer->next;
    //无这个元素
    if(pointer->next==head) return 0;
    del_point=pointer->next;
    pointer->next=del_point->next;
    delete del_point;
    return 1;
}
