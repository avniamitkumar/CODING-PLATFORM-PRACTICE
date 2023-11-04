class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]+=1;
        }
        unordered_map<int,int>fc;
        int ans=0;
        for(auto it:mp)
        {
            int cnt=it.second;
            if(fc[cnt]!=0)
            {
                while(cnt>0 && fc[cnt]!=0)
                {
                    ans++;
                    cnt--;
                }
            }
            fc[cnt]++;
        }
        return ans;

    }
};