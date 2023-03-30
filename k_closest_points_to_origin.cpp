class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,pair<int,int>>>maxh;
        for(int i=0;i<points.size();i++)
        {
            int dis=pow(points[i][0],2)+pow(points[i][1],2);
            maxh.push({dis,{points[i][0],points[i][1]}});
            if(maxh.size()>k)
            {
                maxh.pop();
            }

        }
        vector<vector<int>>ans;
        while(maxh.size()>0)
        {
            vector<int>temp;
            temp.push_back(maxh.top().second.first);
            temp.push_back(maxh.top().second.second);
            ans.push_back(temp);
            maxh.pop();
        }
        return ans;
    }
};