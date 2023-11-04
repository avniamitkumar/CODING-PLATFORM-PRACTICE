class Solution {
public:
    bool isNumber(string s) {
        bool d=false,el=false,er=false;
        int i=0;
        int n=s.size();
        if(s[i]=='-' || s[i]=='+')
        {
            i=1;
        }
        while(i<n && isdigit(s[i]))
        {
            el=1;
            d=true;
            i++;
        }
        if(s[i]=='.')
        {
            i++;
            while(i<n && isdigit(s[i]))
            {
                d=true;
                el=true;
                i++;
            }
        }
        if(i==n)
        {
            return d;
        }
        if(s[i]=='e' || s[i]=='E')
        {
            i++;
        
        if(s[i]=='-' || s[i]=='+')
        {
            i++;
        }
        while(i<n && isdigit(s[i]))
        {
            er=true;
            i++;
        }}
    
    return (i==n) && (d && er && el);}//!(er^ el));}
};