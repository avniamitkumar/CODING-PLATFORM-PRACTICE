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
    ListNode *rev(ListNode* head)
    {
        ListNode*prev=NULL;
        ListNode *curr=head;
        while(curr)
        {
            ListNode* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    //  ListNode* rev(ListNode* head) {
    //     ListNode*prevptr=NULL;
    //     ListNode*currptr=head;
    //     ListNode*nextptr;

    //     while (currptr!=NULL)
    //     {
    //         nextptr=currptr->next;
    //         currptr->next=prevptr;

    //         prevptr=currptr;
    //         currptr=nextptr;
    //     }
    //     return prevptr;
    // }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * a=rev(l1);
        ListNode *b=rev(l2);
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode*curr=ans;
        while(a || b)
        {
            int sum=0;
            if(a){sum+=a->val;
            }
            if(b){sum+=b->val;}
            sum+=carry;
            //ListNode *temp=new ListNode(sum%10);
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            //curr->next=temp;
            curr=curr->next;
             if(a)a=a->next;
            if(b)b=b->next;
        }
       if(carry>0)
       {
           curr->next=new ListNode (carry);
           //curr=curr->next;
       }
        //curr=rev(ans->next);
        return rev(ans->next);
    }
};