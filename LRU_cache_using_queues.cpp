class LRUCache {
public:

        queue<int>q;
        map<int,int>mp,cnt;
        int size;
    LRUCache(int capacity) {
        size=capacity;
        
    }
    
    int get(int key) {
        if(cnt.find(key)!=cnt.end())
        {
            q.push(key);
            cnt[key]++;
            return mp[key];
        }
       
        return -1;
    }
    
    void put(int key, int value) {
       	q.push(key);
	cnt[key]++;
	mp[key] = value;
	while (cnt.size() > size) {
		int cur = q.front(); q.pop();
		if (cnt[cur]-- == 1) 
			cnt.erase(cur);
	}

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */