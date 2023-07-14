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
    ListNode *rev(ListNode*head)
    {
        ListNode *prev=NULL;
        ListNode*curr=head;
        while(curr)
        {
            ListNode* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }


    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<ListNode*>st;
        ListNode* hhead=rev(head);
        ListNode*i=hhead;
        while(i)
        {
            while(!st.empty() && st.top()->val<=i->val)
            {
                st.pop();
            }
            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top()->val);
            }
            st.push(i);
            i=i->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};