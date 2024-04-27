function getEvenNumbers(arr) {
  // Define an empty array to hold the even numbers
  let evenNumbers = [];

  // Loop through the array and check if each element is even
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] % 2 === 0) {
      evenNumbers.push(arr[i]);
    }
  }

  // Return the array of even numbers
  return evenNumbers;
};

let myArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let evenNumbers = getEvenNumbers(myArray);
console.log(evenNumbers);
// Output: [2, 4, 6, 8, 10]