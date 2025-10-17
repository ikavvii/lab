/**
 * 
//1. Object Literal method
Student = {
  name: "KK",
  age: 21,
  course: "MCA",
  displayInfo() {
    console.log(`${this.name} is studying ${this.course}`);
  },
};
Student.displayInfo();

//2. using the new Object Constructor
student1 = new Object();
student1.name = "Arun";
student1.age = 22;
student1.course = "MCA";
student1.display = function () {
  console.log(`${this.name} is studying ${this.course}`);
};
student1.display();
*/


//3. using a constructor function
function Students(name, age, course) {
  this.name = name;
  this.age = age;
  this.course = course;
  this.displayInfo = function () {
    console.log(`${this.name} is ${this.age} and studies ${this.course}`);
  };
}
s1 = new Students("KK", 21, "ME");
s2 = new Students("Arun", 22, "MCA");
s1.displayInfo();
/**

//4.Object Creation using Prototype based
personPrototype = {
  greet() {
    console.log(`Hello, I’m ${this.name} `);
  },
};
student2 = Object.create(personPrototype);
student2.name = "KK";
student2.greet(); // Hello, I’m KK
// student2.city="vnr";
// console.log(student2.city);

// 5. Using Factory Functions
function createStudent(name, age, course) {
  return {
    name,
    age,
    course,
    displayInfo() {
      console.log(`${this.name} is studying ${this.course}`);
    },
  };
}
const ss1 = createStudent("KK", 21, "MTech");
const ss2 = createStudent("Arun", 22, "MCA");
s1.displayInfo();

//6. Using JSON
jsonData = '{"name": "KK", "age": 21, "course": "BCA"}';
Sstudent = JSON.parse(jsonData); // Converts string → object
console.log(Sstudent.name); // KK

//7. Using class Syntax from ES6  ECMA 2015
class Studentss {
  constructor(name, age, course) {
    this.name = name;
    this.age = age;
    this.course = course;
  }
  displayInfo() {
    console.log(`${this.name} is studying ${this.course}`);
  }
}
ss11 = new Studentss("KK", 21, "MBA");
ss21 = new Studentss("Arun", 22, "MCA");
ss1.displayInfo();
ss2.displayInfo();

//8. For creating Singleton Object.
const currentStudents = (function () {
  // Private variables inside closure
  let batch = "25MX";
  let graduateAt;
  // Public interface (Singleton object)
  return {
    getBatch() {
      return batch;
    },
    getSetting() {
      return graduateAt;
    },
    setSetting(v) {
      graduateAt = v;
    },
  };
})();
// Use the Singleton
currentStudents.setSetting(2027);
console.log(
  `${currentStudents.getBatch()} will graduate at ${currentStudents.getSetting()}`
);
 * 
 */
