//
//  LinkList.cpp
//  c plus
//
//  Created by xjq on 2020/10/27.
//

#include "LinkList.hpp"

using namespace std;

class Node{
public:
    int data;
    Node *next;
    ~Node(){
        delete next;
    }
    Node(int data,Node* next = NULL){
        this->data=data;
        this->next = next;
    }
};

class List{
public:
    Node *head,*tail;
    ~List(){
        delete head;
    }
    
    void print();
    void Insert(int data);
    void Delete(int data);
    int Search(int data);
};


void List::print(){
    Node *p = this->head;
    while(p){
        cout << p->data;
        p=p->next;
    }
};

void List::Insert(int data){
    if(head==NULL){
        head = new Node(data);
        tail=head;
    }else{
        Node *p = new Node(data);
        tail->next = p;
        tail=p;
        tail->next = NULL;
    }
    cout << "Insert Success" << endl;
}

void List::Delete(int data){
    Node *p = head,*q = head;
    if(p==NULL){
        cout << "Sorry,this List is empty" << endl;
        return;
    }
    
    while (p&&p->data!=data) {
        q=p;
        p=p->next;
    }
    if(p==head){
        head=head->next;
    }
    q->next=p->next;
    cout << "Delete Success" << endl;
}

int List::Search(int data){
    Node *p=head;
    if(p==NULL){
        cout << "Search No Result" << endl;
    }
    
    int count = -1;
    while (p) {
        count++;
        if(p->data==data){
            return count;
        }
        p=p->next;
    }
    return count;
}
