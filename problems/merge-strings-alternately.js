/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function (word1, word2) {
  var ans = "";
  let i = 0;
  while (i < word1.length || i < word2.length) {
    if (i < word1.length) {
      ans += word1[i];
    }
    if (i < word2.length) {
      ans += word2[i];
    }
    i++;
  }
  return ans;
};

console.log(mergeAlternately("abc", "pqr")); // apbqcr

