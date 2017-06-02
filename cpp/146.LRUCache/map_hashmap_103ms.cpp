class LRUCache {
    unsigned int capacity;
    map<int,int>timemap;//key time,value cache's key
    unordered_map<int,pair<int,int>>hashmap;//key cache's key,value cache's value and time
    unsigned int call;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        call=0;
    }
    
    int get(int key) {
        auto it=hashmap.find(key);
        if(it==hashmap.end())
            return -1;
        timemap[call]=key;
        int oldTime=hashmap[key].second;
        hashmap[key].second=call++;
        timemap.erase(oldTime);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it=hashmap.find(key);
        if(it==hashmap.end()){
            timemap[call]=key;
            hashmap[key]=make_pair(value,call++);
            if(hashmap.size()>capacity){
                int erasedKey=timemap.begin()->second;
                timemap.erase(timemap.begin());
                hashmap.erase(erasedKey);
            }
        }
        else{
            timemap[call]=key;
            int oldTime=hashmap[key].second;
            hashmap[key]=make_pair(value,call++);
            timemap.erase(oldTime);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
