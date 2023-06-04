//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string one="";
           stack<string>st;
           for(int i=0;i<s.size();i++)
           {
               
               if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
               {
                   st.push(one);
                   one="";
                   string t="";
                   t+=s[i];
                   st.push(t);
               }
               else
               {
                   one+=s[i];
               }
           }
           st.push(one);
           string ans;
           while(!st.empty())
           {
               ans+=st.top();
               st.pop();
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
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends