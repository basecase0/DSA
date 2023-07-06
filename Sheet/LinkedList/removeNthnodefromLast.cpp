/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==NULL){     // edge case n=size of list.
            head=head->next;
        }
        else{
            prev->next=slow->next;
        }
        return head;
    }
};