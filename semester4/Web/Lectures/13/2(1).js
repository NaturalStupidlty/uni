let arr1 = [9, 1, 2, 6, 420, 5];
let arr2 = [1488, 5, 2, 7, 69, 9];

let arr = arr1.concat(arr2).filter(function(value, index, self) {
    return self.indexOf(value) === index;
});

console.log(`Третій масив з унікальними елементами: ${arr}`);