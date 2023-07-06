#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 01- addFirstNode 
class Solution01 {
private: ListNode* ohead=NULL;
private:
    void addFirstNode(ListNode* node){
        if(ohead==NULL){
            ohead=node;
        }
        else{
            node->next=ohead;
            ohead=node;
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=NULL;
            addFirstNode(curr);
            curr=next;
        }
        return ohead;
    }
};

// Solution 2 reverse next pointer.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* next;
        ListNode* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* temp=head;
        head=prev;
        return head;
    }
};
int main(){
    
    return 0;
}