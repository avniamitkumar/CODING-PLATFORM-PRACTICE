//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int n, int k) {
        // code here
       int p=n-k;
       int i=0;
       int j=0;
       int sum=0;
       int mn=INT_MAX;
       for(int j=0;j<n;j++)
       {
           sum+=arr[j];
           while(j-i+1==n-k)
           {
               mn=min(mn,sum);
               sum-=arr[i];
               i++;
           }
       }
       int l=0;
       for(int i=0;i<n;i++)
       {
           l+=arr[i];
       }
              if(n==k)return l;

       return l-mn;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends