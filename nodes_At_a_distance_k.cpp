//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
//   unordered_map<int,int> mp; 
// void parentMarkup(Node* root, unordered_map<Node*, Node*>& mp) {
//     if (!root) return;
    
//     if (root->left) {
//         mp[root->left] = root;
//         parentMarkup(root->left, mp);
//     }
    
//     if (root->right) {
//         mp[root->right] = root;
//         parentMarkup(root->right, mp);
//     }
// }
//     int kth(Node *node,int k)
//     {
//       if(node==NULL)
//       {
//           return 0;
//       }
//       if(k==0 && mp[leaf]=)
        
        
//     }
    
//     int ans=0;
//     void solve(Node*root,int k)
//     {
//         if(!root)return;
//         if(!root->left && !root->right)
//         {
//             ans+=kth(root,k,root);
//             return ;
//         }
//         solve(root->left,k);
//         solve(root->right,k);
        
//     }
      set<Node*>s;
 void func(Node* root,int k,int h,map<int,Node*>mp){
    if(root==NULL){
        return;
    }    
    mp.insert({h,root});
    if(root->left==NULL && root->right==NULL && h>=k){
        s.insert(mp[h-k]);
        return;
    }
    func(root->left,k,h+1,mp);
    func(root->right,k,h+1,mp);
}
int printKDistantfromLeaf(Node* root, int k)
{
    s.clear();
    map<int,Node*>mp;
func(root,k,0,mp);
return s.size();
}
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends