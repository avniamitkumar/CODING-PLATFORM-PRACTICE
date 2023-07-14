class Solution {
    int myAtoi(string s, int i, int sign, int result){
        if(i>=s.size() || s[i]<'0' || s[i]>'9')
            return result*sign;
        int temp = s[i]-'0';
        if(result>INT_MAX/10 || result==INT_MAX/10 && temp>7)
            return sign==1? INT_MAX: INT_MIN;
        return myAtoi(s, i+1, sign, result*10+temp);
    }
public:
    int myAtoi(string s) {
        int i=0, n=s.length(), sign=1;

        while(i<n && s[i]==' ')
            ++i;

        if(s[i]=='-'){   sign=(-sign); ++i;}
        else if(s[i]=='+')  ++i;

        return myAtoi(s, i, sign, 0);
    }
};