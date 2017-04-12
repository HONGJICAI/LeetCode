class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> result(2);
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                result[0]=i+1;
                result[1]=j+1;
                break;
            }
            else if(numbers[i]+numbers[j]>target)
                j--;
            else
                i++;
        }
        return result;
    }
};
