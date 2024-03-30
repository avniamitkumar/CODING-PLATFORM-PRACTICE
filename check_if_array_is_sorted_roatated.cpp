class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
       for(int i=0;i<n;i++)
       {
           bool f=true;
           for(int j=0;j<n-1;j++)
           {
               if(nums[(j+i)%n]>nums[(j+i+1)%n]){
                   f=false;
               }
           }
           if(f)return true;
       }
       return false;
    }
};