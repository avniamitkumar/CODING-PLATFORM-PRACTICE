class Solution {
public:
    bool valid(string temp)
    {
        if(temp.size()==0 || temp.size()>3 ||(temp.size()>1 && temp[0]=='0') || stoi(temp)>255)
        {
            return false;
        }
        return true;
    }

    void solve(string s,string temp,vector<string>&ans,int ind,int k)
    {
        if(k==0)
        {
            if(ind==s.size()){
            ans.push_back(temp.substr(0, temp.size()-1));
        }return;}
        for(int i=ind;i<s.size();i++)
        {
           
            if(valid(s.substr(ind, i-ind+1)))
        {
            temp.push_back(s[i]);
            temp.push_back('.');
           solve(s,temp,ans,i+1,k-1);
            temp.pop_back();
        }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp="";
        solve(s,temp,ans,0,4);
        return ans;
    }
};