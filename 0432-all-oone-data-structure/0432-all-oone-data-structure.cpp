class Node {
    public:
    int freq;
    unordered_set<string> keys;
    Node* prev;
    Node* next;
    Node(int freq) {
        this->freq = freq;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class AllOne {
public:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> map;
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (map.find(key) == map.end()) {
            Node* nextNode = head->next;
            if (nextNode == tail || nextNode->freq > 1) {
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = nextNode;
                nextNode->prev = newNode;
                head->next = newNode;
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }
        } else {
            Node* currNode = map[key];
            currNode->keys.erase(key);
            Node* nextNode = currNode->next;
            if (nextNode == tail || nextNode->freq != currNode->freq + 1) {
                Node* newNode = new Node(currNode->freq + 1);
                newNode->keys.insert(key);
                newNode->prev = currNode;
                newNode->next = nextNode;
                nextNode->prev = newNode;
                currNode->next = newNode;
                map[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }
            if (currNode->keys.empty()) {
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                delete currNode;
            }
        }
    }

    void dec(string key) {
        if (map.find(key) == map.end()) {
            return;
        } else {
            Node* currNode = map[key];
            currNode->keys.erase(key);
            if (currNode->freq == 1) {
                map.erase(key);
                // return;
            } else {
                Node* prevNode = currNode->prev;
                if (prevNode == head || prevNode->freq != currNode->freq - 1) {
                    Node* newNode = new Node(currNode->freq - 1);
                    newNode->keys.insert(key);
                    prevNode->next = newNode;
                    newNode->next = currNode;
                    newNode->prev = prevNode;
                    currNode->prev = newNode;
                    map[key] = newNode;
                }
                else{
                    prevNode->keys.insert(key);
                    map[key] = prevNode;
                }
            }
            if (currNode->keys.empty()) {
                currNode->prev->next = currNode->next;
                currNode->next->prev = currNode->prev;
                delete currNode;
            }
        }
    }

    string getMaxKey() {
        if(tail->prev == head){
            return "";
        }
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if(head->next == tail){
            return "";
        }
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */