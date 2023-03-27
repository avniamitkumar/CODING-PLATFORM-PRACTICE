//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(s[j]!='\0')
        {
            mp[s[j]]++;
            while(mp['a']>=1 &&mp['b']>=1 && mp['c']>=1 && i<=j){
               mp[s[i]]--;
               cnt+=n-j;
               i++;}
               j++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends