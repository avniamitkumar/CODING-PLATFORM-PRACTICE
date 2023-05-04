//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int arr[], int n, int L, int R)
    {
        // Complete the function
        int i=0;
        int j=0;
        int win=0;
        long cnt=0;
        while(j<n)
        {
            if(arr[j]>R)
            {
                win=0;
                i=j+1;
                
            }
            else if(arr[j]>=L && arr[j]<=R)
            {
                win=j-i+1;
            }
           
          cnt+=win;
           j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends