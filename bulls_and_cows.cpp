class Solution {
public:
    string getHint(string s, string g) {
    unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++)
       {
           mp[s[i]]++;
       }
       int pc=0;
       for(int i=0;i<g.size();i++)
       {
           if(mp.find(g[i])!=mp.end()){
               pc++;
           mp[g[i]]--;
           if(mp[g[i]]==0){mp.erase(g[i]);}}
       }
        int b=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==g[i])b++;
        }
        int c=pc-b;
        
        
         string ans=to_string(b)+"A"+to_string(c)+"B";
        return ans;
    }// pc 2 b 1 c1
};