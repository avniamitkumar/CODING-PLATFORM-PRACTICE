class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size() || s.size()==1)return false;
        vector<int>diff;
        vector<int>hash(26,0);
        bool f=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])diff.push_back(i);
            else
            {
                hash[s[i]-'a']++;
                if(hash[s[i]-'a']>=2)f=true;
            }}
            if(diff.size()>2)return false;
            if(diff.size()==1)return false;
            if(diff.size()==0)
            {
                return f;
            }
            int a=diff[0];
            int b=diff[1];
            swap(s[a],s[b]);
            return s==goal;
        
        // for(int i=0;i<s.size();i++)
        // {
        //     for(int j=i+1;j<s.size();j++)
        //     {
        //         swap(s[i],s[j]);
        //         if(s==goal)return true;
        //         swap(s[i],s[j]);
        //     }
        // }
        // return false;
    }
};