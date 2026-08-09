class Node {
public:
    shared_ptr<Node> next;
    weak_ptr<Node> prev;
    int key, val;

    Node(int k, int v) : key(k), val(v), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, shared_ptr<Node>> cache;
    int capacity;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    void remove(shared_ptr<Node> node) {
        auto prev_node = node->prev.lock();
        auto next_node = node->next;

        if (prev_node) {
            prev_node->next = next_node;
        } else {
            head = next_node;
        }

        if (next_node) {
            next_node->prev = prev_node;
        } else {
            tail = prev_node;
        }

        node->next = nullptr;
        node->prev.reset();
    }

    void insert(shared_ptr<Node> node) {
        if (!head) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        int val = -1;
        if (cache.count(key)) {
            val = cache[key]->val;
            remove(cache[key]);
            insert(cache[key]);
        }
        return val;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            cache[key]->val = value;
        } else {
            cache[key] = make_shared<Node>(key, value);
            insert(cache[key]);
            if (cache.size() > capacity) {
                cache.erase(tail->key);
                remove(tail);
            }
        }
    }
};
