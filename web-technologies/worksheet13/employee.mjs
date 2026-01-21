import prompts from 'prompts'
import { readFileSync, writeFileSync } from 'fs'

console.log('EMPLOYEE LOGIN DETAILS')
;(async () => {
  const response = await prompts([
    {
      type: 'select',
      name: 'choice',
      message: 'Choose from menu',
      choices: [
        { title: 'Log: time-in', value: 'logTimeIn' },
        { title: 'Log: time-out', value: 'logTimeOut' },
        {
          title: 'View: late clock ins by date',
          value: 'getLateClockInsByDate'
        }
      ]
    }
  ])

  eval(`${response['choice']}()`)
})()

async function logTimeIn () {
  const response = await prompts([
    {
      type: 'text',
      name: 'empId',
      message: 'Enter employee id'
    }
  ])

  const newTimeIn = {
    empId: response.empId,
    date: new Date(),
    timeIn: new Date()
  }

  try {
    const data = readFileSync('EmpLogin.txt', 'utf-8')
    const empLogins = data && data.trim() ? JSON.parse(data) : []

    let found = empLogins.find(entry => {
      if (
        entry.empId === newTimeIn.empId &&
        new Date(entry.date).toLocaleDateString() ===
          newTimeIn.date.toLocaleDateString()
      ) {
        console.log(
          `Employee ID: ${newTimeIn.empId} has already logged in today.`
        )
        return true
      }
    })

    if (!found) {
      empLogins.splice(0, 0, newTimeIn)
      writeFileSync('EmpLogin.txt', JSON.stringify(empLogins, null, 2))
      console.log(`Employee ID: ${newTimeIn.empId} logged in successfully.`)
    }
  } catch (error) {
    console.error(error)
  }
}

async function logTimeOut () {
  const response = await prompts([
    {
      type: 'text',
      name: 'empId',
      message: 'Enter employee id'
    }
  ])

  try {
    const data = readFileSync('EmpLogin.txt', 'utf-8')
    const empLogins = data && data.trim() ? JSON.parse(data) : []

    const found = empLogins.find(
      entry =>
        entry.empId === response.empId &&
        new Date(entry.date).toLocaleDateString() ===
          new Date().toLocaleDateString()
    )

    if (found) {
      if (found.timeOut) {
        console.log(
          `Employee ID: ${response.empId} has already logged out today.`
        )
        return
      }
      found.timeOut = new Date()
      writeFileSync('EmpLogin.txt', JSON.stringify(empLogins, null, 2))
      console.log(`Employee ID: ${response.empId} logged out successfully.`)
    } else {
      console.log(
        `No login entry found for Employee ID: ${response.empId} today.`
      )
    }
  } catch (error) {
    console.error(error)
  }
}

async function getLateClockInsByDate () {
  const response = await prompts([
    {
      type: 'date',
      name: 'date',
      message: 'Enter date to check for late clock ins',
      mask: 'YYYY-MM-DD'
    }
  ])

  console.log(response.date.toLocaleString())

  try {
    const data = readFileSync('EmpLogin.txt', 'utf-8')
    const empLogins = data && data.trim() ? JSON.parse(data) : []

    const lateClockIns = empLogins.filter(entry => {
      return (
        new Date(entry.date).toLocaleDateString() ===
          response.date.toLocaleDateString() &&
        new Date(entry.timeIn).getTime() > new Date('1970-01-01T10:00:00').getTime()
      )
    })

    if (lateClockIns.length > 0) {
      console.log(`Late clock ins for ${response.date}:`)
      lateClockIns.forEach(entry => {
        console.log(`Employee ID: ${entry.empId}, Time In: ${entry.timeIn}`)
      })
    } else {
      console.log(`No late clock ins found for ${response.date}.`)
    }
  } catch (error) {
    console.error(error)
  }
}
