//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        int i=2;
        int cnt=0;
        while(n!=1)
        {
            if(n%i!=0)
            {
                i++;
            }
            else
            {
                n=n/i;
                cnt=max(cnt,i);
            }
        }
        return cnt;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends