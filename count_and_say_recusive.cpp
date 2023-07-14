class Solution {
public:

    

    string countAndSay(int n) {
        if(n==1)return "1";
        string chota=countAndSay(n-1);
        chota+='#';
        string ans="";
        int cnt=0;
        char ch=chota[0];
        for(char c:chota)
        {
            if(c!=ch)
            {
                ans+=(cnt+'0');
                ans+=ch;
                cnt=0;
            }
            ch=c;
            cnt++;
        }
        return ans;
    }
};