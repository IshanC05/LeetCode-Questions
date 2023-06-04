class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), i = 0, j = n - 1;
        while(i < j){
            int curr = numbers[i] + numbers[j];
            if(curr == target){
                return {i + 1, j + 1};
            }else if(curr < target){
                ++i;
            }else{
                --j;
            }
        }
        return {-1, -1};
    }
};