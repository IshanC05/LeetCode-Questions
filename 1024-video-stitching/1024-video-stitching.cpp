class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int min = 0, max = 0, total = 0;
        
        while(max < time){
            
            for(int i = 0; i < clips.size(); i++){
             
                int l = clips[i][0], r = clips[i][1];

                if(l <= min && r > max){

                    max = r;

                }
                
            }
            
            if(min == max)  return -1;
            
            min = max;
            
            ++total;
            
        }
        
        return total;
        
    }
};