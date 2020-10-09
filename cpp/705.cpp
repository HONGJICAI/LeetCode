class MyHashSet {
  vector<set<int>> m_buf = vector<set<int>>(2);
  int m_totalSize = 0;
  const int expandRatio = 2;
  int hashCode(int val, bool rebuild = false) {
    return val % (rebuild ? m_buf.size() * expandRatio : m_buf.size());
  }
  void tryRebuild() {
    if (m_totalSize < m_buf.size() * expandRatio * expandRatio)
      return;
    m_totalSize = 0;
    vector<set<int>> new_buf(m_buf.size() * expandRatio);
    for (auto &m : m_buf) {
      for (auto &k : m) {
        auto &m = new_buf[hashCode(k, true)];
        m.insert(k);
        ++m_totalSize;
      }
    }
    m_buf = move(new_buf);
  }

public:
  /** Initialize your data structure here. */
  MyHashSet() {}

  void add(int key) {
    // tryRebuild();
    auto &m = m_buf[hashCode(key)];
    if (auto it = m.find(key); it == m.end()) {
      m.insert(key);
      ++m_totalSize;
    }
  }

  void remove(int key) {
    auto &m = m_buf[hashCode(key)];
    if (auto it = m.find(key); it != m.end()) {
      m.erase(it);
      --m_totalSize;
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    auto &m = m_buf[hashCode(key)];
    return m.find(key) != m.end();
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */