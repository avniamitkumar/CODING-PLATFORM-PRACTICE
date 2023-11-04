/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
        {
            return NULL;
        }
        Node *t=flatten(head->child);
        Node *p=flatten(head->next);
      
       auto node=head;
        if(t)
        {
            node->next=t;
            t->prev=node;
            while(node->next){node=node->next;}
        }
        if(p)
        {
            node->next=p;
            p->prev=node;
        }
        head->child=NULL;
        return head;


    }
};