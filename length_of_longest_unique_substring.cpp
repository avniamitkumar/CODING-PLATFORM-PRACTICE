class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int mp[256]={0};
        int maxlen=-1;
       // unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int len=0;
        while(j<s.length())
        {
            //len++;
            mp[s[j]]++;
            while(mp[s[j]]>1)
                {
                    mp[s[i]]--;
                    i++;
                   // len--;
                }
            
                maxlen=max(maxlen,j-i+1);
            
            j++;
            
        }
        return maxlen;
        
        
        
        
    }
};