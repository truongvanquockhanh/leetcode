// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/



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
        ListNode *mau=head;
        int i=0,a=1;
        while(mau!=NULL) {
            i=i+1;
            mau=mau->next;
        }
        ListNode *l3= new ListNode(head->val);
        ListNode *prev=l3;
        head=head->next;
        while (a<i) {
             if (a!=i-n) {
                ListNode *l4=new ListNode(head->val);
                prev->next=l4;
                prev=l4;
                
             }
            head=head->next;
            a++;
        }
        if (n==i) {
            l3=l3->next;
        }
        return l3;
    }
};