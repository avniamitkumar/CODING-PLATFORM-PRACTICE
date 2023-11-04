class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int cnt=0;
        int ans=INT_MIN;
        int len=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            mp[s[j]]++;
            cnt=max(cnt,mp[s[j]]);
            if(j-i+1-cnt <=k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else if(j-i+1 -cnt >k)
            {
                while(j-i+1 -cnt >k)
                {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};