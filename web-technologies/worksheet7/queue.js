const prompt = require('prompt-sync')()

const myQueue = []

function enqueue (item) {
  myQueue.push(item)
}

function dequeue () {
  return myQueue.shift()
}

function size () {
  return myQueue.length
}

function sortQueue () {
  return [...myQueue].sort()
}

function editQueue (index, n, ...items) {
  myQueue.splice(index, n, ...items)
}

function divideQueue () {
  return [
    myQueue.slice(0, Math.ceil(myQueue.length / 2)),
    myQueue.slice(Math.ceil(myQueue.length / 2))
  ]
}

function queueAsString () {
  return myQueue.join(', ')
}

while (true) {
  console.log('\nMenu:')
  console.log('1. Enqueue an item')
  console.log('2. Dequeue an item')
  console.log('3. Get the size of the queue')
  console.log('4. Sort the queue')
  console.log('5. Edit the queue')
  console.log('6. Divide the queue into two halves')
  console.log('7. Display the queue as a string')
  console.log('8. Exit')
  console.log(`\x1b[32mCurrent Queue: [${myQueue.join(', ')}]\x1b[0m`)
  const choice = prompt('Choose an option (1-8): ')

  process.stdout.write('\x1b[32m')
  switch (choice) {
    case '1':
      const item = prompt('Enter an item to enqueue: ')
      enqueue(item)
      break
    case '2':
      const dequeued = dequeue()
      if (dequeued === undefined) {
        process.stdout.write('Queue is empty, cannot dequeue.\n')
        break
      }
      console.log(`Dequeued item: ${dequeued}`)
      break
    case '3':
      console.log(`Queue size: ${size()}`)
      break
    case '4':
      console.log(`Sorted queue: ${sortQueue()}`)
      break
    case '5':
      const index = prompt('Enter the index to edit: ')
      const n = prompt('Enter the number of items to remove: ')
      const newItems = prompt('Enter the new items (comma-separated): ').split(
        ','
      )
      editQueue(index, n, ...newItems)
      break
    case '6':
      const [firstHalf, secondHalf] = divideQueue()
      console.log(`First half: ${firstHalf}`)
      console.log(`Second half: ${secondHalf}`)
      break
    case '7':
      console.log(`Queue as string: ${queueAsString()}`)
      break
    case '8':
      console.log('Exiting the program.')
      process.exit()
  }
  process.stdout.write('\x1b[0m')
}
