//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
         if(s.size()!=t.size())
{
         return 0;
}        
         unordered_map<char,char> mp1,mp2;
        for(int i=0;i<s.length();i++){
            char pp = s[i];
            mp1[pp] = t[i];
            mp2[t[i]] = s[i];
        } 
        for(int i=0;i<s.size();i++){
            char pp = s[i];
            if(mp1[s[i]]!=t[i])
              return false;
            if(mp2[t[i]]!=s[i])
              return false;
        }

        

        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends