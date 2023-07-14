class Solution {
public:
    string removeDuplicates(string s) {
        
        string sb;
       stack<char>b;
        b.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!b.empty() && s[i]==b.top())
                b.pop();
            else
                b.push(s[i]);
         }
        
        while(!b.empty())
            {
            sb.push_back(b.top());
            b.pop();
        }
        reverse(sb.begin(),sb.end());
        return sb;
    }
};