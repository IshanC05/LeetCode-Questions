class Solution {
public:
    int findIdx(vector<int>&arr){
        int l = 0, h = arr.size() - 1, curr = -1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(arr[mid] < 0){
                curr = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return curr;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        for(int r = 0; r < m; r++){
            int n = grid[r].size();
            int curr = findIdx(grid[r]);
            if(curr == -1){
                continue;
            }else{
                count += n - curr;
            }
        }
        return count;
    }
};