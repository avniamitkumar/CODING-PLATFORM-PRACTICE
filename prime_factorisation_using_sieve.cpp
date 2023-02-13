//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int n=100100;
  vector<int>spf(n+1);
class Solution {
  public:
  
    void sieve() {
        //vector<int>spf(n+1);
        for(int i=1;i<=n;i++)
        {
            spf[i]=i;   
        }
        for(int i=2;i*i<=n;i++)
        {
            if(spf[i]==i){
            for(int j=i*i;j<n;j+=i)
                {
                    if(spf[j]==j){
                    spf[j]=i;}
                }
            }
        }
      
        
    }

    vector<int> findPrimeFactors(int N) {
        vector<int>my;
        sieve( );
        while(N>1)
        {
            my.push_back(spf[N]);
            N=N/spf[N];
        }
        sort(my.begin(),my.end());
        return my;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends