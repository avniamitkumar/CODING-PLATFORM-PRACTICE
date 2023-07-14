class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create a frequency array to keep track of the count of each task
        vector<int> freq(26);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());
        // Calculate the maximum frequency of any task
        int maxFreq = freq[25] - 1;
        // Calculate the number of idle slots that will be required
        int idleSlots = maxFreq * n;
        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idleSlots -= min(maxFreq, freq[i]);
        }
        // If there are any idle slots left, add them to the total number of tasks
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
          priority_queue<int>pq;
    vector<int>vec(26,0);
   for(int i=0;i<tasks.size();i++)
   {
       vec[tasks[i]-'A']++;
   }

   // so now in the vec we have freq of A as 2, B as 2 , C as 1 stored at 0,1,2 index respectively.

   for(int i=0;i<26;i++)
   {
       if(vec[i])
       {
           pq.push(vec[i]);
       }
   }

  // pq would look like 2 2 1 (top->bottom since max heap)

    int time =0; 

    while(!pq.empty())
    {              
        vector<int>remain;
        int count=K+1 ;
        // here the count is 3 (2+1)

        // but why 3 as if you see minm distance between two A's has to be 2 something like A _ _ A so the the count is actually refering to the [] -> [A _ _] .

// here gonna show only iteration 1 
        while(count && !pq.empty())
        {
            int freq=pq.top();
            // freq will be 2( as max freq is two rn)
            pq.pop();

            // (so we have placed one A(say ) , but 1 is still left so we push 1 to remain vector)

            if(freq>1)
            {
               remain.push_back(freq-1);
            }

            time++;  // time becomes 1 
            count--; // two more to come in the same cycle [A _ _] -->blanks basically 
        }

        for(int i=0;i<remain.size();i++)
        {
            pq.push(remain[i]);
            // again we account for the remaining task and perform same for them 
        }
        if(pq.empty())
        {
            break;
        }
        time+=count; // this is basically for the idle time when the pq got empty(no different task (satisfying cool down)) so you cant do anything.
        
    }
return time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends