class Solution {
public:
    int longestWPI(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>8)arr[i]=1;
            else arr[i]=-1;
        }
        unordered_map<int,int>mp;
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>0)
            {
                maxi=max(maxi,i+1);
            }
            else
            {
                if(mp.find(sum-1)!=mp.end())
                {
                    maxi=max(maxi,i-mp[sum-1]);
                }
            }
             if(mp.find(sum)==mp.end())
            mp[sum]=i;
        }   
        return maxi;
    }
};