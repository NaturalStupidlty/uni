function checkForZero(arr) {
  // Loop through each element in the array
  for (let i = 0; i < arr.length; i++) {
    // If the current element is zero, print a message and return
    if (arr[i] === 0) {
      console.log("At least one element in the array is zero.");
      return;
    }
  }
  // If we get here, there were no zeros in the array
  console.log("No elements in the array are zero.");
}

let myArray = [1, 2, 3, 0, 4];
checkForZero(myArray); // Output: At least one element in the array is zero.

let anotherArray = [1, 2, 3, 4, 5];
checkForZero(anotherArray); // Output: No elements in the array are zero.