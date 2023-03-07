//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isv(char c)
    {
        if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u')
        {
            return 1;
        }
        return 0;
    }
    int isGoodorBad(string str) {
        // code here
        int vow_cnt=0;
        int con_cnt=0;
        int i=0;
        for(int i=0; i<str.size(); i++){
            char c=str[i];
            if(c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u')
            {
                vow_cnt+=1;
                con_cnt=0;
            }
            else if(str[i]=='?')
            {
                con_cnt+=1;
                vow_cnt+=1;
            }
            else 
            {
                con_cnt+=1;
                vow_cnt=0;
            }
            
            if(con_cnt==4 || vow_cnt==6)
            {
                return 0;
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends