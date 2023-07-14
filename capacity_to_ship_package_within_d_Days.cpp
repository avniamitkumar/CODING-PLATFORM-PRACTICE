//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     bool isPossible(int weights[],int n,int capacity,int days){
        int currWeight=0,NoOfDaysRequired=1;
        for(int i=0;i<n;i++){
            if(currWeight+weights[i]<=capacity){
                currWeight+=weights[i];
            }
            else if(weights[i]<=capacity){
                NoOfDaysRequired++;
                currWeight=weights[i];
            }
            else{
                return false;
            }
        }
        return NoOfDaysRequired<=days;
    }
  
    int leastWeightCapacity(int weights[], int n, int days) {
        // code here
        
        //  int sum=accumulate(weights.begin(),weights.end(),0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
        }
        int s=0,e=sum;
        int minimumNoOfDays=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(weights,n,mid,days)){
                minimumNoOfDays=min(minimumNoOfDays,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return minimumNoOfDays;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends