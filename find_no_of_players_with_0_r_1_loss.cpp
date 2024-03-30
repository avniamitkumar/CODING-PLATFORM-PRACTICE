class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<matches.size();i++)
        {
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        vector<int>win;
        vector<int>lose;
       for (auto it : mp) {
        if (it.second.second == 0) {
            win.push_back(it.first);
        } else if (it.second.second == 1) {
            lose.push_back(it.first);
        }
    }
        vector<vector<int>>ans;
        ans.push_back(win);
        ans.push_back(lose);
        return ans;
    }
};