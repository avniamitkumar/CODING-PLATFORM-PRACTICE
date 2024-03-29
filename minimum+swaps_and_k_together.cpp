//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]<=k)
           {cnt++;}
       }
        
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int keep=0;
        int prev=0;
        while(j<n)
        {
            if(j-i+1>cnt){
             while(j-i+1>cnt)
                {
                    if(arr[i]>k)
                    {
                        keep--;
                    }
                    i++;
                }
            }
            if(arr[j]>k)
            {
                keep++;
            }
            if(j-i+1==cnt)
            {
                if(keep<ans)
                {
                    ans=keep;
                }
            }
           
            j++;
            
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends