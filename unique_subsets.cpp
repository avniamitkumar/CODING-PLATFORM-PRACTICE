//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    void result(vector <int>ip,vector<int>op,vector<vector<int>> &m)
    {
        if(ip.size()==0)
        {
           
                m.push_back(op);
            
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        result(ip,op1,m);
        result(ip,op2,m);
return;

    }


    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> A, int n)
    {
        // code here 
         vector<vector<int> > v;
    vector<int> op={};
    sort(A.begin(), A.end());
    result(A, op, v);
    set<vector<int>> s;
     int size = v.size();
    for(int  i = 0; i < size; ++i ) 
    s.insert(v[i]);
    v.assign( s.begin(), s.end() );
 
    return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends