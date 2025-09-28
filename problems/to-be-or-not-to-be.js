/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  return {
    toBe: i => {
      return i === val
        ? true
        : (() => {
            throw new Error('Not Equal')
          })()
    },
    notToBe: i => {
      return i !== val
        ? true
        : (() => {
            throw new Error('Equal')
          })()
    }
  }
}

console.log(expect(5).toBe(5))
console.log(expect(5).notToBe(5))
console.log(expect(5).toBe(null))
