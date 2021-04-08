class OrderedListOfCache {
    
private:
    
    struct Node {
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    
    unordered_map<int, Node*> umap;
    Node* head;
    Node* tail;
    
public:
    
    OrderedListOfCache() : head(nullptr), tail(nullptr) {}
    
    ~OrderedListOfCache() {
        while(head) {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }
    
    void moveToFront(int val) {
        Node* cur = umap[val];
        if(head == cur) {
            return;
        } else if(tail == cur) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->prev = nullptr;
        }
        cur->next = head;
        head->prev = cur;
        head = cur;
    }
    
    void addElementToFront(int val) {
        Node* n = new Node{val};
        umap[val] = n;
        if(!head) {
            tail = n;
        } else {
            head->prev = n;
            n->next = head;
        }
        head = n;
    }
    
    void removeElementFromBack() {
        umap.erase(tail->val);
        Node* n = tail;
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete n;
    }
    
    int front() {
        return head->val;
    }
    
    int back() {
        return tail->val;
    }
};

class LRUCache {
    
private:
    
    unordered_map<int, int> cache;
    OrderedListOfCache list;
    int currentSize;
    int capacity;
    
public:
    
    LRUCache(int capacity) : currentSize(0), capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        list.moveToFront(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            list.moveToFront(key);
        } else if(currentSize < capacity) {
            list.addElementToFront(key);
            ++currentSize;
        } else {
            int LRUKey = list.back();
            list.removeElementFromBack();
            cache.erase(LRUKey);
            list.addElementToFront(key);
        }
        cache[key] = value;
    }
};