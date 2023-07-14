class Solution {
public:
    int strStr(string h, string n) {
        if(n.size()>h.size())return -1;
        int ans=-1;
        for(int i=0;i<h.size();i++)
        {
            if(h[i]==n[0])
            {
                ans=i;
                int k=0;
                for(int j=i;k<n.size();j++,k++)
                {
                    if(h[j]!=n[k])
                    {
                        ans=-1;
                        break;
                    }
                    
                }
                if(ans!=-1)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};