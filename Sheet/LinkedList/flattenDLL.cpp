#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};



class Solution {
private: 
    Node* joinchild(Node* parent){
        Node* pnext=parent->next;
        (parent->child)->prev=parent;
        parent->next=parent->child;
        Node* pchild=parent->child;
        while(pchild->child!=NULL || pchild->next!=NULL){
            if(pchild->child!=NULL){
                pchild=joinchild(pchild);
            }
            else{
                pchild=pchild->next;
            }
        }
        parent->child=NULL;
        if(pnext==NULL) return pchild;
        pnext->prev=pchild;
        pchild->next=pnext;
        
        return pnext;
    }
public:
    Node* flatten(Node* head) {
        Node* curr=head;

        while(curr!=NULL){
            Node* next=curr->next;

            if(curr->child!=NULL){ 
                Node*  joinednode=joinchild(curr);
            }
            curr=next;
        }
        return head;
    }
};

int main(){
    
    return 0;
}