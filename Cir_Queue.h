#ifndef DATASTRUCTURE_CIR_QUEUE_H
#define DATASTRUCTURE_CIR_QUEUE_H
#endif //DATASTRUCTURE_CIR_QUEUE

#include "iostream"
using namespace std;

template <class T>
class Cir_Queue{
private:
    int length;
    int front;
    int rear;
    int flag;
    T* Queue;
public:
    explicit Cir_Queue(int);
    void prt_cir_Queue();
    int check_cir_Queue();
    void ins_cir_Queue(T);
    T del_cir_Queue();
};
//create empty queue
template <class T>
Cir_Queue<T>::Cir_Queue(int m) {
    length=m;
    Queue=new T[length];
    front=length;rear=length;flag=0;
    return;
}

//print
template <class T>
void Cir_Queue<T>::prt_cir_Queue() {
    cout<<"front position="<<front<<endl;
    cout<<"rear position="<<rear<<endl;
    if(flag==0) {cout<<"EMPTY QUEUE!"<<endl;return;}
    int i=front;
    do{
        i=i+1;
        if(i==length+1)
            i=1;
        cout<<Queue[i-1]<<endl;}while(i!=rear);
    return;
}

//check
template <class T>
int Cir_Queue<T>::check_cir_Queue() {
    if((flag==1)&&(front=rear))return(-1);
    if(flag==0)return(0);
    return(1);
}

//insert
template <class T>
void Cir_Queue<T>::ins_cir_Queue(T ins_data) {
    if((flag==1)&&(front==rear))
    {cout<<"Overflow"<<endl;return;}
    rear=rear+1;
    //full,can not insert
    if(rear==length+1) rear=1;
    Queue[rear-1]=ins_data;
    flag=1;
    return;
}

//delete
template <class T>
T Cir_Queue<T>::del_cir_Queue() {
    T del_data;
    if(flag==0){cout<<"Underflow!"<<endl;return 0;}
    front=front+1;
    if(front==length+1)front=1;
    del_data=Queue[front-1];
    if(front==rear) flag=0;
    return del_data;
}
