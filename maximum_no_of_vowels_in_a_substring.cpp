class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int maxlen=INT_MIN;
        int len=0;
        int num=0;
        int n=s.size();
        while(j<n)
        {
            if(isvowel(s[j]))
            {
                num++;
            }
        
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxlen=max(num,maxlen);
                if(isvowel(s[i]))num--;
                i++;j++;
            }
        }
        return maxlen;
    }
};