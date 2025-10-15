let datetime

fetch('./navbar.html')
  .then(response => response.text())
  .then(data => (document.getElementById('navbar').innerHTML = data))
  .then(() => {
    datetime = document.getElementById('datetime')
    updateDateTime()
    setInterval(updateDateTime, 1000)

    if (localStorage.getItem('user')) {
      const user = JSON.parse(localStorage.getItem('user'))
      document.getElementById(
        'user-greeting'
      ).textContent = `Hello, ${user.username}`
    }
  })

function updateDateTime () {
  const now = new Date()
  const options = {
    weekday: 'long',
    year: 'numeric',
    month: 'long',
    day: 'numeric',
    hour: 'numeric',
    minute: 'numeric',
    second: 'numeric',
    hour12: true
  }
  const formattedDateTime = now.toLocaleDateString('en-US', options)
  datetime.textContent = formattedDateTime
}
