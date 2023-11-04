class Solution {
public:
    int fun(vector<int>&nums,int p,int diff)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=diff)
            {
                i++;
                p--;
            }
        }
        return p<=0;
    }


    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=0;
        int end=nums[n-1]-nums[0];
        int res=0;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(fun(nums,p,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return res;

    }
};