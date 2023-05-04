//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

   class Solution{
public:
    vector<vector<int>> res;
    void solve(int idx, vector<int> &candidates, int target, int n, vector<int> &curr) {
        
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(idx == n) {
            return;
        }
        if(target<0) return;
        
        int i = idx+1;
        while(i<n && candidates[i]==candidates[idx]) i++;
        if(candidates[idx]<=target) {// le sakte hain
            curr.push_back(candidates[idx]);
            solve(idx+1, candidates, target-candidates[idx], n, curr);
            curr.pop_back();
        }
        solve(i, candidates, target, n, curr);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> curr;
        solve(0, arr, k, n, curr);
        return res;
    }

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends