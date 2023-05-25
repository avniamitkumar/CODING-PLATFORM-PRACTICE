//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
        int n=arr.size();
        // Code here.
        long long int xo=arr[0];
        for(int i=1;i<n;i++)
        {
            xo=xo^arr[i];
        }
        int xor_bit=xo & ~(xo-1);
         long long  int a = 0;

        long long int b = 0;

        for(long long int j=0; j<n; j++){

            if(arr[j]&xor_bit){

                a^=arr[j];

            }else{

                b^=arr[j];

            }

        }

        

        return {min(a,b), max(a,b)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends