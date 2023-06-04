class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        map<pair<int,int>,int>m;
        for(auto P:r)
        {
            m[{P[0],P[1]}]++;//bottom left
            m[{P[2],P[3]}]++;//top right
            m[{P[0],P[3]}]--;//top left
            m[{P[2],P[1]}]--;//bottom right
        }
        int sum=0;
        for(auto it:m)
        {
            sum+=abs(it.second);
        }
        if(sum==4)return true;
        else return false;
    }
};