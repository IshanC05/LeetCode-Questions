/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var r;

var createCounter = function(init) {
    
    r = init;
    
    return {
        
        increment : () => ++init,
        
        decrement : () => --init,
        
        reset: () => {
            
            init = r;
            
            return init;
        }
        
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */