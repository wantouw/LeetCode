class MinStack {
public:
    struct Node {
        int value;
        Node *prev, *next;
        Node(int val): value(val), prev(nullptr), next(nullptr) {};
    }*head, *tail;

    stack<Node*> minStack;

    MinStack() {
        head = tail = nullptr;
    }
    
    void push(int val) {
        Node* newNode = new Node(val);
        minStack.push(newNode);
        // cout << "value: " << val << endl;
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            if(val < head->value){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else if (val >= tail->value) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else {
                Node *curr = head;
                while(curr->next && curr->value <= val){
                    curr = curr->next;
                }
                newNode->prev = curr->prev;
                newNode->next = curr;
                curr->prev->next = newNode;
                curr->prev = newNode;
            }
        }
    }
    
    void pop() {
        Node* deleted = minStack.top();
        if(deleted == head && deleted == tail){
            head = tail = nullptr;
        }
        else if(deleted == head){
            head = head->next;
            head->prev = nullptr;
        }
        else if(deleted == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            deleted->prev->next = deleted->next;
            deleted->next->prev = deleted->prev;
        }
        delete deleted;
        deleted = nullptr;
        minStack.pop();
    }
    
    int top() {
        return minStack.top()->value;
    }
    
    int getMin() {
        return head->value;
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