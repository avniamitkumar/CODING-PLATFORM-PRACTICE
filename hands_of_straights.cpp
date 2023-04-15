//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &arr) {
        // code here
        if(n%k!=0) return 0;
        sort(arr.begin(),arr.end());
       map<int,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[arr[i]]++;
       }
       for(auto it:mp)
       {
           int t=it.first;
           int m=t;
           for(int i=1;i<k;i++)
           {
               m++;
               if(mp[m]>0)
               {
                   mp[m]--;
                   if(mp[m]==0)
                   {
                       mp.erase(m);
                   }
               }
               else
                   {
                       return false;
                   }
           }
           mp[t]--;
           if(mp[t]==0){
               mp.erase(t);
           }
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends