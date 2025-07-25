class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node *prev, *next;
        Node(int data, int key) : key(key), value(data), next(nullptr), prev(nullptr){}
    }*head, *tail;

    unordered_map<int, Node*> map;
    int size;
    int currSize;

    LRUCache(int capacity) {
        size = capacity;
        currSize = 0;
        head = tail = nullptr;
        // map[0] = new Node(10);
        // cout << map[0]->value;
    }

    void takeToHead(Node* node){
        // cout << "di take to head: " << node->value << endl;
        if(node == head) return;
        if(node == tail){
            node->prev->next = nullptr;
            tail = node->prev;
            pushHead(node);
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        pushHead(node);
    }

    void pushHead(Node* node){
        if(head == nullptr){
        // cout << node->value << " node" << endl;
            head = tail = node;
        }
        else {
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
        }
        
    }
    
    int get(int key) {
        // print();
        // cout << "get: " << key << endl;
        if(map[key]!=nullptr){
            takeToHead(map[key]);
            return map[key]->value;
        }
        return -1;
    }

    int popTail(){
        int key;
        if(head == nullptr) return -1;
        key = tail->key;
        if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        Node *curr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete curr;
        currSize--;
        return key;
    }

    void insertOrPrioritizeValue(int key, int value){
        if(map[key] == nullptr){
            // cout << "made new node: " << key << " " << value << endl;
            map[key] = new Node(value, key);
            pushHead(map[key]);
            currSize++;
        }
        map[key]->value = value;
        takeToHead(map[key]);
        // currSize++;
    }

    void print(){
        Node *curr = head;
        cout << "ll: ";
        while(curr){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
        if(tail != nullptr){
        cout << "tail: " << tail->value << endl;
        cout << "head: " << head->value << endl;

        }
    }
    
    void put(int key, int value) {
        // print();
        insertOrPrioritizeValue(key, value);
        if(currSize > size){
            // print();
            int erased = popTail();
            map.erase(erased);
            // cout << "deleted: " << erased << endl;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */