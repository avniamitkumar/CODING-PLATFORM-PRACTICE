//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int arr[], int n) {
    int ans = INT_MIN;
    int st = 0;
    int end = 0;
    int sum = 0;
    int fs = -1;
    int fe = -1; // Initialize fe to -1

    for (int i = 0; i < n; i++) {
          if(sum==0)
           {
               st=i;
           }
        sum += arr[i];

        if (ans < sum && arr[i]>0) {
            ans = sum;
            fs = st;
            fe = i; // Update fe when a new maximum sum subarray is found
        }
        else if(arr[i]>0 && sum==ans && (i-st)>(fe-fs))
        {
                  fs=st;
                fe=i;
        }

        if (sum < 0 || arr[i] < 0) {
          //  st = i + 1; // Update st to the next index
            sum = 0;
        }
    }
    if(fs==-1 && fe==-1) return {};
    vector<int> a;
    
        for (int i = fs; i <= fe; i++) {
            a.push_back(arr[i]);
        
    }

    return a;
}

};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends