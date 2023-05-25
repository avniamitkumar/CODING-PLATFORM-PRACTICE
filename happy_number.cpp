//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int n){
        // code here
         int sum=0;
        while(n>0)
        {
            int r=n%10;
            sum+=(r*r);
            n=n/10;
        }
        
        if(sum==1)
            return 1;
        if(sum<10)
            return 0;
        return isHappy(sum);
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
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends