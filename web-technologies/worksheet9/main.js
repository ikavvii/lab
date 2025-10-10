let operationButtons = document.getElementById("operation-buttons");
let numberButtons = document.getElementById("number-buttons");
let textBox = document.getElementById("text-box");

const operations = ["+", "-", "*", "/", "^", "log10"];
let lastWasEqual = false;

operations.forEach((operation) => {
  let operationButton = document.createElement("button");
  operationButton.textContent = operation;
  operationButton.addEventListener("click", () => {
    // If last was equal and current is not log10, continue with result
    if (lastWasEqual && operation !== "log10") {
      lastWasEqual = false;
    }
    if (operation === "log10") {
      if (textBox.value !== "") {
        let num = Number(textBox.value);
        if (!isNaN(num)) {
          textBox.value = Math.log10(num);
          lastWasEqual = true;
        } else {
          textBox.value = "Error";
          lastWasEqual = true;
        }
      }
      return;
    } else {
      // Prevent two operators in a row
      if (textBox.value.length > 0) {
        let lastChar = textBox.value[textBox.value.length - 1];
        if ("+-*/^".includes(lastChar)) {
          textBox.value = textBox.value.slice(0, -1) + operation;
          return;
        }
        textBox.value += operation;
      }
    }
  });
  operationButtons.appendChild(operationButton);
});

for (let i = 0; i <= 9; i++) {
  let numberButton = document.createElement("button");
  numberButton.textContent = i;
  numberButton.addEventListener("click", () => {
    if (lastWasEqual) {
      textBox.value = "";
      lastWasEqual = false;
    }
    textBox.value += numberButton.textContent;
  });
  numberButtons.appendChild(numberButton);
}

let decimalButton = document.createElement("button");
decimalButton.textContent = ".";
decimalButton.addEventListener("click", () => {
  if (lastWasEqual) {
    textBox.value = "";
    lastWasEqual = false;
  }
  let parts = textBox.value.split(/[\+\-\*\/\^]/);
  let lastPart = parts[parts.length - 1];
  if (!lastPart.includes(".")) {
    textBox.value += ".";
  }
});
numberButtons.appendChild(decimalButton);

let equalButton = document.createElement("button");
equalButton.textContent = "=";
equalButton.addEventListener("click", evalTextInput);
operationButtons.appendChild(equalButton);

// Add Clear button
let clearButton = document.createElement("button");
clearButton.textContent = "C";
clearButton.addEventListener("click", () => {
  textBox.value = "";
  lastWasEqual = false;
});
operationButtons.appendChild(clearButton);

function evalTextInput() {
  let inputText = textBox.value;
  let result;
  try {
    inputText = inputText.replace(/\^/g, "**");
    result = eval(inputText);
    textBox.value = result;
    lastWasEqual = true;
  } catch (e) {
    textBox.value = "Error";
    lastWasEqual = true;
  }
}