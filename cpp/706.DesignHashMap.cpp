class MyHashMap { //132ms 83.59%
    vector<map<int,int>>m_buf=vector<map<int,int>>(2);
    int m_totalSize=0;
    const int expandRatio=2;
    int hashCode(int val,bool rebuild=false){
        return val%(rebuild?m_buf.size()*expandRatio:m_buf.size());
    }
    void tryRebuild(){
        if(m_totalSize<m_buf.size()*expandRatio*expandRatio)
            return;
        m_totalSize=0;
        vector<map<int,int>>new_buf(m_buf.size()*expandRatio);
        for(auto &m:m_buf){
            for(auto &[k,v]:m){
                auto &m=new_buf[hashCode(k,true)];
                m[k]=v;
                ++m_totalSize;
            }
        }
        m_buf=move(new_buf);
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        //tryRebuild();
        auto &m=m_buf[hashCode(key)];
        if(auto it=m.find(key);it==m.end()){
            m[key]=value;
            ++m_totalSize;
        }
        else{
            it->second=value;
        }
            
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &m=m_buf[hashCode(key)];
        auto it=m.find(key);
        return it==m.end()?-1:it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &m=m_buf[hashCode(key)];
        if(auto it=m.find(key);it!=m.end()){
            m.erase(it);
            --m_totalSize;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */