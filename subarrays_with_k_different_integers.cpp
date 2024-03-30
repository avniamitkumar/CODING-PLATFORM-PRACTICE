class Solution {
public:
    int solve(vector<int>&arr,int k)
    {
  int n=arr.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n)
        {
            mp[arr[j]]++;
            while(i<n && mp.size()>k)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                {
                    mp.erase(arr[i]);
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
      return solve(arr,k)-solve(arr,k-1);
    }
};