//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool isoperator(char r)
    {
        if(r=='/' || r=='+' || r=='-' || r=='*')
        {
            return true;
        }
        return false;
    }
  
  
  
    string postToPre(string s) {
        // Write your code here
         //reverse(s.begin(),s.end());
        stack<string>st;
        for(int i=0;i<s.length();i++)
        {
            if(!isoperator(s[i]))
            {
                string ip="";
                ip+=s[i];
                st.push(ip);
            }else
            {
                string b=st.top();
                st.pop();
                string a=st.top();
                st.pop();
                st.push(s[i]+a+b);
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends