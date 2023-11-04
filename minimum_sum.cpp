//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string findsum(string s1,string s2)
    {
        string s="";
        if(s1.size()==0 && s2.size()==0)
        {
            return "0";
        }
        if(s1.size()>s2.size())
        {
            swap(s1,s2);
        }
        int n1=s1.size();
        int n2=s2.size();
        int c=0;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        for(int i=0;i<n1;i++)
        {
            int num=(s1[i]-'0')+(s2[i]-'0')+c;
            c=num/10;
            s+=(num%10+'0');
        }
        int j = n1;
        for(j;j<n2;j++){
            int num = (s2[j]-'0')+c;
            s.push_back(num%10 + '0');
            c = num/10;
        }
        if(c){
            s.push_back(c + '0');
        }
        reverse(s.begin(),s.end());
        return s;
    }


   string solve(int arr[], int n) {
    sort(arr, arr + n);
    string num1 = "";
    string num2 = "";

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
                  int num = arr[i];
                if(num ==0 and num1.length()==0) continue;
                num1 += to_string(num);
        } else {
                  int num = arr[i];
                if(num ==0 and num2.length()==0) continue;
                num2 += to_string(num);
        }
    }

   // int sum = stoi(num1) + stoi(num2);
    return findsum(num1,num2);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends