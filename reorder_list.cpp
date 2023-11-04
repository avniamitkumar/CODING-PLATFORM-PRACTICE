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
    ListNode* rev(ListNode *head)
    {
        
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr)
        {
            ListNode *fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }


    void reorderList(ListNode* head) {
         if (!head || !head->next || !head->next->next) {
            return; // No need to reorder if the list has 0, 1, or 2 elements.
        }
      ListNode *slow=head,*fast=head,*p,*q,*temp ,*a=head ;
      while(fast && fast->next)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
       // Split the list into two halves.
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // Reverse the second half of the list.
        secondHalf = rev(secondHalf);

        // Merge the two halves to reorder the list.
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        while (p2) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
        p2 = temp2;
    }}
};