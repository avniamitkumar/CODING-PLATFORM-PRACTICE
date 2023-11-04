class Solution {
public:
    int fun(vector<int>& arr, int target)
    {
        if(target<0)return 0;
         int i=0;
        int j=0;
        int n=arr.size();
        int sum=0;
        int cnt=0;
        while(j<n)
        {
            sum+=arr[j];
            while(sum>target)
            {
                sum-=arr[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& arr, int target) {
       return fun(arr,target)-fun(arr,target-1);
    }
};