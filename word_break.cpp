#include <algorithm>
class Solution {
public:
    //RECURSIVE APPROACH
    bool check(string s,int i,int j,vector<string>& wordDict)
    {
        string t=s.substr(i,j-i+1);
       // cout<<t<<endl;
        if(find(wordDict.begin(),wordDict.end(),t)!=wordDict.end())return true;
        return false;
    }
    bool solve(string s, vector<string>& wordDict,int ind)//bool &flag
    {
        if(ind==s.size())
        {
            return true;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(check(s,ind,i,wordDict) && solve(s,wordDict,i+1))
            {
                return true;

            }
        }
        return false;
    }
    //MEMOIZATION
    bool solve(string s, vector<string>& wordDict,int ind,vector<int>&dp)//bool &flag
    {
        if(ind==s.size())
        {
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.size();i++)
        {
            if(check(s,ind,i,wordDict) && solve(s,wordDict,i+1,dp))
            {
                return dp[ind]=true;

            }
        }
        return dp[ind]=false;
    }
//TABULATION

    bool wordBreak(string s, vector<string>& wordDict) {
        
       // cout<<check(s,0,3,wordDict)<<endl;
      // vector<int>dp(s.size()+1,-1);
      int n=s.size();
      vector<bool>dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,i,j,wordDict) && dp[j+1])
            {
               // return
                dp[i]=true;
                break;
            }
            }

        }
        return dp[0];


        //return solve(s,wordDict,0,dp);
    }
};