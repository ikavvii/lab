/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function (candies, extraCandies) {
  let result = []

  candies.forEach(kidWithCandies => {

    let kidWithExtraCandies = kidWithCandies + extraCandies
    
    if (kidWithExtraCandies >= Math.max(...candies)) {
      result.push(true)
    } else {
      result.push(false)
    }
  })
  return result
}

let candies = [2, 3, 5, 1, 3],
  extraCandies = 3

console.log(kidsWithCandies(candies, extraCandies))

/**
 * * candies[i] no of candies of i'th kid
 * ^ iterate thru items and checks 
 * ? if kid is max candies holder, after adding extraCandies
 */

