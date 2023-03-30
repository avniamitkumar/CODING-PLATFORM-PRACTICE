//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& arr, int k) {
        // Code here
        int i=0;
        int j=0;
        int ans=INT_MIN;
        int c=0;
        while(j<n)
        {
           if(arr[j]==1)
           {
               ans=max(ans,j-i+1);
           }
           else if(arr[j]==0)
           {
               if(k>0)
               {
                   k--;
                  ans=max(ans,j-i+1);
               }else if(k==0)
               {
                   while(k==0)
                   {
                       if(arr[i]==0)
                       {
                           k++;
                       }
                       i++;
                   }
                 //  k--;
                    k--;              
                    ans=max(ans,j-i+1);
               }
           }
           j++;
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends