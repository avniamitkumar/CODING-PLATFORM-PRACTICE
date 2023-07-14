//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int n,vector<int>&arr,int h,int given)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<given)
            {
                cnt+=1;
            }else{
            cnt+=ceil(1.0*arr[i]/given);
        }}
        if(cnt<=h)return true;
        return false;
    }
  
  
    int Solve(int n, vector<int>& arr, int h) {
        // Code here
        sort(arr.begin(),arr.end());
        int high=arr[n-1];
        int low=1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(n,arr,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends