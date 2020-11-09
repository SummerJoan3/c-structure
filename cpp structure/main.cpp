//
//  main.cpp
//  c plus
//
//  Created by xjq on 2020/10/27.
//

#include <iostream>
#include "util/util.cpp"
#include "structure/BinTree.cpp"

using namespace std;

void visit(int data){
    cout << data << endl;
}

int main(){
    BinTree<int> tree;
    tree.insertAsRoot(3);
    tree.insertAsLC(tree.root(), 2);
    tree.insertAsLC(tree.root()->lChild, 1);
    tree.insertAsRC(tree.root(), 4);
    tree.travPre(visit);
    return 0;
}
