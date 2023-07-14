class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        pair<int,char>p;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char c=pq.top().second;
            while(freq--)
            {
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }
};