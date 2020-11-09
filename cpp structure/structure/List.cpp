//
//  List.cpp
//  c plus
//
//  Created by xjq on 2020/11/5.
//

#include "List.hpp"

typedef int Rank;

template <typename T> class List{
private:
    int _size;ListNodePosi(T) head;ListNodePosi(T) tail;
protected:
    void init();
    int clear();
    void copyNodes(ListNodePosi(T) p,int n);
public:
    // 构造函数
    List(){init();};
    List(List<T> const& L);
    
    // 析构函数
    ~List(){clear();delete head;delete tail;};
    
    // 只读接口
    Rank size()const{return _size;};
    bool empty()const{return _size<=0;};
    T& operator[](Rank r)const;
    ListNodePosi(T) first()const{return head->succ;};
    ListNodePosi(T) last(){return tail->pred;};
    ListNodePosi(T) find(T const& e)const
    {return find(e,_size,tail);};
    ListNodePosi(T) find(T const& e,int n,ListNodePosi(T) p)const;
    void sort(ListNodePosi(T),int);
    void sort(){sort(head,_size);};
    void selectionSort(ListNodePosi(T),int);
    void selectMax(ListNodePosi(T),int);
    void log();
    
    // 可写接口
    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    T remove(ListNodePosi(T) p);
};

template <typename T>
void List<T>::init(){
    head=new ListNode<T>;
    tail=new ListNode<T>;
    head->succ=tail;head->pred=NULL;
    tail->pred=head;tail->succ=NULL;
    _size=0;
}


template <typename T>
T& List<T>::operator[](Rank r)const{
    ListNodePosi(T) p = first();
    while (0<r--) {
        p=p->succ;
    }
    return p->data;
    
}
    

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(const T &e){
    _size++;
    return head->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(const T &e){
    _size++;
    return tail->insertAsPred(e);
}

template <typename T>
int List<T>::clear(){
    int oldSize = _size;
    while (0<_size) {
        remove(head->succ);
    }
    return oldSize;
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p){
    T ret = p->data;
    p->succ->pred = p->pred;
    p->pred->succ = p->succ;
    delete p;_size--;
    return ret;
}

template <typename T>
void List<T>::log(){
    ListNodePosi(T) p=first();
    while (p!=tail) {
        std::cout << p->data;
        p=p->succ;
    }
}

template <typename T>
ListNodePosi(T) List<T>::find(T const& e,int n,ListNodePosi(T) p)const{
    while (n--) {
        if(e==(p=p->pred)->data)return p;
    }
    return NULL;
}

template <typename T>
void List<T>::copyNodes(ListNode<T> *p, int n){
    init();
    while (n--) {
        insertAsLast(p->data);p=p->succ;
    }
}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n){
    
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n){
    
}
    
template <typename T>
void List<T>::selectMax(ListNodePosi(T) p, int n){
    
}

