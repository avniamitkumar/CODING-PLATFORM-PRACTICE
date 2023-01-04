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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        stack <ListNode*> st1,st2;
        ListNode *t1=head1,*t2=head2;
        while(t1)
        {
            st1.push(t1);
            t1=t1->next;
        }
        while(t2)
        {
            st2.push(t2);
            t2=t2->next;
        }
        //ListNode*a,*b;
        /*while(!st1.empty() && !st2.empty())
        {
            if(st1.top()==st2.top())
            {
                return st2.top();
            }
            st1.pop();
            st2.pop();
        }
        return NULL;*/
        ListNode* prev = NULL;
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top()){
            prev = st1.top();
            st1.pop();
            st2.pop();
        }
        return prev;
    }
};