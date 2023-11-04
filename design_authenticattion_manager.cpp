class AuthenticationManager {
public:
    unordered_map<string,int>mp;
   
    int ttl=0;

    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=ttl+currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)!=mp.end() && mp[tokenId]>currentTime)
        {
            mp[tokenId]=currentTime+ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
         int res = 0;
        for (auto token: mp) {
            if (token.second > currentTime) res++;
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */