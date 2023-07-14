class Solution {
public:
    // long long int fact(int a)
    // {
    //     if(a<=1)return 1;
    //     return a*fact(a-1);
    // }
    //   long long int nCr(int i,int j)
    // {
    //       long long int a=fact(i);
    //       long long int b=fact(j);
    //       long long int c=fact(i-j);
    //     return a/(b*c);

    // }


    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        // for(int i=0;i<n;i++)
        // {
        //     vector<int>temp;
        //     for(int j=0;j<=i;j++)
        //     {
        //         temp.push_back(nCr(i,j));
        //     }
        //     ans.push_back(temp);
        // }
        if(n==1)return {{1}};
        if(n==2)return {{1},{1,1}};
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=2;i<n;i++)
        {
             vector<int>temp;
             temp.push_back(1);
             for(int j=1;j<i;j++)
             {
                 temp.push_back(ans[i-1][j-1]+ans[i-1][j]);

             }
             temp.push_back(1);
             ans.push_back(temp);
        }

        return ans;
    }
};