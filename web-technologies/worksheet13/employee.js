// read EmpLogin.txt file
const prompts = require("prompts");
const { appendFile } = require("fs/promises");

console.log("EMPLOYEE LOGIN DETAILS");

(async () => {
  const response = await prompts([
    {
      type: "select",
      name: "choice",
      message: "Choose from menu",
      choices: [
        { title: "Log: time-in", value: "logTimeIn" },
        { title: "Log: time-out", value: "logTimeOut" },
        {
          title: "View: late clock ins by date",
          value: "getLateClockInsByDate",
        },
      ],
    },
  ]);

  eval(`${response["choice"]}()`);
})();

function logTimeIn() {
  (async () => {
    const response = await prompts([
      {
        type: "text",
        name: "empId",
        message: "Enter employee id",
      },
    ]);

    console.log({
      empId: response.empId,
      date: new Date().toLocaleDateString(),
      timeIn: new Date().toLocaleTimeString(),
    });
  })();
}

function logTimeOut() {
  (async () => {
    const response = await prompts([
      {
        type: "text",
        name: "empId",
        message: "Enter employee id",
      },
    ]);

    // TODO: If an entry for empId, with current date is found, then add the time out also and write to EmpLogin.txt
  })();
}

function getLateClockInsByDate() {}
