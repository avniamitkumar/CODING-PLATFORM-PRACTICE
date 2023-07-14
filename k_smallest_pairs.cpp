#define pi pair<int,pair<int,int>>
class Solution {
public:


    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
      priority_queue<pi,vector<pi>,greater<pi>> pq;
        set<pair<int,int>>st;
        int n=a.size();
        int m=b.size();
        vector<vector<int>> ans;
        if(n==0 || m==0)    return ans;
        st.insert({0,0});
        pq.push({a[0]+b[0],{0,0}});

        while(!pq.empty() && k--)
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            ans.push_back({a[x],b[y]});
             pq.pop();
            if(x<n-1 && st.find({x+1,y})==st.end())
            {
                st.insert({x+1,y});
                pq.push({a[x+1]+b[y],{x+1,y}});
            }
            if(y<m-1 && st.find({x,y+1})==st.end())
            {
                st.insert({x,y+1});
                pq.push({a[x]+b[y+1],{x,y+1}});
            }

        }
     
      
    return ans;

    }
};