//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        stack<string>st;
        int i=0;
        string word="";
        while(s[i]!='\0')
        {
            
            if(s[i]=='.')
            {
                 st.push(word);
                 word = "";
            }
            else
            {
                word+=s[i];
            }
            i++;
        }
    st.push(word);
       // for(int i=0;i<s.length();i++)
        
       string reversed_string = "";
    while (!st.empty()) {
        reversed_string += st.top();
        st.pop();
        if (!st.empty()) {
            reversed_string += ".";
        }
    }
    
    return reversed_string;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends