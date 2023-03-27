//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int l=0;
        int r=0;
        int mx=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if(l==r)
            {
                mx=max(mx,2*r);
            }
            else if(r>l)
            {
                r=0;
                l=0;
            }
            
        }
        l=0;
        r=0;
       // reverse(s.begin(),s.end());
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if(l==r)
            {
                mx=max(mx,2*l);
            }
            else if(l>r)
            {
                r=0;
                l=0;
            }
            
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends