//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   \
#define ll long long
 
ll rec(int i, int currPos, vector<int> &types, unordered_map<int, int> &lefmost, unordered_map<int, int> &rightmost, vector<vector<ll>> &dp, int dirIndi)
{
    // base case
    if (i == types.size())
    {
        return 0;
    }
 
    if (dp[i][dirIndi] != -1)
    {
        return dp[i][dirIndi];
    }
 
    // Case 1 : when we first move left then right to collect the current types of fruits
    ll lr = abs(currPos - lefmost[types[i]]) + abs(lefmost[types[i]] - rightmost[types[i]]) + rec(i + 1, rightmost[types[i]], types, lefmost, rightmost, dp, 1);
 
    // Edges case : when we collect all types of fruits then we have to return again to 0 where we start intially
    if (i == types.size() - 1)
    {
        lr += abs(rightmost[types[i]] - 0);
    }
 
    // Case 2 : when we first move right then left to collect the current types of fruits
    ll rl = abs(currPos - rightmost[types[i]]) + abs(rightmost[types[i]] - lefmost[types[i]]) + rec(i + 1, lefmost[types[i]], types, lefmost, rightmost, dp, 0);
 
    if (i == types.size() - 1)
    {
        rl += abs(lefmost[types[i]] - 0);
    }
 
    // induction step
    return dp[i][dirIndi] = min(lr, rl);
}
 
long long minTime(int n, vector<int> &l, vector<int> &t)
{
    int mxT = *max_element(t.begin(), t.end());
    vector<int> typePre(mxT + 1, 0);
 
    // In order to collect all types of fruit in min time then we need to rightmost and leftmost positions of every types of fruits
    unordered_map<int, int> lefmost, rightmost;
    for (int i = 0; i < n; i++)
    {
        typePre[t[i]] = 1;
        if (!lefmost.count(t[i]))
        {
            lefmost[t[i]] = l[i];
            rightmost[t[i]] = l[i];
        }
        else
        {
            lefmost[t[i]] = min(lefmost[t[i]], l[i]);
            rightmost[t[i]] = max(rightmost[t[i]], l[i]);
        }
    }
 
    vector<int> types;
    for (int i = 0; i <= typePre.size(); i++)
    {
        if (typePre[i] == 1)
        {
            types.push_back(i);
        }
    }
 
    vector<vector<ll>> dp(types.size(), vector<ll>(2, -1));
    // rec(curr index, curr pos,leftmost,rightmost,dp array,direction indicator 0 represent left, 1 represent right)
    return rec(0, 0, types, lefmost, rightmost, dp, 0);
}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends