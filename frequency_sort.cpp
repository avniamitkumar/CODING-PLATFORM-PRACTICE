class Solution {
public:
class Compare {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }};
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
       priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxh;

        for(auto it:mp)
        {
            maxh.push({it.second,it.first});
        }
        vector<int>ans,my;
        while(!maxh.empty())
        {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            while(mp[ans[i]]!=0)
            {
                my.push_back(ans[i]);
                mp[ans[i]]--;
            }
        }
        return my;
    }
};