//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        //ODD PART
        int start=0;
        int end=0;
        int n=S.size();
        int len=0;
        for(int i=1;i<n;i++)
        {
            int s=i-1;
            int e=i+1;
            while(s>=0 && e<n && S[s]==S[e])
            {
                if(e-s+1>len)
                {
                    len=e-s+1;
                    start=s;
                    end=e;
                }
                s--;
                e++;
            }
        
        s=i-1;
        e=i;
            
             while(s>=0 && e<n && S[s]==S[e])
            {
                if(e-s+1>len)
                {
                    len=e-s+1;
                    start=s;
                    end=e;
                }
                s--;
                e++;
            }
        
        }
                string ans="";
        for(int i=start;i<=end;i++){
            ans+=S[i];}
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends