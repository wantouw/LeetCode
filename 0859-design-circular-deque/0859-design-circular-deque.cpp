class Node {
public:
    int value;
    Node* prev;
    Node* next;
    Node(int value) {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int max, size;
    MyCircularDeque(int k) {
        size = 0;
        head = tail = nullptr;
        max = k;
    }

    bool insertFront(int value) {
        Node* newNode = new Node(value);
        if (size == max)
            return false;
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        Node* newNode = new Node(value);
        if (size == max)
            return false;
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (!head) {
            return false;
        } else {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size = 0;
            } else {
                head = head->next;
                delete head->prev;
                size--;
            }
            return true;
        }
    }

    bool deleteLast() {
        if (!head) {
            return false;
        } else {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size = 0;
            } else {
                tail = tail->prev;
                delete tail->next;
                size--;
            }
            return true;
        }
    }

    int getFront() {
        if (!head) {
            return -1;
        }
        return head->value;
    }

    int getRear() {
        if (!head) {
            return -1;
        }
        return tail->value;
    }

    bool isEmpty() {
        if (!head) {
            return true;
        }
        return false;
    }

    bool isFull() { return size == max; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */