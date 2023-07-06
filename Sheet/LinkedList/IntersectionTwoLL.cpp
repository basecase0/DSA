/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* one=headA;
        ListNode* two=headB;
        if(one==NULL||two==NULL){
            return NULL;
        }
        while(one!=two){
            if(one==NULL){
                one=headB;
            }
            else{
                one=one->next;
            }
            if(two==NULL){
                two=headA;
            }
            else{
                two=two->next;
            }
        }
        
        return one;
    }
};