class Node {
public:

int key;
int value;
Node* prev;
Node* next;
    
    Node(int k, int v){
      key = k;
      value = v;
      prev = NULL;
      next = NULL; 
    }
};

class LRUCache {
private:

int cap;
unordered_map<int, Node*> mp;
Node* head;
Node* tail;

public:

    LRUCache(int capacity) {
      cap = capacity;
      head = new Node(0, 0);
      tail = new Node(0, 0);

      head -> next = tail;
      tail -> prev = head;
    }

    void remove(Node* node){
        Node* p = node -> prev;
        Node* n = node -> next;

        p -> next = n;
        n -> prev = p;
    }

    void insertAtFront(Node* node){
        node -> next = head -> next;
        node -> prev = head;

        head -> next -> prev = node;
        head -> next = node;
    }
    
    int get(int key) {
       if(mp.find(key) == mp.end()) return -1;

       Node* node = mp[key];
       remove(node);
       insertAtFront(node);

       return node -> value;
    }
    
    void put(int key, int value) {
       if(mp.find(key) != mp.end()){
        Node* node = mp[key];
        node -> value = value;

        remove(node);
        insertAtFront(node);
       }

       else{
        // No capacity
        if(mp.size() == cap){
            Node* lru = tail -> prev;
            mp.erase(lru -> key);
            remove(lru);
            delete(lru);
        }

        Node* newNode = new Node(key, value);
        insertAtFront(newNode);
        mp[key] = newNode;
       }
    }
};
