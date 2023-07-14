//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
  
   long long f(int n,vector<int> arr,long long r) {
        // code here
        int i=0;
        int j=0;
        long long sum=0;
        long long ans=0;
        while(j<n)
        {
            sum+=arr[j];
            while(sum>r)
            {
                sum-=arr[i];
                i++;
            }
            ans+=j-i+1;
            j++;
            
        }
        return ans;
        
        
    }
    
    long long countSubarray(int n,vector<int> arr,long long l,long long r) {
        // code here
        return f(n,arr,r)-f(n,arr,l-1);
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends