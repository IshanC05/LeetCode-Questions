class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int A = 0, B = 0;

        for(int num : nums){
            
            if(num > A){
                
                B = A;
                
                A = num;
                
            }
            
            else if(num > B)    B = num;
            
        }
        
        return (A - 1) * (B - 1);
        
    }
};