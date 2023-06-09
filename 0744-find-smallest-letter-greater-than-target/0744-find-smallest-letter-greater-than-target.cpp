class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target >= letters[n - 1] || target < letters[0]){
            return letters[0];
        }
        int ans = 'Z';
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(letters[mid] <= target){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        
        return letters[l];
    }
};