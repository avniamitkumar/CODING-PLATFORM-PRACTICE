class Solution {
public:
    void solve(vector<int>&arr,vector<int>&ds,int ind,int&ans)
    {
        if(ind==arr.size())
        {
            int maxi=*max_element(ds.begin(),ds.end());
            ans=min(ans,maxi);
            return ;
        }
        for(int i=0;i<ds.size();i++)
        {
            ds[i]+=arr[ind];
            solve(arr,ds,ind+1,ans);
            ds[i]-=arr[ind];
        }
    }


    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>ds(k,0);
        int ans=INT_MAX;
        solve(cookies,ds,0,ans);
        return ans;
    }
};