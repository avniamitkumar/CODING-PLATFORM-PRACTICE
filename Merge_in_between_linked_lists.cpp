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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        int ind=0;
        while(ind<a-1)
        {
            curr=curr->next;
            ind++;
        }
        ListNode*mid=curr;
        while(ind<b+1)
        {
            curr=curr->next;
            ind++;
        }
        ListNode*end=curr;
        ListNode *second=list2 ,* head=list2;
        while(second->next!=NULL)
        {
            second=second->next;
        }
        mid->next=head;
        second->next=end;
        return list1;
    }
};