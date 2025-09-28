/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newArray = []
    
    for (let i = 0; i < arr.length; i++) {
        newArray.push(fn(arr[i], i))
    }
    return newArray
};

let arr = [1,2,3]

function plusone(n) { return n + 1; }
function plusI(n, i) { return n + i; }

const newArray = map(arr, plusone)
const newArray1 = map(arr, plusI)

console.log(newArray);
console.log(newArray1);
