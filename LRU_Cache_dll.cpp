//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class node{
public:
    int key, val;
    node *prev, *next;
    node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    int cap;
    node* head=new node(0,0);
    node* tail=new node(0,0);
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
     void addnode(node* n)
    {
            node*temp=head->next;
            n->next=temp;
            temp->prev=n;

            head->next=n;
            n->prev=head;   
    }
    void delnode(node *n)
    {
        node* nprev=n->prev;
        node* nnext=n->next;
        nprev->next=nnext;
        nnext->prev=nprev;

    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end())
        {
            node *res=mp[key];
            int ans=res->val;
            mp.erase(key);
            delnode(res);
            addnode(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            node *exist=mp[key];
            delnode(exist);
            mp.erase(key);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]=head->next;
        // your code here   
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends