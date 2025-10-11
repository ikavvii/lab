
// Notice that index 2 is skipped, since there is no item at
// that position in the array.
[2, 5, , 9].forEach(logArrayElements);

//  Printing the array elements
const logArrayElements = (element, index /*, array */) => {
  console.log(`a[${index}] = ${element}`);
};
