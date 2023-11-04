class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        int n=p.size();
        priority_queue<pair<int,int>>pq;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && p[i][0]-pq.top().second>k)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                ans=max(ans,p[i][0]+p[i][1]+pq.top().first);
            }
            pq.push({p[i][1]-p[i][0],p[i][0]});
        }
        return ans;
    }
};