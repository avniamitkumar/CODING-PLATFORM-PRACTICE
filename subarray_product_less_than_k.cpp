class Solution {
public:
    int solve(vector<int>& arr, int k){
        int n=arr.size();
        int i=0;
        int j=0;
        int ans=0;
        int p=1;
        if(k <= 1) return 0;
        while(j<n)
        {
            p*=arr[j];
            while(p>=k)
            {
               
                p/=arr[i];
                 i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
       return solve(arr,k);


    }
};