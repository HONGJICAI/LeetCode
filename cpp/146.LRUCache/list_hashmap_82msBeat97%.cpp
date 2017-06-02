class LRUCache {
    unsigned int capacity;
    list< pair<int,int> >timeList;
    unordered_map<int,list<pair<int,int>>::iterator>hashmap;//key cache's key,value cache's value's pointer
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        auto it=hashmap.find(key);
        if(it==hashmap.end())
            return -1;
        timeList.push_back(make_pair(key,(*it->second).second));
        timeList.erase(it->second);
        it->second=--timeList.end();
        return (*it->second).second;
    }
    
    void put(int key, int value) {
        auto it=hashmap.find(key);
        if(it==hashmap.end()){
            timeList.push_back(make_pair(key,value));
            hashmap[key]=--timeList.end();
            if(hashmap.size()>capacity){
                hashmap.erase(timeList.begin()->first);
                timeList.pop_front();
            }
        }
        else{
            timeList.erase(it->second);
            timeList.push_back(make_pair(key,value));
            it->second=--timeList.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
