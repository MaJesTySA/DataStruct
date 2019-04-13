#ifndef DATASTRUCTURE_SEQ_LIST_H
#define DATASTRUCTURE_SEQ_LIST_H
#endif //DATASTRUCTURE_SQ_LIST_H

#include "iostream"
using namespace std;
template<class T>
class seq_List{
private:
    int length;
    int ele_num;
    T *List;
public:
    seq_List(){length=0;ele_num=0;return;}
    explicit seq_List(int);
    void prt_seq_List();
    int check_seq_List();
    void ins_seq_List(int,T);
    void del_seq_List(int);
};
//Create an empty list
template <class T>
seq_List<T>::seq_List(int m)
{
    length=m;
    List=new T[length];
    ele_num=0;
    return;
}
//Print list
template <class T>
void seq_List<T>::prt_seq_List() {
    cout<<"Number of elements：" <<ele_num<<endl;
    for(int i=0;i<ele_num;i++)
    {
        cout<<List[i]<<endl;
    }
    return;
}
//Check status
template <class T>
int seq_List<T>::check_seq_List() {
    //Full list
    if(ele_num==length)return(-1);
    //Empty list
    if(ele_num==0)return(0);
    return(1);
}
//Insert Element
template <class T>
void seq_List<T>::ins_seq_List(int pos, T ins_data) {
    if(ele_num==length){cout<<"overflow!"<<endl; return;}
    //insert behind the last element
    if(pos>ele_num) pos=ele_num+1;
    //insert front the first element
    if(pos<1) pos=1;
    for(int i=ele_num;i>=pos;i--)
        List[i]=List[i-1];
    List[pos-1]=ins_data;
    ele_num=ele_num+1;
    return;
}
//Delete Element
template <class T>
void seq_List<T>::del_seq_List(int pos) {
    if(ele_num==0){cout<<"underflow!"<<endl; return;}
    if((pos<1)||(pos>ele_num)){cout<<"No such element exists!"<<endl;return;}
    for(int k=pos;k<ele_num;k++)
        List[k-1]=List[k];
    ele_num=ele_num-1;
    return;
}
