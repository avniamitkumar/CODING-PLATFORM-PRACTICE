//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> prime(int n)
    {
        vector<int>p(n+1,1);
        for(int i=2;i<=n;i++)
        {
            if(p[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    p[i]=0;
                }
            }
        }
        vector<int>my;
        for(int i=2;i<=n;i++)
        {
            if(p[i])
            {
                my.push_back(i);
            }
        }
        return my;
    }

vector<int> SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 vector<int>my;
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            {
                my.push_back(p);
            }
             return my;
}

    vector<int> primeDivision(int N){
        // code here
        vector<int>ss=SieveOfEratosthenes(10000);
        vector<int>as;
        for(int i=0;i<ss.size();i++)
        {   std::vector<int>::iterator it;
            it = std::find (ss.begin(), ss.end(), N-ss[i]);
            if(it != ss.end())
            {
                as.push_back(ss[i]);
                as.push_back(N-ss[i]);
            }
            
        }
        
        return as;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends