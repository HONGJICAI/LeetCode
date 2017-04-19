class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,result=0;
        while(i<j){
            result=result>min(height[i],height[j])*(j-i)?result:min(height[i],height[j])*(j-i);
            if(height[i]<height[j])
                ++i;
            else
                --j;
        }
        return result;
    }
};
