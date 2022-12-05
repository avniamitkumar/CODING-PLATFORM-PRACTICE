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
    ListNode* ans = new ListNode(0);
    ListNode* curr = ans;
    int carry = 0;
    while(l1 || l2){
        int sum = 0;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        sum += carry;

        curr->next = new ListNode(sum%10);
        curr = curr->next;

        carry = sum/10;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    if(carry){
        curr->next = new ListNode(carry);
    }
    ans = ans->next;
    return ans;
}

};