//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	 bool check(string &s,int i,int j)
	 {
	     if(i>j)return true;
	     if(s[i]!=s[j])return false;
	     return check(s,i+1,j-1);
	 }
	 
	
	int isPalindrome(string s)
	{
	    // Your code goes here
	    bool ck;
	    ck=check(s,0,s.length()-1);
	    if(ck==true){
	        return 1;
	    }
	    return 0;
	    
	    
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends