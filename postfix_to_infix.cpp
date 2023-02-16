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
    string postToInfix(string s) {
        // Write your code here
        int i=0;
        stack<string>st;
      
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(!isoperator(s[i]))
            {
                string ip="";
                ip+=s[i];
                st.push(ip);
               // i++;
            }
            else
            {
                string b=st.top();
                st.pop();
                string a=st.top();
                st.pop();
                 // string op='('+a+s[i]+b+')';
                st.push('('+a+s[i]+b+')');
               // i++;
            }
            
        }
       
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends