let power = (exp) => (num) => num ** exp;
let square = power(2);
let cube = power(3);
console.log(square(5));
console.log(cube(2));