//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int atm(int n,vector<int>&nums,int k)
  {
      int i=0;
        int j=0;
        int cnt=0;
        int at=0;
        while(j<n)
        {
            if(nums[j]%2!=0)
            {
                at++;
            }
            while(at>k)
            {
                if(nums[i]%2!=0)
                {
                    at--;
                }
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
  }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        //unordered_map<int,int>mp;
         int answer;

        answer=atm(n,nums,k)-atm(n,nums,k-1);

        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends