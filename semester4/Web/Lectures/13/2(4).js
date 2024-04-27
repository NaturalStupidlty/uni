function findIndex(arr) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === 5) {
      return i;
    }
  }
  return -1; // If 5 is not found in the array, return -1
}

const myArray = [1, 4, 5, 8, 3, 5, 2];
const index = findIndex(myArray);
console.log(index); // Output: 2
