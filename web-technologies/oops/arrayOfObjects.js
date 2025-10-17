let students = [
  { name: "Kumar", age: 21, course: "ME", marks: 96 },
  { name: "Arun", age: 22, course: "MCA", marks: 96 },
  { name: "Divya", age: 20, course: "MTech", marks: 95 },
];
students.forEach((s) => console.log(s.name));

//using keyword class
class sStudent {
  constructor(name, age, marks) {
    this.name = name;
    this.age = age;
    this.marks = marks;
  }
}
let sstudentList = Array.of(
  new sStudent("KK", 22, 97),
  new sStudent("Arun", 23, 89),
  new sStudent("Divya", 21, 95)
);

sstudentList.forEach((s) => console.log(s.name));

let ssstudentList = [];
ssstudentList[0] = new sStudent("KK", 22, 97);
ssstudentList[1] = new sStudent("Arun", 23, 89);
ssstudentList[2] = new sStudent("Divya", 21, 95);

ssstudentList.forEach((s) => console.log(s.name));

class Student {
  constructor(name, age, marks) {
    this.name = name;
    this.age = age;
    this.marks = marks;
  }
}

let studentList = [];
studentList.push(new Student("Krish", 21, 85));
studentList.push(new Student("Anish", 22, 90));

studentList.forEach((s) => console.log(s.name));
