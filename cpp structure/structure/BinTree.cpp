//
//  BinTree.cpp
//  cpp structure
//
//  Created by xjq on 2020/11/9.
//

#include "BinTree.hpp"

template <typename T> class BinTree{
protected:
    int _size;
    BinNodePosi(T) _root;
//    virtual int updateHeight(BinNodePosi(T) x);
//    void updateHeightAbove(BinNodePosi(T) x);
public:
    BinTree():_size(0),_root(NULL){};
    ~BinTree(){if(0<_size)remove(_root);};
    
    int remove(BinNodePosi(T) x);
    BinNodePosi(T) root(){return _root;};
    BinNodePosi(T) insertAsRoot(T const& e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const& e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const& e);
    template <typename VST>
    void travLevel(VST& visit){if(_root)_root->travLevel(visit);}
    template <typename VST>
    void travPre(VST& visit){if(_root)_root->travPre(visit);}
    template <typename VST>
    void travIn(VST& visit){if(_root)_root->travIn(visit);}
    template <typename VST>
    void travPost(VST& visit){if(_root)_root->travPost(visit);}
};


template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, const T &e){
    _size++;
    x->insertAsLC(e);
    return x->lChild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, const T &e){
    _size++;
    x->insertAsRC(e);
    return x->rChild;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T &e){
    _size=1;return _root=new BinNode<T>(e);
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x){
    return 0;
}
