//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void gen(string op,int num)
    {
        if(num==0)
        {
            cout<<op<<" ";
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back('0');
        gen(op1,num-1);
        if(op2.back()!='1'){
        op2.push_back('1');
        gen(op2,num-1);}
        
    }


    void generateBinaryStrings(int& num){
        //Write your code
        string op="";
        gen(op,num);
        return;

   


    }
    
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends