#ifndef DATASTRUCTURE_LINKED_QUEUE_H
#define DATASTRUCTURE_LINKED_QUEUE_H
#endif //DATASTRUCTURE_LINKED_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
struct node{
    T data;
    node *next;
};

template <class T>
class linked_Queue{
private:
    node<T>* front;
    node<T>* rear;
public:
    linked_Queue();
    void prt_linked_Queue();
    int check_linked_Queue();
    void ins_linked_Queue(T);
    T del_linked_Queue();
};
//初始化
template <class T>
linked_Queue<T>::linked_Queue() {
    front=NULL;
    rear=NULL;
}
//输出
template <class T>
void linked_Queue<T>::prt_linked_Queue() {
    node<T>* pointer;
    pointer=front;
    if(pointer==NULL){
        cout<<"Empty Queue"<<endl;
        return;
    }
    do{
        cout<<pointer->data<<endl;
        pointer=pointer->next;
    }while(pointer!=NULL);
    return;
}
//检测状态
template <class T>
int linked_Queue<T>::check_linked_Queue() {
    if(front==NULL)return 0;
    return 1;
}
//入队
template <class T>
void linked_Queue<T>::ins_linked_Queue(T ins_data) {
    node<T> *new_node;
    new_node=new node<T>;
    new_node->data=ins_data;
    new_node->next=NULL;
    //空队列
    if(rear==NULL) front=new_node;
    //原来的rear->next变成new_node
    //赋完值后，将new_node置为rear
    else rear->next=new_node;
    rear=new_node;
    return;
}
//退队
template <class T>
T linked_Queue<T>::del_linked_Queue() {
    T del_data;
    node<T> *del_pointer;
    if(front==NULL) {
        cout<<"Empty Queue!"<<endl;
        return 0;
    }
    del_data=front->data;
    del_pointer=front;
    front=del_pointer->next;
    delete del_pointer;
    if(front==NULL) rear=NULL;
    return del_data;
}
