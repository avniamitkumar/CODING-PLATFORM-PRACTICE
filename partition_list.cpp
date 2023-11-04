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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode *small=new ListNode (0,0);
        ListNode *large=new ListNode (0,0);
        ListNode *p,*q;
        p=small;
        q=large;
        ListNode* t=head;
        while(t)
        {
            if(t->val<x)
            {
                small->next=t;
                small=small->next;
            }
            else
            {
                large->next=t;
                large=large->next;
            }
            t=t->next;
        }
        large->next=NULL;
        small->next=q->next;
        return p->next;

    }
};