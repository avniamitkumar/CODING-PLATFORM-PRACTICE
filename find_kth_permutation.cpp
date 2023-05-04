//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // string s="";
        vector<int>s;
        for(int i=1;i<=n;i++){
            // s+=i;
            s.push_back(i);
        }
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact*i;
        }
        string str="";
        k=k-1;
        while(true){
            str=str+to_string(s[k/fact]);
            s.erase(s.begin()+k/fact);
            if(s.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/s.size();
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends