class Solution {
public:
    int n;
    vector<int>t;
    int solve(vector<vector<int>>&intervals,int ind)
    {
        if(ind>=n)
        {
            return 0;
        }
         int tk=0;
        int nt=0;
        //vector<int>temp={end,INT_MAX,INT_MAX};
        if(t[ind]!=-1)return t[ind];
       int low = ind+1,high = intervals.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(intervals[mid][0] < intervals[ind][1]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        tk=1+solve(intervals,low);
         nt=solve(intervals,ind+1);
        return t[ind]=max(tk,nt);

    }



    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(begin(intervals), end(intervals));
        
        n = intervals.size();
        
        t.resize(n+1, -1);
        
        return n-solve(intervals, 0);
    }
};