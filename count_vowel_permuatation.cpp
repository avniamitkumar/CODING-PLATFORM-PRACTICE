class Solution {
public:
    int n;
    vector<vector<int>>dp;
    long long mod=1e+9;
    int f(int ind,int c)
    {
        if(ind==n)
        {
            return 1;
        }
        if(dp[ind][c]!=-1)dp[ind][c];
        long long ans=0;
        switch(c)
        {
            case 0: ans+= f(ind+1,1)%mod;
                    break;
            case 1: ans+= (f(ind+1,0)+f(ind+1,2))%mod;
                    break;
            case 2: ans=(ans+f(ind+1,0)+f(ind+1,1)+f(ind+1,3)+f(ind+1,4))%mod;
                    break;
            case 3: ans+= (f(ind+1,2)+f(ind+1,4))%mod;
                    break;
            case 4: ans+= f(ind+1,0)%mod;
                    break;

        }
        return dp[ind][c]=ans;
    }


    int countVowelPermutation(int n) {
         this->n = n;
        dp.assign(n + 1, vector<int>(5, -1));
        long long ans = 0;
        for (int j = 0; j < 5; j++)
            ans = (ans + f(1,j)) % mod;// starting from length=1
        return ans;
    }
};