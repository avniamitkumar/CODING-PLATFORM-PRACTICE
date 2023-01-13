//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

 void solve(int sum,int itr,vector<int>arr,vector<int>&m,int n)
 {
     if(itr==n)
     {
        m.push_back(sum);
        return;
     }
     solve(sum+arr[itr],itr+1,arr,m,n);
     solve(sum,itr+1,arr,m,n);
 }


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        solve(0,0,arr,ans,N);
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends