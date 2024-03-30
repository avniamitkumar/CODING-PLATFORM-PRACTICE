class Solution {
public:
    int M = 1e9 + 7;
    long long solve(int n, int a, int l, vector<vector<vector<int>>> &dp)
    {
        if(a >= 2)
            return 0;
        if(l == 3)
            return 0;
        if(n == 0)
            return 1;
        
        if(dp[n][a][l] != -1)
            return dp[n][a][l];
        
        long long case1 = solve(n - 1, a, 0, dp); // normal;
        long long case2 = solve(n - 1, a + 1, 0, dp); //absent;
        long long case3 = solve(n - 1, a, l + 1, dp); //late
    
        return dp[n][a][l] = (case1 % M + case2 % M + case3 % M) % M;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(4, -1))); // recursive
        return solve(n, 0, 0, dp);
    }
};