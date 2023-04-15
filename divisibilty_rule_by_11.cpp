//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int len=x.size();
       int sume=0;
       int sumo=0;
       for(int i=0;i<len;i++)
       {
            int digit=(x[i]-'0');
            if(i%2==0)
            {
                sumo+=digit;
            }
            else
            {
                sume+=digit;
            }
       }
        long long diff = (sumo - sume) % 11;
       if(x.length() % 2 == 0)
          return abs(diff - 11) % 11;
   
       return diff;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends