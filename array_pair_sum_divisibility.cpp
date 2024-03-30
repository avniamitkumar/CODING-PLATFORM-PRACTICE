//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n%2)return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]%k;
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==0)continue;
            else{
                 int temp = (k-nums[i])%k ;
                 if(mp.count(temp)){
                     if(mp[nums[i]]==mp[temp])
                     {
                         mp[nums[i]]=0;
                         mp[temp]=0;
                     }
                     else
                     {
                         return 0;
                     }
                 }else{
                     return 0;
                 }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends