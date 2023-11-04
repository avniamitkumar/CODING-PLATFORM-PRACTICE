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
    ListNode *fun(ListNode* head, int val)
    {
        if(!head)
        {
            return NULL;
        }
        if(!head->next)
        {
            if(head->val==val)
            {
                return NULL;
            }
            return head;
        }
        ListNode *p=fun(head->next,val);
        if(head->val==val)
        {
            return p;
        }
        head->next=p;
        return head;
    }

    ListNode* removeElements(ListNode* head, int val) {
        return fun(head,val);
    }
};