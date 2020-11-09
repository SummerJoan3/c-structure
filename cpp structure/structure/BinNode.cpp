//
//  BinNode.cpp
//  cpp structure
//
//  Created by xjq on 2020/11/9.
//

#include "BinNode.hpp"
using namespace std;

template <typename T> struct BinNode{
    T data;
    BinNodePosi(T) parent;BinNodePosi(T) lChild;BinNodePosi(T) rChild;
    int height;
    int npl;
    RBColor color;
    BinNode():parent(NULL),lChild(NULL),rChild(NULL),height(0),npl(1),color(RB_RED){};
    BinNode(T e,BinNodePosi(T) p=NULL,BinNodePosi(T) lc=NULL,BinNodePosi(T) rc=NULL,int h=0,int l=1,RBColor c=RB_RED):data(e),parent(p),lChild(lc),rChild(rc),height(h),npl(l),color(c){};
    
    int size();
    BinNodePosi(T) insertAsLC(T const& e);
    BinNodePosi(T) insertAsRC(T const& e);
    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travPost(VST&);
    template <typename VST> void travIn(VST&);
};


template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(const T &e){
    return lChild=new BinNode(e,this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(const T &e){
    return rChild=new BinNode(e,this);
}

template <typename T> template <typename VST>
void BinNode<T>::travPre(VST& visit){
    switch (rand()%5) {
        case 1:
            travPre_R(this,visit);
            break;
        default:
            travPre_R(this,visit);
            break;
    }
}

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST & visit){
    travIn_R(this, visit);
}

template <typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST& visit){
    if(!x)return;
    visit(x->data);
    travPre_R(x->lChild, visit);
    travPre_R(x->rChild, visit);
}

template <typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST& visit){
    if(!x)return;
    travIn_R(x->lChild, visit);
    visit(x->data);
    travIn_R(x->rChild, visit);
}

template <typename T> template <typename VST>
void BinNode<T>::travPost(VST & visit){
    travPost_R(this,visit);
}

template <typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST& visit){
    if(!x)return;
    travPost_R(x->lChild, visit);
    travPost_R(x->rChild, visit);
    visit(x->data);
}

template <typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,stack<BinNodePosi(T)>& S){
    while(x){
        visit(x->data);
        S.push(x->rChild);
        x=x->lChild;
    }
}

template <typename T,typename VST>
void travPre_I2(BinNodePosi(T) x,VST& visit){
    stack<BinNodePosi(T)> S;
    while (true) {
        visitAlongLeftBranch(x, visit, S);
        if(S.empty())break;
        x=S.top();
        S.pop();
    }
}

