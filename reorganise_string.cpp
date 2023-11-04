class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        string a="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
          for(auto itr = mp.begin() ; itr != mp.end() ; itr++){
            pq.push({itr->second, itr->first});
        }
        int size=s.size();
        int ind=0;
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            if(2*freq-1>size) return "";
            while(freq-->0)
            {
                if(ind>=s.size())ind=1;
                s[ind]=ch;
                ind+=2;
            }
        }
        return s;
        
    }
};class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        string a="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
          for(auto itr = mp.begin() ; itr != mp.end() ; itr++){
            pq.push({itr->second, itr->first});
        }
        int size=s.size();
        int ind=0;
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            if(2*freq-1>size) return "";
            while(freq-->0)
            {
                if(ind>=s.size())ind=1;
                s[ind]=ch;
                ind+=2;
            }
        }
        return s;
        
    }
};