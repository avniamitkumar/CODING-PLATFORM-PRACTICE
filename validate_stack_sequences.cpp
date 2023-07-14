class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int>st;
       int j=0;
       int n=pushed.size();
       for(int i=0;i<n;i++)
       {
           st.push(pushed[i]);
           if(!st.empty() && st.top()==popped[j])
           {
               while(!st.empty() && st.top()==popped[j])
               {
                   j++;
                   st.pop();
               }
           }
       } 
       return st.size()==0;
    }
};