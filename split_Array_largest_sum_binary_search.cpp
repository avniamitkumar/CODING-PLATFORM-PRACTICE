class Solution {
public:

    int count_of_subArray(vector<int> &nums,int k)
    {
        int count=1;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]+sum > k)
            {
                count++;
                sum=nums[i];
            }
            else
            sum+=nums[i];
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=count_of_subArray(nums,mid);
            if(count>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};