class Solution {
public:
    int numberOfBeams(vector<string>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            int present=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='1')
                {
                    present++;
                }
            }
            ans+=(prev*present);
            if(present!=0){
            prev=present;}
        }
        return ans;
    }
};