//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies,candies+n);
        vector<int>a;
        int j=n-1;
        int min=0;
        int i=0;
        while(i<=j)
        {
            min+=candies[i];
            j=j-k;
            i++;
        }
        a.push_back(min);
        int max=0;
        j=n-1;
        i=0;
        while(j>=i)
        {
         max+=candies[j];
            i=i+k;
            j--;   
        }
        a.push_back(max);
        return a;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends