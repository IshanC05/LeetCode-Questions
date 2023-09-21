class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>arr;
        
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        
        while(true){
            
            int prevSize = arr.size();
            
            if(i < m)    arr.push_back(nums1[i++]);
            
            if(j < n)    arr.push_back(nums2[j++]);
            
            if(prevSize == arr.size())  break;            
        }
        
        sort(arr.begin(), arr.end());
        
        int mid = arr.size() / 2;
        
        if(arr.size() % 2)  return arr[mid];
        
        return (arr[mid] + arr[mid - 1]) / 2.0;
    }
};