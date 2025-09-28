/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newArray = []
    arr.forEach((item, index) => {
        if (fn(item, index)) {
            newArray.push(item)
        }
    })
    return newArray
};

function greaterThan10(n) { return n > 10; }
function firstIndex(n, i) { return i === 0; }
function plusOne(n) { return n + 1 }

let arr = [10, 20, 30]
let arr1 = [1,2,3]
let arr2 = [-2,-1,0,1,2]

const newArray = filter(arr, greaterThan10); // [20, 30]
const newArray1 = filter(arr1, firstIndex); 
const newArray2 = filter(arr2, plusOne); 


console.log(newArray);
console.log(newArray1);
console.log(newArray2);