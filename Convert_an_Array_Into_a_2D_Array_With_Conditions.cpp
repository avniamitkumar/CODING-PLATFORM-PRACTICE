class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int size=0;
        for(auto it:mp)
        {
            size=max(size,it.second);
        }
        vector<vector<int>>ans(size);
          for (auto it : mp) {
            int freq = it.second;
            while (freq > 0) {
                ans[size - freq].push_back(it.first);
                freq--;
            }
        }
        
        return ans;
    }
};