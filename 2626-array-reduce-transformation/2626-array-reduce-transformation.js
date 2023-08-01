/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    if(nums.length == 0)    return init;
    
    // return nums.reduce(fn, init);
    
    let start = init;
    
    for(let i = 0; i < nums.length; i++){
        
        let temp = fn(start, nums[i]);
        
        start = temp;
        
    }
    
    return start;
    
};