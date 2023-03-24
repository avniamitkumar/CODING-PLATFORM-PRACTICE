//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int n, int target){
      // int n = arr.size();
    int count = 0, sum = 0, left = 0, right = 0;
    
    while(right < n){
        sum += arr[right];
        while(left < right && sum > target){
            sum -= arr[left];
            left++;
        }
        if(sum == target){
            count++;
        }
        for (int i = left; sum == target && i < right && arr[i] == 0; i++)
                count++;
        right++;
    }
    
    return count;
        
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
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends