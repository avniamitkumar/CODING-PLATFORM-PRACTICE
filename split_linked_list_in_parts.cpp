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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode *p=head;
        while(p)
        {
            len++;
            p=p->next;
        }
        int parts=len/k;
        int ex_parts=len%k;
        vector<ListNode*>ans(k,NULL);
        ListNode*q,*r=NULL;
        q=head;
        for(int i=0;q && i<k;i++,ex_parts--)
        {
            ans[i]=q;
            for(int j=0;j< parts+(ex_parts>0);j++)
            {
                r=q;
                q=q->next;
                
            }
            r->next=NULL;
        }
        return ans;

    }
};