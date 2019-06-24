#ifndef DATASTRUCTURE_LINKED_STACK_H
#define DATASTRUCTURE_LINKED_STACK_H
#endif //DATASTRUCTURE_LINKED_STACK_H

#include "iostream"

using namespace std;

template <class T>
struct node{
    T data;
    node *next;
};

template <class T>
class linked_Stack{
private:
    node<T> *top;
public:
    linked_Stack();
    void prt_linked_Stack();
    int check_linked_Stack();
    void ins_linked_Stack(T);
    T del_linked_Stack();
    T read_linked_Stack();
};
//初始化
template <class T>
linked_Stack<T>::linked_Stack() {
    top=NULL;
    return;
}
//输出遍历
template <class T>
void linked_Stack<T>::prt_linked_Stack() {
    node<T> *pointer;
    pointer=top;
    if(pointer==NULL){
        cout<<"Empty Stack!"<<endl;return;
    }
    do{
        cout<<pointer->data<<endl;
        pointer=pointer->next;
    }while(pointer!=NULL);
    return;
}
//检查状态
template <class T>
int linked_Stack<T>::check_linked_Stack() {
    if(top==0) return 0;
    return 1;
}
//入栈
template <class T>
void linked_Stack<T>::ins_linked_Stack(T ins_data) {
    node<T> *new_top;
    new_top=new node<T>;
    new_top->data=ins_data;
    new_top->next=top;
    top=new_top;
    return;
}
//退栈
template <class T>
T linked_Stack<T>::del_linked_Stack() {
    T del_data;
    node<T> *tmp_pointer;
    if(top==NULL){
        cout<<"Empty Stack!"<<endl;return 0;
    }
    tmp_pointer=top;
    del_data=tmp_pointer->data;
    top=tmp_pointer->next;
    delete tmp_pointer;
    return del_data;
}
//读栈顶
template <class T>
T linked_Stack<T>::read_linked_Stack() {
    if(top==NULL){
        cout<<"Empty Stack!"<<endl;return 0;
    }
    return (top->data);
}
