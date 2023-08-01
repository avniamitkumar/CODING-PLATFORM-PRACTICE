class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(vector<vector<int>>&events ,int k,int ind)
    {
        if(ind>=n || k<=0)
        {
            return 0;
        }
     //   int st=events[ind][0];
        int end=events[ind][1];
        int val=events[ind][2];
        if(t[ind][k] != -1)
            return t[ind][k];

        int tk=INT_MIN;
        int nt=INT_MIN;
        vector<int>temp={end,INT_MAX,INT_MAX};
        int j = upper_bound(events.begin(), events.end(), temp) - events.begin();
        tk=val+solve(events,k-1,j);
        nt=solve(events,k,ind+1);
        return t[ind][k]=max(tk,nt);
        }


    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        
        n = events.size();
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, k,0);
        
    }
};