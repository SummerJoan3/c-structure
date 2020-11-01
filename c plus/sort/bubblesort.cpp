//
//  bubblesort.cpp
//  c plus
//
//  Created by xjq on 2020/10/30.
//

#include "bubblesort.hpp"
#include "../structure/vector.cpp"

using namespace std;

template <class T> void bubblesort(MyVector<T> &v){
    int temp;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j]){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}
