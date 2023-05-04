class Solution {
public:
    int partitionString(string s) {
       // vector<string>s;
        unordered_map<char,int>mp;
      //  string st="";
        int cnt=1;
       for(int i=0;i<s.size();i++){
           if(mp.find(s[i])!=mp.end()){
               mp.clear();
               cnt++;
           }
           mp[s[i]]++;
        }
        return cnt;
    }
};