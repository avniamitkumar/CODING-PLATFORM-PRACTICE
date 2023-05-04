//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int n=str.size();
        int i=0;
        int j=0;
        int ans=INT_MAX;
        unordered_map<char,int>mp;
        unordered_map<char,int>m;
        for(int i=0;i<str.size();i++)
        {
            mp[str[i]]++;
        }
        int ind=mp.size();
        while(j<n)
        {
            m[str[j]]++;
            if(m.size()==ind)
            {
                while(m[str[i]]>1)
                {
                    m[str[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
            }
            j++;
            
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends