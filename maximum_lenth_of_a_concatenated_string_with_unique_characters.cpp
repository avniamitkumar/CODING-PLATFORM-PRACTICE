class Solution {
public:

    bool check(string &s1,string &s2)
    {
        int arr[26]={0};
        for(char &ch: s1)
        {
            if(arr[ch-'a']>0)
            {
                return true;
            }
            arr[ch-'a']++;
        }
        for(char &ch: s2)
        {
            if(arr[ch-'a']>0)
            {
                return true;
            }
            arr[ch-'a']++;
        }
        return false;
    }
    int solve(vector<string>&arr,int ind,int n,string temp)
    {
        if(ind>=n)
        {
            return temp.size();
        }
        int pick=0;
        if(!check(temp,arr[ind])){
        pick=solve(arr,ind+1,n,temp+arr[ind]);}
        int np=solve(arr,ind+1,n,temp);
        return max(pick,np);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr,0,arr.size(),"");
    }
};