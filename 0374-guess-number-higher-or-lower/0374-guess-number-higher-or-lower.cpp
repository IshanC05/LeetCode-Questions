/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int l = 1, h = n, mid;
        
        while(true){
            
            mid = l + (h - l) / 2;
            
            int out = guess(mid);
            
            if(out == 0) break;
            
            else if(out == -1)  h = mid - 1;
            
            else l = mid + 1;
            
        }
        
        return mid;
        
    }
};