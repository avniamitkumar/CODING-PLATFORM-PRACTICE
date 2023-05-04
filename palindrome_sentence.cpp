//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	


	bool sentencePalindrome(string s) 
	{
	    // code here
	    int i=0,j=s.size()-1;

    while(i<=j){

        if(!(s[i]>= 'a' && s[i]<='z'))

             i++;

         else if(!(s[j]>= 'a' && s[j]<='z'))

             j--;

        else if(s[i]!=s[j])

             return false;

        else{

            i++;

            j--;

        }

    }

    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends