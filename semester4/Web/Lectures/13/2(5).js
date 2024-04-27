function productOfArray(arr) {
  let product = 1;
  for (let i = 0; i < arr.length; i++) {
    product *= arr[i];
  }
  return product;
}


let arr = [4, 5, 6, 7, 8, 9];
console.log(productOfArray(arr))