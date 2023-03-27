//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int mn=INT_MAX;
        while(s[j]!='\0')
        {
            mp[s[j]]++;
            if(mp.size()==3){
                while(mp[s[i]]>1){
                    mp[s[i]]--;
                    i++;
                }
                 mn=min(mn,j-i+1);
               }
            j++;
        }
        
        return mn==INT_MAX?-1:mn;;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends