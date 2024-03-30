//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define lli long long int
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        lli maxsum[n];
        lli csum=0;
        for(int i=0;i<n;i++)
        {
            if(csum>0)
            {
                csum+=a[i];
            }
            else{
                csum=a[i];
            }
            maxsum[i]=csum;
        }
        
           lli sum = 0;
         for (int i = 0; i < k; i++)sum += a[i];
        lli ans=INT_MIN;
        ans=max(sum,ans);
       // lli sum=0;
        for(int i=k;i<n;i++)
        {
            sum+=a[i]-a[i-k];
            ans=max(ans,sum);
            ans=max(ans,sum+maxsum[i-k]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends