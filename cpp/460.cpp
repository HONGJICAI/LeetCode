class LFUCache {
  // Runtime: 108 ms, faster than 97.00% of C++ online submissions for LFU
  // Cache. Memory Usage: 40.3 MB, less than 75.85% of C++ online submissions
  // for LFU Cache.
  int cap;
  int minFreq;
  using L = list<tuple<int, int, int>>; // k,v,count
  unordered_map<int, L> count2kv;
  unordered_map<int, L::iterator> hashmap;

public:
  LFUCache(int capacity) : cap(capacity), minFreq(0) {}

  int get(int key) {
    auto it = hashmap.find(key);
    if (it == end(hashmap))
      return -1;
    auto [k, v, c] = *it->second;
    {
      auto &target = count2kv[c];
      target.erase(it->second);
      if (target.size() == 0 and minFreq == c)
        ++minFreq;
    }
    {
      auto &target = count2kv[c + 1];
      target.emplace_front(k, v, c + 1);
      it->second = target.begin();
    }
    return v;
  }

  void put(int key, int value) {
    if (cap == 0)
      return;
    auto it = hashmap.find(key);
    if (it == end(hashmap)) {
      if (hashmap.size() >= cap) {
        auto &target = count2kv[minFreq];
        auto [k, v, c] = target.back();
        hashmap.erase(k);
        target.pop_back();
      }
      auto &target = count2kv[1];
      target.emplace_front(key, value, 1);
      hashmap[key] = target.begin();
      minFreq = 1;
    } else {
      auto [k, v, c] = *it->second;
      {
        auto &target = count2kv[c];
        target.erase(it->second);
        if (target.size() == 0 and minFreq == c)
          ++minFreq;
      }
      {
        auto &target = count2kv[c + 1];
        target.emplace_front(key, value, c + 1);
        it->second = target.begin();
      }
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */