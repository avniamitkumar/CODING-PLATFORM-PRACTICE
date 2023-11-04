class RandomizedCollection {
public:
    int n;
    vector<int>v;
    unordered_map<int,vector<int>>mp;


    RandomizedCollection() {
        n=0;
        mp.clear();
        v.clear();
    }
    
    bool insert(int val) {
        mp[val].push_back(n++);
        v.push_back(val);
         return mp[val].size()<2;

    }
    
    bool remove(int val) {
        if(mp[val].size()==0)return false;
        int ind=mp[val][mp[val].size()-1];
        mp[val].pop_back();
        v[ind]=v[n-1];
        v.pop_back();
        n--;
        if(n>ind){ mp[v[ind]][mp[v[ind]].size()-1]=ind;sort(mp[v[ind]].begin(), mp[v[ind]].end());}
        return true;

        
    }
    
    int getRandom() {
        int index = rand()%n;
        return v[index];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */