class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node* front;
    Node* back;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* next = back->next;
        node->next = next;
        next->prev = node;
        back->next = node;
        node->prev = back;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        back = new Node(-1, -1);
        front = new Node(-1, -1);
        back->next = front;
        front->prev = back;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if (cache.size() > cap) {
            Node* rem = front->prev;
            remove(rem);
            cache.erase(rem->key);
            delete rem;
        }
    }
};
