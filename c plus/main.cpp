//
//  main.cpp
//  c plus
//
//  Created by xjq on 2020/10/27.
//

#include <iostream>
#include "util/util.cpp"
#include "structure/List.cpp"


using namespace std;

int main(){
    List<int> l;
 
    l.insertAsFirst(1);
    l.insertAsFirst(0);
    l.insertAsLast(2);
    l.insertAsLast(3);
    
    l.remove(l.first());
    l.log();
    return 0;
}
