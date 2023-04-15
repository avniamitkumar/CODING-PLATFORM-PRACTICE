//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i <n; i++) {
            while (!st.empty() && cnt < k && st.top() > s[i]) {
                st.pop();
                cnt++;
            }
            st.push(s[i]);
        }
        while (!st.empty() && cnt < k) {
            st.pop();
            cnt++;
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        while (!ans.empty() && ans[0] == '0') {
            ans.erase(0, 1);
        }
        if (ans.empty()) {
            ans = "0";
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends