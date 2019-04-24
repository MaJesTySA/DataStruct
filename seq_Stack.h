#ifndef DATASTRUCTURE_SEQ_STACK_H
#define DATASTRUCTURE_SEQ_STACK_H
#endif //DATASTRUCTURE_SEQ_STACK_H

#include "iostream"
using namespace std;

template <class T>
class seq_Stack{
private:
    int length;
    int top;
    T *Stack;
public:
    explicit seq_Stack(int);
    void prt_seq_Stack();
    int check_seq_Stack();
    void ins_seq_Stack(T);
    T del_seq_Stack();
    T read_seq_Stack();
};
//create empty stack
template <class T>
seq_Stack<T>::seq_Stack(int m) {
    length=m;
    top=0;
    Stack=new T[length];
    return;}

//print stack
template <class T>
void seq_Stack<T>::prt_seq_Stack() {
    cout<<"top pointer position="<<top<<endl;
    for(int i=top;i>0;i--)
        cout<<Stack[i-1]<<endl;
    return;
}

//check status
template <class T>
int seq_Stack<T>::check_seq_Stack() {
    if(top==length) return(-1);
    if(top==0) return(0);
    return(1);
}

//insert
template <class T>
void seq_Stack<T>::ins_seq_Stack(T ins_data) {
    if(top==length)
    {cout<<"overflow!"<<endl; return;}
    top=top+1;
    Stack[top-1]=ins_data;
    return;
}

//delete
template <class T>
T seq_Stack<T>::del_seq_Stack() {
    T del_data;
    if(top==0)
    {cout<<"uderflow!"<<endl;return(0);}
    del_data=Stack[top-1];
    top=top-1;
    return(del_data);
}

//read top
template <class T>
T seq_Stack<T>::read_seq_Stack() {
    if(top==0)
    {cout<<"empty stack!"<<endl;return(0);}
    return(Stack[top-1]);
}
