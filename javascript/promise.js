let promise = new Promise(function(resolve, reject) {
    console.log(1);
    resolve(2)
    console.log(3);
});

promise.then((value) => {
    console.log(value); 
})

console.log(4);

// Output will be:
// 1
// 3
// 4
// 2

