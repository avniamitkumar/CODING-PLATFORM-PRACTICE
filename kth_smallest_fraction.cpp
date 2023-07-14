class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,pair<int,int>>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                pq.push({(double)(1.00*arr[i])/arr[j],{arr[i],arr[j]}});
            }
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        return {a,b};
            }
};