/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

var gcdOfStrings = function (str1, str2) {
  if (str1 + str2 !== str2 + str1) {
    return "";
  }

  function gcd(a, b) {
    while (b != 0) {
      let temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  return str1.slice(0, gcd(str1.length, str2.length));
};

var gcdOfStrings1 = function (str1, str2) {
  let shortString, longString;

  if (str1.length > str2.length) {
    longString = str1;
    shortString = str2;
  } else {
    longString = str2;
    shortString = str1;
  }

  let gcdLengthPossible = longString.length;

  let gcd = "",
    GCD = "";

  let isGCD = false;

  for (let i = 0; i < shortString.length; i++) {
    if (gcd.length <= gcdLengthPossible) {
      if (str1[i] === str2[i]) {
        gcd += str1[i];
        isGCD =
          longString.split(gcd).every((c) => c === "") &&
          shortString.split(gcd).every((c) => c === "");
        if (isGCD) {
          GCD = gcd;
        }
      } else {
        return "";
      }
    }
  }
  return GCD;
};

console.log(gcdOfStrings("ABCABC", "ABC"));
console.log(gcdOfStrings("ABABAB", "ABAB"));
console.log(gcdOfStrings("LEET", "CODE"));
console.log(
  gcdOfStrings(
    "TAUXXTAUXXTAUXXTAUXXTAUXX",
    "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
  )
);
console.log(gcdOfStrings("ABCDEF", "ABC"));
console.log(gcdOfStrings("ABABABAB", "ABAB"));
console.log(
  gcdOfStrings(
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
  )
);

/**
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 */