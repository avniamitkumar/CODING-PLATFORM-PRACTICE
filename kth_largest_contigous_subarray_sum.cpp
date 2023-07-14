//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        int i=0;
        int j=0;
        int curr=0;
        priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<n;i++)
       {
           curr=0;
           for(int j=i;j<n;j++)
           {
               curr+=arr[j];
               pq.push(curr);
               while(pq.size()>k)
               {
                   pq.pop();
               }
           }
       }
       return pq.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends