class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            items.splice(items.begin(), items, cache[key]);
            
            return cache[key]->second;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() == capacity) { //Delete least recent used key
                cache.erase(items.back().first);
                items.pop_back();
            }
            
            items.push_front(make_pair(key, value));
            cache[key] = items.begin();
        } else {
            cache[key]->second = value;
            items.splice(items.begin(), items, cache[key]);
        }
    }

private:
    list<pair<int, int>> items;
    
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    
    int capacity;
};
