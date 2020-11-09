//
//  main.cpp
//  c plus
//
//  Created by xjq on 2020/10/27.
//

#include <iostream>
#include "util/util.cpp"
#include "structure/List.cpp"
#include <stack>
#include <vector>

using namespace std;

int main(){
//    List<int> l;
    List<int> l;
    l.insertAsFirst(1);
//    l.insertAsFirst(0);
//    l.insertAsLast(2);
//    l.insertAsLast(3);
    
//    l.log();
    
    vector<int> v;
    
    stack<int> s;
    s.push(1);
    
    cout << s.top() << endl;
    cout << s.size();
    return 0;
}
