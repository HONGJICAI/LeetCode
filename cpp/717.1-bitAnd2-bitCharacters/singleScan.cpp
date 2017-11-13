class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();)
            if(bits[i]==0)
                if(i==bits.size()-1)
                    return true;
                else
                    ++i;
            else
                i+=2;
        return false;
    }
};
