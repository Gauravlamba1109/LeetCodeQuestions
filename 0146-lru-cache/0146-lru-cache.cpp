struct Node {
    int key, value;
    Node *next, *prev;
    Node(int key, int value){
        this->key = key;
        this->value = value;
    }
};
class LRUCache {
    int cap;
    unordered_map<int,Node*>m;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    void del(Node* todel){
        Node* prevn = todel->prev;
        Node* nextn = todel->next;
        prevn->next = nextn;
        nextn->prev = prevn;
    }

    // add to front 
    void add(Node* toadd){
        Node* prevn = head->prev;
        head->prev = toadd;
        toadd->next = head;
        toadd->prev = prevn;
        prevn->next = toadd;

    }
public:
    LRUCache(int capacity) {
        head->prev = tail;
        tail->next = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        del(m[key]);
        add(m[key]);
        return m[key]->value;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()){
            if(cap == m.size()){
                Node* lru = tail->next;
                del(lru);
                m.erase(lru->key);
                delete(lru);
            }
            Node* toput = new Node(key,value);
            add(toput);
            m[key] = toput;
        }
        else
        {
            Node* toput = m[key];
            del(toput);
            toput->value = value;
            add(toput);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */