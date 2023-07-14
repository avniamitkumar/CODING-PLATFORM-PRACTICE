//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:

    void computeLPS(string s,vector<int>&lps)
    {
        int n=s.size();
        int len=0;
        int i=1;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                lps[i++]=++len;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else i++;
                
            }
        }
    }

    int findLastOccurence(string txt,string pat){
        //Code Here
        int M=pat.size();
        int N=txt.size();
        
        vector<int>lps(M,0);
        int ans=-1;
        computeLPS(pat,lps);
        int i=0,j=0;
        while((N-i) >=(M-j))
        {
            if(pat[j]==txt[i])
            {
                j++;
                i++;
            }
            if(j==M)
            {
                ans=i-j+1;
                j=lps[M-1];
                
            }
            else if(i<N && pat[j] !=txt[i])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else i++;
            }
        }
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
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends