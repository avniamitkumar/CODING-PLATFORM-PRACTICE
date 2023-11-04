//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

int lll(Node* l){
    if(l==nullptr)return 0;
    int count =0;
    while(l){
        count++;
        l = l->next;
    }
    return count;
}


// to reverse the linked list

Node* rev(Node* head){
    Node* curr = head ,* pre = NULL,*next;
    while(curr){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr=next;
    }
    return pre;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    Node*t1,*t2;
    t1=l1;t2=l2;
    
    // to remove initial zeros (if any) present in both ll
    while(t1){
        if(t1->data!=0){
            l1 = t1;
            break;
        }
        t1 = t1->next;
    }
    // if the whole ll is zero;
    if(t1==NULL){
        Node* no = new Node(0);
        l1 =no;
    }
    while(t2){
        if(t2->data!=0){
            l2 = t2;
            break;
        }
        t2 = t2->next;
    }
    if(t2==NULL){
        Node* no = new Node(0);
        l2 =no;
    }
    
    
    // to get the lengt of ll
    int len1 = lll(l1);
    int len2 = lll(l2);

 

// deciding the ll with larger number and smaller number
    Node* g,*s;
    if(len1>len2){
        g = l1;
        s = l2;
    }
    else if(len1<len2){
        g = l2;
        s = l1;
    }
    else if(len1==len2){
        
        // if both have same length then see for first non matching number
        
        t1=l1;t2=l2;
        while(t1 && t2){
            if(t1->data>t2->data){
                g = l1;
                s = l2;
                break;
            }
            else if(t1->data==t2->data){
                g = l1;
                s = l2;
            }
            else{
                g = l2;
                s = l1;
                break;
            }
            t1=t1->next;t2 = t2->next;
        }
    }
    
    // reverse both the ll
    
    g = rev(g);
    s = rev(s);
    
    int borr=0;
    
    // initialising the ans ll;
    
    Node* dum = new Node(-1);
    Node* temp = dum;
    
    // computing the difference 
    
    
    while(g && s ){
        // adding borrow ( if any ) 
        int d1 = g->data + borr;
        int d2 = s->data;
        if(d1>=d2){
            Node* nn = new Node(d1-d2);
            temp->next = nn;
            // no need to take borrow
            borr=0;
        }
        else{
            // handling the case of borrow
            
            Node* nn = new Node(d1+10-d2);
            temp->next = nn;
            borr=-1;
        }
        temp = temp->next;
        g=g->next;s=s->next;
    }
    
    // handling the case when g ll is having remaining element
    
    while(g){
        int d1 = g->data+borr;
        if(d1>=0){
            Node* nn = new Node(d1);
            temp->next = nn;
            borr=0;
        }
        else{
            Node* nn = new Node(d1+10);
            temp->next = nn;
            borr=-1;
        }
        temp = temp->next;
        g=g->next;
        
    }
    temp->next = nullptr;
    temp=dum->next;
    delete dum;
    
    
    // reversing the answer string ...
    // ll can also be like 1->2->3->2->0
    
    temp = rev(temp);
    Node* ran = temp;
    
    
    // ll can also be like 0->2->3->2->1
    // handling case of leading zeros
    
    while(ran){
        if(ran->data!=0){
            temp = ran;
            break;
        }
        ran = ran->next;
    }
    
    
    // if whole ll is zero
    if(ran==NULL){
        Node* no = new Node(0);
        temp =no;
    }
    return temp;
    
}

 