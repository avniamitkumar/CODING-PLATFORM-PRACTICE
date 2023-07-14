//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findlps(string s){
        int n = s.length();
        
        int i = 1;
        int j = 0;
        vector<int> lps(n);
        while(i<n){
            if(s[i] == s[j]){
                lps[i] =  j+1;
                i++;
                j++;
            }
            else{
                if(j>0){
                    j = lps[j-1];
                }
                else if(j == 0){
                    i++;
                }
            }
        }
        
        return lps[n-1];
        
        
    }
    int minChar(string str){
        //Write your code here
        int n = str.size();
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        str += '$';
        str+= rev;
        
        int lps = findlps(str);
        
        int ans = n - lps;
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends