class Solution {
public:

    int solve(int i,string &s,unordered_map<string,int>&mp,vector<int>&dp)
    {
        if(i==s.size())
        {
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int x=0;
        string ans="";
        int res=s.size();
        int tot=0;
        for(int ind=i;ind<s.size();ind++)
        {
            ans+=s[ind];
            if(mp.find(ans)==mp.end())
            {
                x=ans.size();
            }
            else
            {
                x=0;
            }
            int z=solve(ind+1,s,mp,dp);
            tot=z+x;
            res=min(tot,res);

        }
        dp[i]=res;
        return res;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int>mp;
        vector<int>dp(s.size(),-1);
        for(int i=0;i<dictionary.size();i++)
        {
            mp[dictionary[i]]=0;
        }
        int ans=solve(0,s,mp,dp);
        return ans;
    }
};