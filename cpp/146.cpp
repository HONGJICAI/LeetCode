// list_hashmap_82msBeat97%.cpp
class LRUCache {
  unsigned int capacity;
  list<pair<int, int>> timeList;
  unordered_map<int, list<pair<int, int>>::iterator>
      hashmap; // key cache's key,value cache's value's pointer
public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto it = hashmap.find(key);
    if (it == hashmap.end())
      return -1;
    timeList.push_back(make_pair(key, (*it->second).second));
    timeList.erase(it->second);
    it->second = --timeList.end();
    return (*it->second).second;
  }

  void put(int key, int value) {
    auto it = hashmap.find(key);
    if (it == hashmap.end()) {
      timeList.push_back(make_pair(key, value));
      hashmap[key] = --timeList.end();
      if (hashmap.size() > capacity) {
        hashmap.erase(timeList.begin()->first);
        timeList.pop_front();
      }
    } else {
      timeList.erase(it->second);
      timeList.push_back(make_pair(key, value));
      it->second = --timeList.end();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// map_hashmap_103ms.cpp
class LRUCache2 {
  unsigned int capacity;
  map<int, int> timemap; // key time,value cache's key
  unordered_map<int, pair<int, int>>
      hashmap; // key cache's key,value cache's value and time
  unsigned int call;

public:
  LRUCache2(int capacity) {
    this->capacity = capacity;
    call = 0;
  }

  int get(int key) {
    auto it = hashmap.find(key);
    if (it == hashmap.end())
      return -1;
    timemap[call] = key;
    int oldTime = hashmap[key].second;
    hashmap[key].second = call++;
    timemap.erase(oldTime);
    return it->second.first;
  }

  void put(int key, int value) {
    auto it = hashmap.find(key);
    if (it == hashmap.end()) {
      timemap[call] = key;
      hashmap[key] = make_pair(value, call++);
      if (hashmap.size() > capacity) {
        int erasedKey = timemap.begin()->second;
        timemap.erase(timemap.begin());
        hashmap.erase(erasedKey);
      }
    } else {
      timemap[call] = key;
      int oldTime = hashmap[key].second;
      hashmap[key] = make_pair(value, call++);
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
