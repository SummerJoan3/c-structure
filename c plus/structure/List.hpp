//
//  List.hpp
//  c plus
//
//  Created by xjq on 2020/11/5.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#define ListNodePosi(T) ListNode<T>*

template <typename T>
struct ListNode{
    T data;ListNodePosi(T) pred=NULL;ListNodePosi(T) succ=NULL;
    ListNode(){};
    ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T) s=NULL):data(e),pred(p),succ(s){};
    // 操作接口
    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(const T &e){
    ListNodePosi(T) node = new ListNode(e,pred,this);
    pred->succ=node;pred=node;
    return node;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(const T &e){
    ListNodePosi(T) node = new ListNode(e,this,succ);
    succ->pred = node;succ=node;
    return node;
}

#endif /* List_hpp */
