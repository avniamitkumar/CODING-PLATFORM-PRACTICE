//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool compare(string &s,string &t)
    {
        if(abs(s.size()-t.size())!=1)return false;
        
        int i=0;
        int j=0;
        while(i <s.size())
        {   
            if(s[i]==t[j]){i++;j++;}
            else
            {
                i++;
            }
            
        }
        if(i==s.size() && j==t.size())return true;
        return false;
        
        
    }
    static bool comp(string &a, string &b) { return a.size() < b.size(); }
  
  
    int longestChain(int n, vector<string>&a) {
        // Code here
        sort(a.begin(), a.end(), comp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(a[i],a[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends