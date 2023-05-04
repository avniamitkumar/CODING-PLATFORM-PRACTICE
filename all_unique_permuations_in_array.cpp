//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(vector<int>&arr,int ind,int n,vector<vector<int>> &ans)
  {
      if(ind==n)
      {
          ans.push_back(arr);
          return;
      }
      for(int i=ind;i<n;i++)
      {
          swap(arr[ind],arr[i]);
        // ds.push_back(arr[i]);
          solve(arr,ind+1,n,ans);
         //ds.pop_back();
          swap(arr[ind],arr[i]);
      }
      
  }
  
  
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        
        vector<vector<int>> ans;
        vector<int> ds;
       // vector<bool> flag(n,false);
        sort(arr.begin(),arr.end());
        solve(arr,0,n,ans);
        set<vector<int>> st;
        for(auto it:ans){
            st.insert(it);
        }
        ans.clear();
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends