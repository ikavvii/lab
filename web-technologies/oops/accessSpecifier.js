class Student {
  #aadhar;
  constructor(name, age, course, aadhar) {
    this.name = name;
    this.age = age;
    this.course = course;
    this.#aadhar = aadhar;
  }
  displayInfo() {
    console.log(
      `${this.name} is studying ${this.course} and aadhar is ${this.#aadhar}`
    );
  }
}
s1 = new Student("Selvi", 21, "MBA", 1234);
s2 = new Student("Arun", 22, "MCA", 1245);
s1.displayInfo();
s2.displayInfo();
