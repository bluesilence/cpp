class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheHistory.splice(cacheHistory.begin(), cacheHistory, cacheMap[key]);
            
            return cacheMap[key]->second;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) {
            if (cacheHistory.size() == capacity) {
                int oldestKey = cacheHistory.back().first;
                cacheMap.erase(oldestKey);
                cacheHistory.pop_back();
            }
        
            cacheHistory.push_front(make_pair(key, value));
            cacheMap[key] = cacheHistory.begin();
        } else {
            cacheMap[key]->second = value;
            cacheHistory.splice(cacheHistory.begin(), cacheHistory, cacheMap[key]);
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    
    list<pair<int, int>> cacheHistory;
    
    int capacity;
};
