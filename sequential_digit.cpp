class Solution {
public:
    void solve(int i,long long cur,int low,int high,vector<int>&ans)
    {
        if(cur<=high && cur>=low)
        {
            ans.push_back(cur);
        }
        if(i==10)
        {
            return ;
        }
        if(cur>high)
        {
            return ;
        }
        cur*=10;
        cur+=i;
        solve(i+1,cur,low,high,ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            solve(i,0,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};