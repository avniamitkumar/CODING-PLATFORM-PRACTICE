class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
                int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101};
                if(strs.size()==1)
                {
                    return {{strs[0]}};
                }
                 vector<vector<string>> res;
        unordered_map<double , vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            double hash=1;
            for(char c:strs[i])
            {
                hash*=primes[c-'a'];
            }
            mp[hash].push_back(strs[i]);
        }
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        return res;


    }
};