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
    
    string preToPost(string s) {
        reverse(s.begin(),s.end());
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
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                st.push(a+b+s[i]);
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends