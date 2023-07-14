//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &arr) {
        // code here
        int ten=0;
        int five=0;
        int ten2=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==5)
            {
                five++;
            }
            if(arr[i]==10)
            {
                ten++;
                if(five-1>=0)
                {
                    five--;
                }
                else
                {
                    return false;
                }
            }
            if(arr[i]==20)
            {
                ten2++;
                if(ten-1>=0 && five-1>=0)
                {
                    ten--;
                    five--;
                }
                else if(five-1>=3)
                {
                    five-=3;   
                }
                else
                {
                    return false;
                }
                
                
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends