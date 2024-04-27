// a)

function sortArrayAlphabetically(arr) {
  arr.sort();
  return arr;
}

const fruits = ["banana", "apple", "orange", "grape"];
const sortedFruits = sortArrayAlphabetically(fruits);
console.log(sortedFruits); // Output: ["apple", "banana", "grape", "orange"]

// b)

function sortAbsoluteValues(arr, descendingOrder = false) {
  // Sort the array by absolute value
  arr.sort((a, b) => {
    const absA = Math.abs(a);
    const absB = Math.abs(b);
    if (absA === absB) {
      return 0;
    }
    if (absA < absB) {
      return descendingOrder ? 1 : -1;
    }
    return descendingOrder ? -1 : 1;
  });
  // Return the sorted array
  return arr;
}

const arr = [-5, 3, -1, 2, -4, 0];
const sortedArr = sortAbsoluteValues(arr);
console.log(sortedArr); // [0, -1, 2, 3, -4, -5]