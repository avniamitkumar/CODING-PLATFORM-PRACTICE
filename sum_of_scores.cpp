class Solution {
public:
    vector<int>lps(string &s)
    {
        vector<int>lps(s.size(),0);
        int len=0;
        int i=1;
        while(i<s.size())
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }


    long long sumScores(string s) {
        vector<int>cnt;
        for (int j :  lps(s))
        cnt.push_back(j == 0 ? 0 : cnt[j - 1] + 1);   
    return accumulate(begin(cnt), end(cnt), 0LL) + s.size();
    }
};