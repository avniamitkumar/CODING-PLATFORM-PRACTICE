//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
  
  
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
         sort(arr.begin(), arr.end());
         vector<int> hash(n,1);
         int ans=1;
        vector<int>dp(n,1);
                int lstind=0;

        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if((arr[i]%arr[prev]==0) && dp[prev]+1>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                lstind=i;
            }
        }
        vector<int> s;
        s.push_back(arr[lstind]);
        
        while(hash[lstind]!=lstind)
        {
            lstind=hash[lstind];
            s.push_back(arr[lstind]);
        }
        
        reverse(s.begin(),s.end());
        
        return s;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends