class Solution {
public:
    long long totalCost(vector<int>& c, int k, int can) {
        
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;//min heap
        long long ans=0;
        int cnt=0;
        int i=0;
        int j=c.size()-1;
        while(cnt<k)
        {
            while(pq1.size()<can && i<=j)pq1.push(c[i++]);
            while(pq2.size()<can && j>=i)pq2.push(c[j--]);
            int c1=pq1.size()>0?pq1.top():INT_MAX;
            int c2=pq2.size()>0?pq2.top():INT_MAX;
            if(c1<=c2)
            {
                ans+=c1;
                pq1.pop();
            }
            else
            {
                ans+=c2;
                pq2.pop();
            }
            cnt++;
        }
        return ans;



    }
};