//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void printStrings(int ind, int n, int prev, string temp)
{
    if (ind == n)
    {
        cout<<temp<<" ";
        return;
    }
    if(prev==-1)
    {
        printStrings(ind+1,n,0,temp+"0");
        printStrings(ind+1,n,1,temp+"1");
    }
    else if(prev==0)
    {
         printStrings(ind+1,n,0,temp+"0");
        printStrings(ind+1,n,1,temp+"1");
    }
    else
    {
           printStrings(ind+1,n,0,temp+"0");
    }
    
    
}


    void generateBinaryStrings(int num){
        int prev=-1;
        printStrings(0,num,prev,"");
        //Write your code
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends