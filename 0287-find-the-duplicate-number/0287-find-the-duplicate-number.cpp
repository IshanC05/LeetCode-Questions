class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Same as Detect cycle in LinkedList - II         
        int slow = nums[0];
        int fast = nums[0];
        
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(slow == fast)    break;
        }
        
        slow = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;        
    }
};