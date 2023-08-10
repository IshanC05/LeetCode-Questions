class Solution {
public:
    
    void heapify(vector<int>&arr, int n, int i){
        
        int largest = i;
        
        int lChild = 2*i + 1;
        
        int rChild = 2*i + 2;
        
        if(lChild < n && arr[lChild] > arr[largest])    largest = lChild;
        
        if(rChild < n && arr[rChild] > arr[largest])    largest = rChild;
        
        if(largest != i){
            
            swap(arr[largest], arr[i]);
            
            heapify(arr, n, largest);
            
        }
        
    }
    
    void buildHeap(vector<int>&arr, int n){
        
        for(int i = n / 2 - 1; i >= 0; i--){
            
            heapify(arr, n, i);
            
        }
        
    }
    
    void heapSort(vector<int>&arr){
        
        int n = arr.size();
        
        if(n <= 1) return;
        
        buildHeap(arr, n);
        
        for(int i = n - 1; i >= 0; i--){
            
            swap(arr[0], arr[i]);
            
            heapify(arr, i, 0);
            
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        heapSort(nums);
        
        return nums;
        
    }
};