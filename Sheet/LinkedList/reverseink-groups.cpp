#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private: 
    ListNode* thead=NULL;
    ListNode* ttail=NULL;
private:
    int size(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
private:
    void addFirstNode(ListNode* node){
        if(thead==NULL){
            thead=ttail=node;
        }
        else{
            node->next=thead;
            thead=node;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz=size(head);
        ListNode* ohead=NULL;
        ListNode* otail=NULL;
        ListNode* curr=head;
        while(sz>=k){
            for(int i=0;i<k;i++){
                ListNode* next=curr->next;
                curr->next=NULL;
                addFirstNode(curr);
                curr=next;
            }
            if(ohead==NULL){
                ohead=thead;
                otail=ttail;
            }
            else{
                otail->next=thead;
                otail=ttail;
            }
            thead=NULL;
            ttail=NULL;
            sz-=k;
        }
        otail->next=curr;
        return ohead;
    }
};