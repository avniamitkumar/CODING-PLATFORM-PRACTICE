//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isoperator(char s)
    {
        if(s=='+'|| s=='-' || s=='*' || s=='/')
        {
            return true;
        }
        return false;
    }
    string preToInfix(string s) {
        // Write your code here
        int i=0;
        reverse(s.begin(),s.end());
        stack<string>st;
        string op="";
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(!isoperator(s[i]))
            {
                string ip="";
                ip+=s[i];
                st.push(ip);
                
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
               // op='('+a+s[i]+b+')';
                st.push('('+a+s[i]+b+')');
               
            }
            
        }
        while(!st.empty())
        {
         ans+=st.top();
         st.pop();
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends