class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        //vector<vector<int>>st;
         map<vector<int>,int>mp;
        int cnt=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            mp[grid[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(grid[j][i]);
            }
           cnt+=mp[temp];
        }
        return cnt;
    }
};