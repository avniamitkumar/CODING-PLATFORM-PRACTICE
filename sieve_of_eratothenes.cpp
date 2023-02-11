//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int>my;
        vector<int>isprime(n+1,1);
        for(int i=2;i*i<=n;i++)
        {
            if(isprime[i]==1){
            for(int j=i*i;j<=n;j+=i)
            {
                    isprime[j]=0;
            }}
        }
        for (int i = 2; i <= n; i++)
        {if (isprime[i]==1)
        {
            my.push_back(i);
        }
        }
        
        return my;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends