class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int size = flowerbed.size(), i = 0;
        
        while(i < size){
            
            if(flowerbed[i] == 0){
                
                bool emptyLeft = (i == 0) || flowerbed[i - 1] == 0;
                bool emptyRight = (i == size - 1) || flowerbed[i + 1] == 0;
                
                if(emptyLeft && emptyRight){
                    
                    flowerbed[i] = 1;
                    --n;
                    
                }
                
            }
            
            ++i;
            
        }
        
        return n <= 0;
        
    }
};