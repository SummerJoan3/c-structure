//
//  vector.cpp
//  c plus
//
//  Created by xjq on 2020/10/31.
//

#include "vector.hpp"

using namespace std;

typedef int Rank;
const int DEFAULT_CAPACITY = 3;

template <typename T> class MyVector{
protected:
    Rank _size;int _capacity;T* _elem;
    void copyFrom(T const* A,Rank lo,Rank hi);
    void expand();
    void shrink();
    bool bubble(Rank lo,Rank hi);
    Rank max(Rank lo,Rank hi);
public:
    // 构造函数
    MyVector(int c = DEFAULT_CAPACITY,int s=0,T v=0){
        _elem=new T[_capacity=c];
        for(_size=0;_size<0;_elem[_size++]=v);
    }
    MyVector(T const* A,Rank n){copyFrom(A,0,n);};
    
    // 析构函数
    ~MyVector(){delete [] _elem;};
    // 重载下标操作符
    T& operator[] (Rank r) const;
    MyVector& operator= (MyVector<T> const&);
    // 只读
    Rank size()const{return _size;}
    bool empty()const{return !_size;}
    Rank capacity()const{return _capacity;}
    // 可访问接口
    void log();
    Rank insert(Rank r,T const& e);
    T remove(Rank r);
    int remove(Rank,Rank);
    Rank find(T const& e){return find(e,0,_size);};
    Rank find(T const& e,Rank lo,Rank hi)const;
    void permute(MyVector<T>& v);
    void unsort(Rank lo,Rank hi);
    int unique();
    Rank binSearch(T* A,T const& e,Rank lo,Rank hi);
    Rank search(T const& e,Rank lo,Rank hi);
    Rank push_back(const T& e);
    T pop_back();
};

template <typename T>
void MyVector<T>::expand(){
    if(_size<_capacity)return;//容量未满
    T* oldElem=_elem;
    _elem=new T[_capacity<<=1];
    for(int i= 0;i<_size;i++){
        _elem[i]=oldElem[i];
    }
    delete [] oldElem;
}

template <typename T>
void MyVector<T>::shrink(){
    if(_capacity<DEFAULT_CAPACITY<<1)return;
    if(_size<<2>_capacity)return;
    T* oldElem=_elem;
    _elem= new T[_capacity>>=1];
    for(int i=0;i<_size;i++)_elem[i]=oldElem[i];
    delete [] oldElem;
}

template <typename T>
void MyVector<T>::log(){
    for(int i=0;i<_size;i++) cout<< _elem[i] << ',';
}

template <typename T>
Rank MyVector<T>::find(T const& e,Rank lo,Rank hi)const{
    while((lo<hi--)&&(e==_elem[hi]));
    return hi;
}

template <typename T>
Rank MyVector<T>::insert(Rank r,T const& e){
    expand();
    for(int i=_size;i>r;i--)_elem[i]=_elem[i-1];
    _elem[r]=e;
    _size++;
    return r;
}

template <typename T>
int MyVector<T>::remove(Rank lo, Rank hi){
    if(lo==hi)return 0;
    while(hi<_size){
        _elem[lo++]=_elem[hi++];
    }
    _size=lo;
    shrink();
    return hi-lo;
}

template <typename T>
T MyVector<T>::remove(Rank r){
    T ret=_elem[r];
    remove(r,r+1);
    return ret;
}

template <typename T>
T& MyVector<T>::operator[](Rank r) const{
    return _elem[r];
}

template <typename T>
MyVector<T>& MyVector<T>::operator= (MyVector<T> const& v){
    if(_elem)delete [] _elem;
    copyFrom(v._elem, 0, v._size);
    return *this;
}

template <typename T>
void MyVector<T>::copyFrom(const T *A, Rank lo, Rank hi){
    _elem=new T[_capacity=2*(hi-lo)];
    _size=0;
    while (lo<hi) {
        _elem[_size++]=A[lo++];
    }
}

template <typename T>
void MyVector<T>::permute(MyVector<T> &v){
    for(int i=v.size();i>0;i--){
        cout << rand() << endl;
        swap(v[i-1],v[rand()%i]);
    }
}

template <typename T>
void MyVector<T>::unsort(Rank lo, Rank hi){
    T* V = _elem+lo;
    for(Rank i=hi-lo;i>0;i--){
        swap(V[i-1], V[rand()%i]);
    }
}

template <typename T>
int MyVector<T>::unique(){
    int oldSize=_size;
    Rank i=1;
    while(i<_size){
        find(_elem[i],0,i)>0 ? i++:remove(i);
    }
    return oldSize-_size;
}

template <typename T>
Rank MyVector<T>::binSearch(T* A, T const& e, Rank lo, Rank hi){
    while(lo<hi){
        Rank mi = (lo+hi) >> 1;
        cout << e << "," << A[mi] << endl;
        if(e<A[mi]){
            hi=mi;
        }else if(e>A[mi]){
            lo=mi+1;
        }else{
            return mi;
        }
    }
    return -1;
}

template <typename T>
Rank MyVector<T>::search(T const &e, Rank lo, Rank hi){
    return binSearch(_elem, e, lo, hi);
}


template <typename T>
Rank MyVector<T>::push_back(T const& e){
    expand();
    Rank r = _size;
    _elem[_size++]=e;
    return r;
}

template <typename T>
T MyVector<T>::pop_back(){
    T ret=_elem[--_size];
    return ret;
}
