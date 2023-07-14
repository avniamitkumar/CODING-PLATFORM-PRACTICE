class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&ds,int ind,int &k)
    {
        if(ind==0)
        {
            if(k==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(ind);
        k=k-1;
        solve(ans,ds,ind-1,k);
        k+=1;
        ds.pop_back();
        solve(ans,ds,ind-1,k);

    }



    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(ans,ds,n,k);
        return ans;
    }
};