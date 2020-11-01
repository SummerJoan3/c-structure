//
//  main.cpp
//  c plus
//
//  Created by xjq on 2020/10/27.
//

#include <iostream>
#include "util/util.cpp"
#include "structure/vector.cpp"

using namespace std;

int main(){
    MyVector<int> v;
    v.insert(0, 9);
    v.insert(0, 8);
    v.insert(0, 7);
    v.insert(0, 6);
    v.insert(0, 5);
    v.insert(0, 4);
    v.insert(0, 3);
    v.insert(0, 2);
    v.insert(0, 1);
    v.insert(0, 0);
    
//    v.log();
    return 0;
}
