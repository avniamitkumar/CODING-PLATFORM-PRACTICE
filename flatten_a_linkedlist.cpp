//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/


//MergeSort Function O(n*logn)
    Node* mergelist(Node *l1, Node *l2)
    {
        Node *ptr = new Node(0);
        Node *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->data <= l2->data)
            {
                curr -> bottom = l1;
                l1 = l1 -> bottom;
            }
            else
            {
                curr -> bottom = l2;
                l2 = l2 -> bottom;
            }
        
        curr = curr ->bottom;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> bottom = l1;
            l1 = l1->bottom;
        }
        
        if(l2 != NULL)
        {
            curr -> bottom = l2;
            l2 = l2 ->bottom;
        }
        
        return ptr->bottom;
    }

Node* sortList(Node* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->bottom == NULL)
            return head;
        
        
        Node *temp = NULL;
        Node *slow = head;
        Node *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> bottom != NULL)
        {
            temp = slow;
            slow = slow->bottom;          //slow increment by 1
            fast = fast ->bottom->bottom;  //fast incremented by 2
            
        }   
        temp -> bottom = NULL;            //end of first left half
        
        Node* l1 = sortList(head);    //left half recursive call
        Node* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
    
    
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *head)
{
    Node*p=head,*q=head;
    while(p)
    {
        while(q->bottom)
        {
            q=q->bottom;
        }
        q->bottom=p->next;
        p=p->next;
    }
    p=head;
    


    return sortList(head);
    
   // Your code here
}

