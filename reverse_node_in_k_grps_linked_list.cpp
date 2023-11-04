class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int x = k;
        ListNode* p = head;
        while(x>0&&p){
            p = p->next;
            x--;
        }
        if(x==0){
            ListNode* pre = NULL,*next = NULL,*curr = head;
            while(curr != p){
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            head->next = reverseKGroup(p,k);
            return head = pre;
        }else{
            return head;
        }
    }
};