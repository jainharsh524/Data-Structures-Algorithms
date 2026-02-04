class LRUCache {
    int cap;
    list<int> lru; // keeps order: front = most recent
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // move key to front (most recently used)
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        // if key already exists
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
        }
        // if cache is full
        else if (cache.size() == cap) {
            int lruKey = lru.back();
            lru.pop_back();
            cache.erase(lruKey);
        }

        // insert/update key
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
