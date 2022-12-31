 vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        vector<int> ans;
        
        int i = 0;
        while(i < N){
            if(st.empty()){
                st.push(asteroids[i]);
                ++i;
            }
            else{
                if((asteroids[i] > 0 && st.top() > 0) || 
                (asteroids[i] < 0 && st.top() < 0) ||
                (asteroids[i] > 0 && st.top() < 0)){
                    st.push(asteroids[i]);
                    ++i;
                }
                else if(asteroids[i] < 0 && st.top() > 0){
                    int a = st.top();
                    st.pop();
                    
                    if(a == abs(asteroids[i]))
                        ++i;
                    else if(a > abs(asteroids[i])){
                        st.push(a);
                        ++i;
                    }
                    else if(a < abs(asteroids[i])){
                        continue;
                    }
                }
            }
        }
        
        while(!st.empty()){
            int a = st.top();
            st.pop();
            ans.push_back(a);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }