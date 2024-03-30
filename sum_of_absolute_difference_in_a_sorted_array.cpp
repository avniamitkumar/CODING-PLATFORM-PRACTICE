class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        vector<int>arr(n,0);
        int lsum=0;
        for(int i=0;i<n;i++)
        {
            lsum+=nums[i];
            arr[i]=((i)*nums[i])-lsum;
            arr[i]+=abs(sum-lsum-((n-i-1)*nums[i]));
            arr[i]+=nums[i];
        }
        return arr;
    }
};