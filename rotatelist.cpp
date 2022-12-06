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
       ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = 0;
        ListNode* p = head;
        while(p) p = p->next, len++;
        k = k % len;
        if(k == 0) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(k > 0) fast = fast->next, k--;
        while(fast->next) fast = fast->next, slow = slow->next;
        
        ListNode* res = slow->next;
        
        slow->next = NULL;
        fast->next = head;
        
        return res;
    }
};