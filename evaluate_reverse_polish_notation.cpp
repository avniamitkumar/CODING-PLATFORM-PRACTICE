#include <iostream>
#include <stdlib.h>
class Solution {
public:

long long int sol(long long a,long long b,string s)
{
    if(s=="+")return a+b;
    if(s=="-")return a-b;
    if(s=="/" )return a/b;
    if(s=="*")return a*b;
    return 0;
}
    bool isoperand(string s)
    {
        if(s=="+" || s=="-" || s=="*" || s=="/")return false;
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<long long int>st;
        for(int i=0;i<n;i++)
        {
            if(isoperand(tokens[i]))
            {
                int a=stoi(tokens[i]);
                st.push(a);
            }
            else
            {
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int ans=sol(b,a,tokens[i]);
                st.push(ans);
            }

        }
       return st.top();
    }
};