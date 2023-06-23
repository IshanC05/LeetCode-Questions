class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size();
        vector<int>ans(m + n, 0);
        int k = 0;
        int i = 0, j = 0;
        
        while(i < m and j < n){
            if(nums1[i] < nums2[j]){
                ans[k++] = nums1[i++];
            }else{
                ans[k++] = nums2[j++];
            }
        }
        
        while(i < m){
            ans[k++] = nums1[i++];
        }
        
        while(j < n){
            ans[k++] = nums2[j++];
        }
        int mid = (m + n) / 2;
        if((m + n) % 2 == 0){
            return (ans[mid] + ans[mid - 1]) / 2.0;
        }
        return ans[(m + n) / 2];
    }
};