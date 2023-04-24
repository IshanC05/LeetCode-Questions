class Solution {
public:
    void merge(vector<int>& arr, int s1, int e1, int s2, int e2){
        vector<int>temp;
        int i = s1, j = s2;
        while(i <= e1 and j <= e2){
            if(arr[i] > arr[j]){
                temp.push_back(arr[j++]);
            }else{
                temp.push_back(arr[i++]);
            }
        }
        while(i <= e1){
            temp.push_back(arr[i++]);
        }
        while(j <= e2){
            temp.push_back(arr[j++]);
        }
        int n = temp.size(), k = s1;
        for(int x : temp){
            arr[k++] = x;
        }
        return;
    }
    void mergeSort(vector<int>& arr, int l, int r){
        if(l >= r){
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, mid + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};