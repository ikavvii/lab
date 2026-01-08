import { writeFileSync } from "fs";

try {
    fstat.writeFileSync('output.txt', "Hello, Exception handling in JS!")
    console.log("File written successfully!");
}