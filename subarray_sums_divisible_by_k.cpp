class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=(sum%k);
            if(rem<0)
            {
                rem+=k;
            }
            cnt=cnt+mp[rem];
            mp[rem]++;
        }
        return cnt;





    //     int n=nums.size();
    //     vector<int>p;
    //     int sum=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         sum+=nums[i];
    //         p.push_back(sum);
    //        // cout<<p[i]<<" ";
    //     }
    //    // cout<<endl;
    //     int ans=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(((p[j]-p[i])%k)==0)
    //             {
    //                 ans++;
    //             }
    //         }
    //         if(p[i]%k==0)ans+=1;
    //     }
    //     return ans;
    }
};