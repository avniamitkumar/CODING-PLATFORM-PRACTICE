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
    ListNode* mergeTwoLists(ListNode* i, ListNode* j) {
        if(i==NULL)
            return j;
        if(j==NULL)
            return i;
        // if(!list1 && !list2)return NULL;
        // if(list1 && !list2)return list1;
        // if(list2 && !list1)return list2;
        ListNode*ans=new ListNode(-1);
        ListNode*k=ans;
        // ListNode*i=list1;
        // ListNode*j=list2;
        while(i&&j)
        {
            if(i->val <= j->val)
            {

                 k->next=i;
               k=i;
               i=i->next;
                
            }else
            {
             k->next=j;
                k=j;
                j=j->next; 
            }
          
        }
        if(i)
        {
            k->next=i;
            //i=i->next;
        }
        if(j)
        {
            k->next=j;
          //  j=j->next;
        }
        return ans->next;

    }
};