class Solution {
public:
    void permute(string in,string op,set <string>&m)
    {
        if(in.length()==0)
        {
            m.insert(op);
            return;
        }
        string op1=op;
    
        string op2=op;
    
    op1.push_back(tolower(in[0]));
    op2.push_back(toupper(in[0]));
    in.erase(in.begin()+0);
    permute(in,op1,m);
    permute(in,op2,m);
        
    }


    vector<string> letterCasePermutation(string s) {
        set<string > st;
        vector<string>ans;
        string ip=s;
        string op="";
        permute(ip,op,st);
        for(auto it=st.begin();it!=st.end();it++){
        ans.push_back(*it);
        }
        return ans;



    }
};