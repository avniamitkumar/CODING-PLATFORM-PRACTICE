class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int sum=0;
        int i=0;
        int n=nums.size();
        int j=0;
        while(j<n)
        {
            sum+=nums[j];
            if(sum<target)
            {
                j++;
            }
            /*else if(sum==target)
            {
                len=min(len,j-i+1);
                j++;
            }*/
            else
            {
                while(sum>=target){
                    len=min(len,j-i+1);
                sum-=nums[i];
                i++;
                  
                }
                
                  
                
               // i++;
                j++;
            }
        }
        if(len==INT_MAX)return 0;
        return len;
    }
};