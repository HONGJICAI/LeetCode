class Solution { // 0ms
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(),stones.end());
        while(stones.size()>1){
            int a=stones[0];
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            int b=stones[0];
            pop_heap(stones.begin(),stones.end());
            // stones.pop_back();
            // stones.push_back(a-b);
            stones[stones.size()-1]=a-b;
            push_heap(stones.begin(),stones.end());
        }
        return stones[0];
    }
};