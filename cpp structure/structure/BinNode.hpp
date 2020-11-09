//
//  BinNode.hpp
//  cpp structure
//
//  Created by xjq on 2020/11/9.
//

#ifndef BinNode_hpp
#define BinNode_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <stack>

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)?p->height:-1)
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rChild)
#define HasChild(x) (HasLChild(x)||HasRChild(x))
#define HasBothChild(z) (HasLChild(x)&&HasRChild(x))
#define IsLeaf(x) (!HasChild(x))


typedef enum {RB_RED,RB_BLACK} RBColor;


#endif /* BinNode_hpp */
