class AllOne {
    unordered_map<string, int> key2cnt;
    map<int, unordered_set<string>> cnt2keys;
public:
    AllOne() { }
    
    void inc(const string& key) {
        auto it = key2cnt.find(key);
        if (it == key2cnt.end()) {
            key2cnt[key] = 1;
            cnt2keys[1].insert(key);
        } else {
            cnt2keys[it->second + 1].insert(key);
            auto& origin = cnt2keys[it->second];
            origin.erase(key);
            if (origin.empty())
                cnt2keys.erase(it->second);
            ++it->second;
        }
    }
    
    void dec(const string& key) {
        auto it = key2cnt.find(key);
        if (it == key2cnt.end()) return;
        if (it->second - 1 == 0) {
            auto& origin = cnt2keys[1];
            origin.erase(key);
            if (origin.empty())
                cnt2keys.erase(1);
            key2cnt.erase(it);
        } else {
            cnt2keys[it->second - 1].insert(key);
            auto& origin = cnt2keys[it->second];
            origin.erase(key);
            if (origin.empty())
                cnt2keys.erase(it->second);
            --it->second;
        }
    }
    
    string getMaxKey() {
        if (key2cnt.empty()) return "";
        return *cnt2keys.rbegin()->second.begin();
    }
    
    string getMinKey() {
        if (key2cnt.empty()) return "";
        return *cnt2keys.begin()->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */