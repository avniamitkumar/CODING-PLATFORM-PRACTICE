//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int xo=arr[0];
        for(int i=1;i<n;i++)
        {
            xo=xo^arr[i];
        }
        int xor_bit=xo & ~(xo-1);
         long long  int a = 0;

        long long int b = 0;

        for(long long int j=0; j<n; j++){

            if(arr[j]&xor_bit){

                a^=arr[j];

            }else{

                b^=arr[j];

            }

        }

        

        return {max(a,b), min(a,b)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends