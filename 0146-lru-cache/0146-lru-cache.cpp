class LRUCache {
public:
    class Node {
    public:
        int key;
        int data;
        Node* prev;
        Node* next;

        Node(int key, int data) {
            this->key = key;
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* foundNode = mp[key];
        int value = foundNode->data;
        moveNodeToHead(foundNode); // Move the accessed node to the head
        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* foundNode = mp[key];
            foundNode->data = value;
            moveNodeToHead(foundNode);
        } else {
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            // Check and remove the tail if capacity is exceeded
            if (mp.size() > capacity) {
                Node* nodeToBeDel = tail;
                tail = tail->prev;
                if (tail) {
                    tail->next = nullptr;
                } else {
                    head = nullptr; // Cache is empty
                }
                nodeToBeDel->prev = nullptr;
                mp.erase(nodeToBeDel->key);
                delete nodeToBeDel; // Free memory
            }
        }
    }

private:
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    // Move a node to the head of the linked list
    void moveNodeToHead(Node* node) {
        if (node == head) {
            return; // Node is already at the head
        }
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */