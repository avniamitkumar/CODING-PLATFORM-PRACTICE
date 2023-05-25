//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

  
   class Solution {
public:
    void helper(int index, const string& path, long resSoFar, long prev, string& s, int target, vector<string>& res){
        if(index == s.size()){
            if(resSoFar == target)
                res.push_back(path);
            return;
        }
        string numStr;
        long num = 0;
        for(int i=index;i<s.size();i++){
            if(i>index && s[index]=='0') break;
            numStr += s[i];
            num = num * 10 + s[i] - '0';
            if(index == 0)
                helper(i+1, path+numStr, num, num, s, target, res);
            else{
                helper(i+1, path+"+"+numStr, resSoFar+num, num, s, target, res);
                helper(i+1, path+"-"+numStr, resSoFar-num, -num, s, target, res);
                helper(i+1, path+"*"+numStr, resSoFar-prev+prev*num, prev*num, s, target, res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.size()==0 || target<=INT_MIN || target>INT_MAX) return res;
        helper(0,"",0,0,num,target,res);
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends