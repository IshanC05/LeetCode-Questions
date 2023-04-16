class Solution {
public:
    vector<int> merge2Arrays(vector<int>n1, vector<int>n2){
        vector<int>ans(n1.size() + n2.size());
        int m=n1.size(), n = n2.size();
        int i=0,j=0,k=0;
        while(i < m and j < n){
            if(n1[i] > n2[j]){
                ans[k] = n2[j];
                ++j;
            }else{
                ans[k] = n1[i];
                ++i;
            }
            ++k;
        }
        while(i < m){
            ans[k++] = n1[i++];
        }
        while(j < n){
            ans[k++] = n2[j++];
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mergedArr = merge2Arrays(nums1, nums2);
        int d = mergedArr.size();
        if(d & 1){
            return mergedArr[d / 2];
        }
        return ((mergedArr[d / 2] + mergedArr[(d / 2) - 1]) / 2.0);
    }
};