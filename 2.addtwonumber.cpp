// You are given two non-empty linked lists representing two non-negative integers. 

// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//https://leetcode.com/problems/add-two-numbers/



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x,z,k;
        int h=0;
        x=l1->val;
        z=l2->val;
        if(x+z+h>9) {
            k=(x+z+h)%10;
            h=(x+z+h)/10;
        }
        else {
            k=x+z+h;
            h=0;
        }
        l1=l1->next;
        l2=l2->next; 
        ListNode *l3= new ListNode(k);
        ListNode *prev=l3;
        if(l1==NULL&&l2==NULL&&h!=0) {
            ListNode *l4=new ListNode(h);
            prev->next=l4;
        }
        
        while(l1!= NULL || l2!=NULL) {
            if(l1!=NULL && l2==NULL) {
                x=l1->val;
                z=0;
                l1=l1->next;
            }
            if(l1==NULL && l2!=NULL) {
                x=0;
                z=l2->val;
                l2=l2->next;
            }
            if (l1!=NULL && l2!=NULL) {
                x=l1->val;
                z=l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            
            if(x+z+h>9) {
                k=(x+z+h)%10;
                h=(x+z+h)/10;
            }
            else {
                    k=x+z+h;
                    h=0;
            }
            ListNode *l4=new ListNode(k);
            prev->next=l4;
            prev=l4; 
        }
        if(h!=0){
            ListNode *l5=new ListNode(h);
            prev->next=l5;
        }
        return l3;
    }
};