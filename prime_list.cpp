//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/
vector<int>sieve(int n)
{
    vector<int>prime(n+1,1);
    for(int i=2;i<n;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<n;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    vector<int>list;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            list.push_back(p);
    return list;
}
int binary_search(vector<int> &prime, int x){
        int lo = -1, hi = prime.size();
        while(hi-lo>1){
            int mid = (hi+lo)>>1;
            if(prime[mid]<x){
                lo = mid;
            }
            else hi =mid;
        }
        if(lo == -1){
            return prime[hi];
        }
        else if(hi == prime.size()){
            return prime[lo];
        }
        if(abs(x-prime[lo])<=abs(x-prime[hi])){
            return prime[lo];
        }
        return prime[hi];
    }
class Solution{
public:
    Node *primeList(Node *head){
        Node* p=head,*q;
        vector<int>list=sieve(1e4+7);
        while(p)
        {
            
            p->val=binary_search(list,p->val);
            p=p->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends