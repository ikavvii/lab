class Stack {
  constructor(size) {
    this.size = size;
    this.items = new Array(size);
    this.top = -1;
  }

  isEmpty() {
    return this.top === -1;
  }

  isFull() {
    return this.top === this.size - 1;
  }

  push(element) {
    if (this.isFull()) {
      throw new Error("Stack Overflow");
    }
    this.items[++this.top] = element;
  }

  pop() {
    if (this.isEmpty()) {
      throw new Error("Stack Underflow");
    }
    return this.items[this.top--];
  }

  peek() {
    if (this.isEmpty()) {
      throw new Error("Stack is empty");
    }
    return this.items[this.top];
  }

  find(element) {
    let tempStack = new Stack(this.size);
    let foundAt = -1;

    while (!this.isEmpty()) {
      let current = this.pop();
      if (current === element && foundAt === -1) {
        foundAt = this.top + 1;
      }
    }

    // Restore the original stack
    while (!tempStack.isEmpty()) {
      this.push(tempStack.pop());
    }

    return {
      found: foundAt !== -1,
      value: foundAt !== -1 ? element : null,
      position: foundAt,
    };
  }

  length() {
    return this.top + 1;
  }
}
export default Stack;
