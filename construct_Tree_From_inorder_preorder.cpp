//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
     int search(int in[],int start,int end,int cur){
        for(int i=start;i<=end;i++){
            if(in[i]==cur){
                return i;
            }
        }
        return -1;
    }
    int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
   Node*bt (int in[],int pre[],int n,int &st,int ins,int ine)
    {
        if(ine<ins)return NULL;
        Node* root=new Node(pre[st]);
        int mid=search(in,ins,ine,pre[st]);
        st++;
        root->left=bt(in,pre,n,st,ins,mid-1);
        root->right=bt(in,pre,n,st,mid+1,ine);
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int st=0;
        
         Node* root=bt(in,pre,n,st,0,n-1);
        return root;
        
        
    }
    /*   Node* make_tree(int in[],int pre[], int s, int e, int curr)
    {
        if(s>e)
        {
            return NULL;
        }
        
        Node* root=new Node(pre[curr]);
        int mid=binarySearch(in,s,e,pre[curr]);
        curr++;
        root->left=make_tree(in,pre,s,mid-1,curr);
        root->right=make_tree(in,pre,mid+1,e,curr);
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root=NULL;
        root=make_tree(in,pre,0,n-1,0);
        return root;
    }*/
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends