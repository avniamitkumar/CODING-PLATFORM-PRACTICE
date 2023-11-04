class Solution {
public:
    string decodeAtIndex(std::string s, int k) {
        long long dc=0;
        for(auto ch:s)
        {
            if(isdigit(ch))
            {
                dc*=ch-'0';
            }
            else
            {
                dc++;
            }
        }

        for(int i=s.size()-1;i>=0;i--)
        {
            if(isdigit(s[i]))
            {
                dc/=(s[i]-'0');
                k=k%dc;
            }
            else
            {
                if(k==0 || dc==k)
                {
                     return string("") + s[i];
                }
                dc--;
            }
        }
        return "";
    }
};