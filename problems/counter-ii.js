/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let curr = init
    return {
        increment: () => {
            return ++curr;
        },
        decrement: () => {
            return --curr;
        },
        reset: () => {
            curr = init
            return curr
        }
    }
};


const counter = createCounter(5)
console.log(counter.increment()); // 6
console.log(counter.reset()); // 5
console.log(counter.decrement()); // 4