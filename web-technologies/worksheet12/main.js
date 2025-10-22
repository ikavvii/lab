let questions = []

class Student {
  #name
  #age
  #marks
  constructor (name, age, marks) {
    this.#name = name
    this.#age = age
    this.#marks = marks
  }

  get studentInfo () {
    return {
      name: this.#name,
      age: this.#age,
      marks: this.#marks
    }
  }

  get marks () {
    return this.#marks
  }

  static averageMarks (students) {
    const totalMarks = students.reduce(
      (total, student) => total + student.marks,
      0
    )
    return totalMarks / students.length
  }

  static highScorers (students, threshold = 90) {
    return students.filter(student => student.marks >= threshold)
  }

  static maxMarks (students) {
    return Math.max(...students.map(student => student.marks))
  }

  static sortStudentsByMarks (students) {
    return [...students].sort((a, b) => b.marks - a.marks)
  }
}

let students = Array.of(
  new Student('Kavin', 23, 19),
  new Student('Arjuna', 22, 40),
  new Student('Ram', 24, 43)
)

questions.push({
  id: 1,
  title: 'Create and Display Student Records',
  description:
    'Create a Student class with properties: name, age, and marks.  Create an array of 3 student objects and display their details using forEach(). Use a constructor to initialize properties and print data using template literals.'
})

const question1 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Create and Display Student Records
  students.forEach(student => {
    output.innerHTML += JSON.stringify(student.studentInfo, null, 2)
  })
}

students.push(new Student('John', 21, 90), new Student('Doe', 22, 95))

questions.push({
  id: 2,
  title: 'Calculate Average Marks',
  description:
    'Using the same Student class, store 5 student objects in an array. Write a function to calculate and display the average marks of all students. Use a loop or reduce() to compute the total marks, then divide by the array length.'
})

const question2 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Calculate Average Marks
  const average = Student.averageMarks(students)
  output.innerHTML = `Average Marks: ${average}`
}

questions.push({
  id: 3,
  title: 'Filter High Scorers',
  description:
    'Filter and display students whose marks are greater than 90.  Use the filter() method on the array of objects and display using forEach().'
})

const question3 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Filter High Scorers
  const highScorers = Student.highScorers(students, 90)

  highScorers.forEach(student => {
    output.innerHTML += JSON.stringify(student.studentInfo, null, 2)
  })
}

questions.push({
  id: 4,
  title: 'Find the Topper',
  description:
    'Find and display the student with the highest marks from the array.   Use reduce() or sort the array in descending order of marks.'
})
const question4 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Find the Topper
  const studentsSorted = Student.sortStudentsByMarks(students)

  const maxMarks = Student.maxMarks(students)
  studentsSorted.forEach(student => {
    if (student.marks === maxMarks) {
      output.innerHTML += `<mark>${JSON.stringify(
        student.studentInfo,
        null,
        2
      )}</mark>`
    } else {
      output.innerHTML += JSON.stringify(student.studentInfo, null, 2)
    }
  })
}

class Employee {
  constructor (id, name, salary) {
    this.id = id
    this.name = name
    this.salary = salary
  }
}

let employees = Array.of(
  new Employee(1, 'Alice', 50000),
  new Employee(2, 'Bob', 60000),
  new Employee(3, 'Charlie', 70000)
)

questions.push({
  id: 5,
  title: 'Add New Property Dynamically',
  description:
    'Create an array of Employee objects with properties: id, name, salary.  Later, add a new property department to all objects and display them. Use forEach() to add a new property to each object in the array'
})
const question5 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  employees.forEach(employee => {
    employee.department = 'Engineering' // Dynamically adding a new property
    output.innerHTML += JSON.stringify(employee, null, 2)
  })
}

class Book {
  constructor (title, author, price) {
    this.title = title
    this.author = author
    this.price = price
  }

  updatePrice (newPrice) {
    this.price = newPrice
  }
}

const books = Array.of(
  new Book('Web Development', 'Shairaaj', 49.99),
  new Book('Data Structures', 'Kavin', 29.99),
  new Book('Algorithms', 'Kartheeswaran', 39.99)
)

questions.push({
  id: 6,
  title: 'Sorting Objects',
  description:
    'Sort an array of Book objects based on the price property (low to high).  Use the sort() method with a comparison function like (a, b) => a.price - b.price.'
})

const question6 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Sorting Objects by Price
  const sortedBooks = [...books].sort((a, b) => a.price - b.price)
  output.innerHTML = JSON.stringify(sortedBooks, null, 2)
}

// Class with Method to Calculate Discounted Price
class Product {
  constructor (name, price) {
    this.name = name
    this.price = price
  }
  getDiscountedPrice (rateOfDiscount) {
    return {
      name: this.name,
      originalPrice: this.price,
      discountedPrice: this.price - (this.price * rateOfDiscount) / 100
    }
  }
}

const products = Array.of(
  new Product('Laptop', 1000),
  new Product('Smartphone', 500),
  new Product('Tablet', 300)
)

questions.push({
  id: 7,
  title: 'Class with Method',
  description:
    'Define a class Product with name, price, and a method getDiscountedPrice(rateOfDiscount) that returns the price after applying the given discount. '
})
const question7 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  products.forEach(product => {
    const discountedPrice = product.getDiscountedPrice(10) // 10% discount
    output.innerHTML += JSON.stringify(discountedPrice, null, 2)
  })
}

questions.push({
  id: 8,
  title: 'Update Specific Object',
  description:
    'Given an array of Book objects, write code to update the price of a specific book   (based on the title). Use find() or for...of to locate the matching object and then modify its property.'
})

const question8 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  books.find(book => {
    if (book.title === 'Data Structures') {
      output.innerHTML = 'Before Price Update:\n'
      output.innerHTML += JSON.stringify(book, null, 2)

      const price = Math.random() * (100 - 50) + 50 // price >= 50 and price < 100
      // Update Specific Object
      book.updatePrice(price.toFixed(2)) // Update price
    }
  })

  output.innerHTML += '\nAfter Price Update:\n'

  output.innerHTML += JSON.stringify(books, null, 2)
}

questions.push({
  id: 9,
  title: 'Remove an Object',
  description:
    'From an array of Student objects, remove the student with the lowest marks. Find the minimum marks, then use filter() to remove that student from the array'
})

const question9 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Remove an Object with Minimum Marks
  const minMarksStudent = Math.min(...students.map(student => student.marks))
  const filteredStudents = students.filter(student => {
    return student.marks !== minMarksStudent
  })
  filteredStudents.forEach(student => {
    output.innerHTML += JSON.stringify(student.studentInfo, null, 2)
  })
}

class Car {
  constructor (brand, model, price) {
    this.brand = brand
    this.model = model
    this.price = price
  }
}

const cars = Array.of(
  new Car('Toyota', 'Camry', 24),
  new Car('Honda', 'Accord', 26),
  new Car('Ford', 'Mustang', 30)
)

questions.push({
  id: 10,
  title: 'Display Custom Formatted Output',
  description:
    'Create a Car class with properties brand, model, and price. Store multiple cars in an array and print them in the following format: “The [brand] [model] costs ₹[price] lakh.”'
})

const question10 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  // Display Custom Formatted Output for Objects
  // Using Object Destructuring
  for (const car of cars) {
    const { brand, model, price } = car
    output.innerHTML += `The ${brand} ${model} costs &#x20B9;${price} lakhs.\n`
  }
}

rawArray = [
  ['Alice', 23, 85],
  ['Bob', 22, 92],
  ['Charlie', 24, 78]
]

// students.push(...rawArray.map(data => new Student(...data)))

// Using Array.from with mapping function
students.push(
  ...Array.from(rawArray, ([name, age, marks]) => new Student(name, age, marks))
)

questions.push({
  id: 11,
  title: 'Use of Array.from()',
  description:
    'Given an array of raw data (arrays of [name, age, marks]),  convert it into an array of Student objects using Array.from().'
})

const question11 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  students.forEach(student => {
    output.innerHTML += JSON.stringify(student.studentInfo, null, 2)
  })
}

const employeesArray = [
  [4, 'David', 80000],
  [5, 'Eva', 90000],
  [6, 'Frank', 75000]
]

// Use of Index Assignment (No Push) to Add Objects to an Array
// Using for..of Loop with Destructuring
for (const [id, name, salary] of employeesArray) {
  employees[employees.length] = new Employee(id, name, salary)
}

questions.push({
  id: 12,
  title: 'Use of Index Assignment (No Push)',
  description:
    'Create an array of Employee objects using direct index assignments  instead of the push() method.'
})
const question12 = () => {
  const output = document.getElementById('output')

  output.innerHTML = ''

  output.innerHTML = JSON.stringify(employees, null, 2)
}

class Library {
  ArrayOfBooks = [] // Book objects

  addBook (book) {
    this.ArrayOfBooks.push(book)
  }
  get listBooks () {
    return this.ArrayOfBooks
  }
  findBookByTitle (title) {
    return this.ArrayOfBooks.find(book => book.title === title)
  }
}

const question13 = () => {
  const output = document.getElementById('output')
  output.innerHTML = ''

  const library = new Library()
  books.forEach(book => library.addBook(book))

  output.innerHTML += 'All Books in Library:\n'
  output.innerHTML += JSON.stringify(library.listBooks, null, 2)

  const searchTitle = 'Algorithms'
  const foundBook = library.findBookByTitle(searchTitle)
  output.innerHTML += `\n\nSearching for Book with Title "${searchTitle}":\n`
  output.innerHTML += JSON.stringify(foundBook, null, 2)
}
