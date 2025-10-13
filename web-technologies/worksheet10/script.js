function validateName () {
  const name = document.getElementById('name').value
  const nameRegex = /^[A-Za-z\s]{2,100}$/
  const isValid = name.match(nameRegex) !== null

  document.getElementById('nameHelp').textContent = isValid
    ? '✅'
    : 'Invalid name. Please enter 2-100 letters.'

  return isValid
}

document.getElementById('name').addEventListener('input', validateName)

function validateEmail () {
  const email = document.getElementById('email').value
  const emailRegex = /^[a-z0-9._%+-]+@[a-z0-9.-]+\.(com|in|edu)$/

  const isValid = email.match(emailRegex) !== null
  document.getElementById('emailHelp').textContent = isValid
    ? '✅'
    : 'Invalid email. Please enter a valid email (e.g., user@example.com)'
  return isValid
}

document.getElementById('email').addEventListener('blur', validateEmail)

function validatePassword () {
  const password = document.getElementById('password').value
  const passwordRegex = /^(?=.*[0-9]).{6,}$/

  const isLongEnough = password.length >= 6
  const isValid = password.match(passwordRegex) !== null && isLongEnough

  const errorList = document.getElementById('passwordHelp').querySelector('ul')
  errorList.innerHTML = ''

  const errorItem1 = document.createElement('li')
  if (!isLongEnough) {
    errorItem1.textContent = 'Password must be at least 6 characters long.'
  } else {
    errorItem1.textContent = '✅ Password length is sufficient.'
  }
  errorList.appendChild(errorItem1)

  const errorItem2 = document.createElement('li')
  if (!isValid) {
    errorItem2.textContent = 'Password must contain at least one number.'
  } else {
    errorItem2.textContent = '✅ Password contains a number.'
  }
  errorList.appendChild(errorItem2)

  return isValid
}

document.getElementById('password').addEventListener('input', validatePassword)

function validatePhone () {
  const phone = document.getElementById('phone')?.value
  const phoneRegex = /^[1-9][0-9]{9}$/
  if (phone === undefined) {
    return true
  }
  const isValid = phone.match(phoneRegex) !== null

  document.getElementById('phoneHelp').textContent = isValid
    ? '✅'
    : 'Invalid phone number. Please enter a 10-digit valid phone number.'
  return isValid
}

document.getElementById('phone').addEventListener('blur', validatePhone)

function validateDob () {
  const dob = document.getElementById('dob').value
  console.log(dob); // 2025-10-16

  const dobRegex = /^(19|20)\d\d-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$/
  const isValid = dob.match(dobRegex) !== null

  document.getElementById('dobHelp').textContent = isValid
    ? '✅'
    : 'Invalid date of birth. Please enter a valid date.'
  return isValid
}

document.getElementById('dob').addEventListener('blur', validateDob)

function validateRating () {
  const rating = document.form
  const isValid = rating >= 1 && rating <= 5

    document.getElementById('ratingHelp').textContent = isValid
    ? '✅'
    : 'Invalid rating. Please enter a rating between 1 and 5.'
  return isValid
}

document.getElementById('rating').addEventListener('blur', validateRating)

function validateForm () {
  let isValid = true
  isValid &= validateName()
  isValid &= validateEmail()
  isValid &= validatePassword()
  isValid &= validatePhone()
  isValid &= validateDob()
  isValid &= validateRating()
  isValid &= validateInterests()
  return isValid
}
