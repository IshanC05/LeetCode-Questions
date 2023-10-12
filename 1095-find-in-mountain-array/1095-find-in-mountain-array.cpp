/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &a, int l, int h){
        
        int peak = -1;
        
        while(l <= h){
            
            int m = l + (h - l) / 2;
            
            int mv = a.get(m);
            
            if(mv > a.get(m + 1)){
                
                if(mv > a.get(m - 1)){
                    
                    return m;
                }
                
                else    h = m - 1;
            }
            
            else    l = m + 1;
            
        }
        
        return peak;
    }
    
    int bSearch(MountainArray &a, int l, int h, int target){
        
        while(l <= h){
            
            int m = l + (h - l) / 2;
            
            int mv = a.get(m);
            
            if(mv == target)    return m;
            
            else if(mv > target)    h = m - 1;
            
            else    l = m + 1;            
        }
        
        return -1;        
    }
    
    int bSearchReverse(MountainArray &a, int l, int h, int target){
        
        while(l <= h){
            
            int m = l + (h - l) / 2;
            
            int mv = a.get(m);
            
            if(mv == target)    return m;
            
            else if(mv > target)    l = m + 1;
            
            else    h = m - 1;            
        }
        
        return -1;        
    }
    
    int findInMountainArray(int target, MountainArray &a) {
        
        int l = 0, h = a.length() - 1, peak;
        
        // find peak Index
        peak = findPeak(a, l, h);
        
        if(peak == -1)  return peak;
        
        // cout << peak << endl;
        
        int left = bSearch(a, l, peak, target);
        
        if(left != -1)  return left;
        
        return bSearchReverse(a, peak + 1, h, target);
    }
};