import { readFileSync } from "fs";

try {
  let data = readFileSync("info.txt", "utf-8");
  console.log("File content: \n" + data);
} catch (e) {
  console.log("Error: Unable to read file.");
  
  console.log("Details: " + e.message);

  console.log(JSON.stringify(e, null, 2));
} finally {
  console.log("File read attempt completed.");
}
