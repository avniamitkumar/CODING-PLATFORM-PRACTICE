//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//n/2+1
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
       //find mid
       Node*mid=head,*fast=head;
       while(fast && fast->next)
       {
           mid=mid->next;
           fast=fast->next->next;
       }
       //reverse from mid
       Node *prev=NULL;
       Node*curr=mid;
       Node* next;
       while(curr)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       Node *l=head,*r=prev;
       while(r)
       {
           if(r->data!=l->data)
           {
               return false;
           }
           r=r->next;
           l=l->next;
       }
       return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends