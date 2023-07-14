class Node
{
    public:
    int val,mini;
    Node*next;
    Node(int val)
    {
        this->val=val;
        mini=val;
    }
};
Node*head;
class MinStack {
public:
  
    int mini=INT_MAX;
    MinStack() {
      head=NULL;
    }
    
    void push(int val) {
        Node*temp=new Node(val);
        temp->next=head;
        if(head)
        {
            temp->mini=min(val,head->mini);
        }
        head=temp;
    }
    
    void pop() {
       Node *temp=head;
       head=head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */