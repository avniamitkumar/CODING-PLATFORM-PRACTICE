//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
int mod=1e9+7;
class Solution{   
public:
    long long subarraySum(long long arr[], long long n)
    {
        // Your code goes here
        // int sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         for(int k=i;k<=j;k++)
        //         {
        //             sum+=a[k];
        //         }
        //     }
        // }
        // return sum;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=(sum+(n-i)*(i+1)*arr[i])%mod;
        }
        return sum%mod;
    }
};

//{ Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}

// } Driver Code Ends