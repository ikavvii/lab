// Program to demonstrate Array.from() for converting NodeList into Array
// This is useful when working with DOM elements and you need array methods

console.log("=== NodeList to Array Conversion using Array.from() ===\n");

// Example 1: Basic NodeList to Array conversion
console.log("1. Basic NodeList to Array conversion:");
console.log("   HTML: <div class='item'>Item 1</div>");
console.log("         <div class='item'>Item 2</div>");
console.log("         <div class='item'>Item 3</div>");
console.log("");

// Simulating a NodeList (since we're running in Node.js, not browser)
// In a real browser environment, this would be: document.querySelectorAll('.item')
const mockNodeList = {
    0: { textContent: 'Item 1', tagName: 'DIV' },
    1: { textContent: 'Item 2', tagName: 'DIV' },
    2: { textContent: 'Item 3', tagName: 'DIV' },
    length: 3,
    [Symbol.iterator]: function* () {
        for (let i = 0; i < this.length; i++) {
            yield this[i];
        }
    }
};

console.log("   NodeList (array-like object):", mockNodeList);
console.log("   NodeList has length:", mockNodeList.length);
console.log("   NodeList has map method:", typeof mockNodeList.map); // undefined

// Convert NodeList to Array using Array.from()
const elementsArray = Array.from(mockNodeList);
console.log("   Converted to Array:", elementsArray);
console.log("   Array has map method:", typeof elementsArray.map); // function
console.log("");

// Example 2: Using Array.from() with mapping function
console.log("2. Array.from() with mapping function:");
const textArray = Array.from(mockNodeList, element => element.textContent);
console.log("   Text content array:", textArray);
console.log("");

// Example 3: Demonstrating array methods after conversion
console.log("3. Using array methods after conversion:");

// Filter elements
const filteredElements = elementsArray.filter(el => el.textContent.includes('2'));
console.log("   Filtered elements (containing '2'):", filteredElements);

// Map to get text content
const textContents = elementsArray.map(el => el.textContent);
console.log("   Mapped text contents:", textContents);

// Find element
const foundElement = elementsArray.find(el => el.textContent === 'Item 2');
console.log("   Found element:", foundElement);

// ForEach iteration
console.log("   Iterating with forEach:");
elementsArray.forEach((el, index) => {
    console.log(`     Index ${index}: ${el.textContent}`);
});
console.log("");

// Example 4: Real-world scenario simulation
console.log("4. Real-world scenario - Processing form inputs:");

// Simulating form inputs NodeList
const mockInputs = {
    0: { type: 'text', name: 'username', value: 'john_doe' },
    1: { type: 'email', name: 'email', value: 'john@example.com' },
    2: { type: 'password', name: 'password', value: '********' },
    length: 3,
    [Symbol.iterator]: function* () {
        for (let i = 0; i < this.length; i++) {
            yield this[i];
        }
    }
};

console.log("   Original NodeList of form inputs:", mockInputs);

// Convert and process
const inputsArray = Array.from(mockInputs);
const formData = inputsArray.reduce((data, input) => {
    data[input.name] = input.value;
    return data;
}, {});

console.log("   Converted to form data object:", formData);
console.log("");

// Example 5: Array.from() vs Spread operator vs Array.prototype.slice.call()
console.log("5. Different methods to convert NodeList to Array:");

// Method 1: Array.from()
const method1 = Array.from(mockNodeList);
console.log("   Array.from():", method1.length, "elements");

// Method 2: Spread operator (also works)
const method2 = [...mockNodeList];
console.log("   Spread operator:", method2.length, "elements");

// Method 3: Array.prototype.slice.call() (older method)
const method3 = Array.prototype.slice.call(mockNodeList);
console.log("   Array.prototype.slice.call():", method3.length, "elements");

console.log("   All methods produce equivalent results:", 
    JSON.stringify(method1) === JSON.stringify(method2) && 
    JSON.stringify(method2) === JSON.stringify(method3));
console.log("");

// Example 6: Browser usage example (commented for Node.js environment)
console.log("6. Browser usage examples (as comments):");
console.log(`
   // In a real browser environment, you would use:
   
   // Get all paragraphs
   const paragraphs = document.querySelectorAll('p');
   const paragraphsArray = Array.from(paragraphs);
   
   // Get all buttons and add event listeners
   const buttons = document.querySelectorAll('button');
   Array.from(buttons).forEach(button => {
       button.addEventListener('click', handleClick);
   });
   
   // Get all input elements and validate
   const inputs = document.querySelectorAll('input[required]');
   const emptyInputs = Array.from(inputs).filter(input => !input.value);
   
   // Convert HTMLCollection to Array (similar to NodeList)
   const divs = document.getElementsByTagName('div');
   const divsArray = Array.from(divs);
`);

console.log("=== Summary ===");
console.log("Array.from() is the modern, clean way to convert NodeList to Array");
console.log("Benefits:");
console.log("- Clear and readable syntax");
console.log("- Supports optional mapping function");
console.log("- Works with any iterable or array-like object");
console.log("- Better performance than older methods");
console.log("- Part of ES6/ES2015 standard");