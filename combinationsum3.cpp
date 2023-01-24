//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void solve(vector<int>&ds,vector<vector<int>>&ans,int sum,int k,int i)
  {
      
      if(sum==0 && k==0){
       if(sum==0){
          ans.push_back(ds);
          return ;
      }}
      if(i>9)
      {
          return;
      }
      
          ds.push_back(i);
          //solve(ds,ans,sum-i,k-1,i);
          solve(ds,ans,sum-i,k-1,i+1);
          ds.pop_back();
          solve(ds,ans,sum,k,i+1);
      
  }
  
  
  
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
       vector<int>ds;
       vector<vector<int>>ans;
       solve(ds,ans,n,k,1);
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends