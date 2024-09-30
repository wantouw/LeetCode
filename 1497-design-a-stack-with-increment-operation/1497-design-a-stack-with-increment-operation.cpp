class Node {
    public:
    int x;
    Node* prev;
    Node* next;
    Node(int x){
        this->x = x;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class CustomStack {
public:
    Node* head;
    Node* tail;
    int size;
    int max;
    CustomStack(int maxSize) {
        head = nullptr;
        tail = nullptr;
        max = maxSize;
        size = 0;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        if(size == max) return;
        if(!head){
            head = newNode;
            tail = newNode;
        }
        else{
            // cout << head->x << endl;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    int pop() {
        if(!head) return -1;
        int result = -1;
        if(head == tail){
            result = head->x;
            delete head;
            head = tail = nullptr;
        }
        else{
            result = tail->x;
            tail = tail->prev;
            // Node* temp = tail->next;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
        return result;
    }
    
    void increment(int k, int val) {
        Node* curr = head;
        for(int i = 0;i<k;i++){
            if(!curr) return;
            curr->x+=val;
            curr = curr->next;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */