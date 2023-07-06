#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node. */
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iterator=head;
        // Pass one
        while(iterator!=NULL){
            Node* nxt=iterator->next;
            Node* copy=new Node(iterator->val);
            copy->next=nxt;
            iterator->next=copy;
            iterator=nxt;
        }
        // pass two
        iterator=head;
        while(iterator!=NULL){
            if(iterator->random!=NULL){
                iterator->next->random=iterator->random->next;
            }
            iterator=iterator->next->next;
        }
        // pass three
        iterator=head;
        Node* dcHead=new Node(0);
        Node* copy=dcHead;
        while(iterator!=NULL){
            Node* nxt=iterator->next->next;
            copy->next=iterator->next;
            iterator->next=nxt;
            iterator=nxt;
            copy=copy->next;
        }
        return dcHead->next;
    }
};