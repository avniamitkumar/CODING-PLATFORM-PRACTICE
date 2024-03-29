//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
       string ans = "";
        string s;
        int len = INT_MAX;
       for(int i=0;i<N;i++)
       {
           if(arr[i].length() < len)
           {
               s = arr[i];
               len = arr[i].length();
           }
       }
       int k=0;
       int flag=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<N;j++)
            {
                if(arr[j][i]!=s[k])
                {
                 if(i==0)
                 {
                     return "-1";
                 }
                 else
                 {
                     flag=1;
                     break;
                 }
                }
            }
            if(flag ==1)break;
           ans+=s[k++];
        }
          return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends