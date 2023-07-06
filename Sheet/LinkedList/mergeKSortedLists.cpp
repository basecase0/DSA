#include<bits/stdc++.h>
using namespace std;

/**
* Definition for singly-linked list.   */
struct ListNode {
    int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode* merge2Lists(ListNode* head1,ListNode* head2){
        if(head1==NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode* ans=head1;
        ListNode* tail;
        if(head1->val>head2->val){
            ans=head2;
            head2=head2->next;
        }
        else{
            head1=head1->next;
        }
        tail=ans;
        while(head1 && head2){
            if(head1->val<head2->val){
                tail->next=head1;
                tail=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=head2;
                head2=head2->next;
            }
        }
        if(head1) tail->next=head1;
        if(head2) tail->next=head2;

        return ans;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        if(k<2) return lists[0];
        int i=0;
        ListNode* one=lists[0];
        ListNode* two=lists[1];
        ListNode* res=merge2Lists(one,two);
        i=2;
        while(i<k){
            ListNode* three=lists[i];
            res=merge2Lists(res,three);
            i++;
        }
        return res;
    }
};