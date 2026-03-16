struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int value){
        key = k;
        val = value;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* nd){
        Node* pre = nd->prev;
        Node* nex = nd->next;
        pre->next = nex;
        nex->prev = pre;
    }

    void insertAfterHead(Node* nd){
        Node* nex = head->next;
        head->next = nd;
        nd->prev = head;
        nd->next = nex;
        nex->prev = nd;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        else{
            Node* nd = mp[key];
            deleteNode(nd);
            insertAfterHead(nd);
            return nd->val;
        }
    }

    void put(int key, int value) {
        if(mp.count(key)>0){
            Node *nd = mp[key];
            nd->val = value;
            deleteNode(nd);
            insertAfterHead(nd);
        }
        else{
            if(mp.size()==cap){
                Node* nd = tail->prev;
                mp.erase(nd->key);
                deleteNode(nd);
                // delete nd;
            }
            Node* nd = new Node(key, value);
            mp[key]= nd;
            insertAfterHead(nd);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
