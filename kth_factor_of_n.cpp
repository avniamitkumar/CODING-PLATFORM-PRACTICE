class Solution {
public:
    int kthFactor(int n, int k) {
        int end=sqrt(n);
        //max heap
        
        priority_queue<int,vector<int>>pq;
        pq.push(n);
        for(int i=1;i<=n/2;i++)
        {
             if(n%i==0){
            pq.push(i);} 
            if(pq.size()>k)
            {
                pq.pop();
            }
           
        }
        if(pq.size()<k)return -1;
      //  pq.pop();
        return pq.top();
    }
};