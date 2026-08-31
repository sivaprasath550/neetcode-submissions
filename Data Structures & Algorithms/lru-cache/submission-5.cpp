class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the linked list
    void remove(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Add a node just before tail
    // This means it becomes Most Recently Used
    void addToMRU(Node* node) {

        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // This node was just used,
        // so move it to MRU position
        remove(node);
        addToMRU(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Move it to MRU
            remove(node);
            addToMRU(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        addToMRU(node);

        // Cache exceeded capacity
        if (mp.size() > capacity) {

            // Least Recently Used node
            Node* lru = head->next;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};
