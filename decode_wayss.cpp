class Solution {
public:
    int solve(string s,int ind,vector<int>&dp)
    {
        if(ind==s.size())
        {
            return 1;
        }
        //if(s[ind]=='0'){return 0;}
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int res=0;
        if(s[ind]!='0')
        {
            res+=solve(s,ind+1,dp);
        }
        if(ind+1<s.size() && (s[ind]=='1' || s[ind]=='2' && s[ind+1]<='6'))
        {
            res+=solve(s,ind+2,dp);
        }
        return dp[ind]=res;

    }



    int numDecodings(string s) {
        int n=s.size();
       vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for(int ind=2;ind<=n;ind++)
        {
            if(s[ind-1]!='0')
            {
                dp[ind]+=dp[ind-1];
            }
            int two=stoi(s.substr(ind-2,2));
            if(two>=10 && two<=26)
            {
                dp[ind]+=dp[ind-2];
            }
        }
        return dp[n];

       //return solve(s,0,dp); 
    }
};