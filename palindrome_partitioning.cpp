//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  void solve(int index,string s, vector<string>&path,vector<vector<string>>&ans){
      if(index>=s.size()){
          ans.push_back(path);
          return;
      }
        
    for(int i=index;i<s.size();i++){
        if(isPalind(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            solve(i+1,s,path,ans);
            //backtrack
            path.pop_back();
        }
    }
  }
  bool isPalind(string s,int start,int end){
      while(start<=end){
          if(s[start++]!=s[end--]){
              return false;
          }
      }
      return true;
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,S,path,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends