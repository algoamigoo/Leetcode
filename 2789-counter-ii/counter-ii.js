/**
 * @param {number} init
 * @return {{ increment: Function, decrement: Function, reset: Function }}
 */
var createCounter = function(init) {
    let curr = init;

    return {
        increment: function() {
            return ++curr;
        },
        decrement: function() {
            return --curr;
        },
        reset: function() {
            curr = init;
            return curr;
        }
    };
};

/**
 * Example usage:
 * const counter = createCounter(5);
 * console.log(counter.increment()); // 6
 * console.log(counter.reset());     // 5
 * console.log(counter.decrement()); // 4
 */
