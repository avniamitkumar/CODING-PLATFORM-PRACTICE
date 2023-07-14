//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
     bool isPossible(vector<int>&nums, int mid, int target){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += ceil( (double)nums[i]/(double)mid );
            if(sum > target){
                return false;
            }
        }
        return true;
    }


  
  
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Write your code here.
         // finding the start point and end point for nums
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(nums, mid, threshold)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends