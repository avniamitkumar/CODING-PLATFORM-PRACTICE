class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int req=sum-x;
        if(req==0)return nums.size();
        int i=0;
        int j=0;
        int fsum=0;
        int maxi=0;
        while(j<n)
        {
            fsum+=nums[j];
            while(fsum>req && i<=j)
            {
                fsum-=nums[i];
                i++;
            }
            if(fsum==req){
            maxi=max(maxi,j-i+1);}
            j++;
        }
        if(maxi==0)return -1;
        return n-maxi;
    }
};