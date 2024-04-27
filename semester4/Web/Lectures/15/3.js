const myObj = {
  name: "John",
  age: 30,
  city: "New York"
};

// Method 1
console.log("Method 1: Using for...in loop");
for (let key in myObj) {
  console.log(key + ": " + myObj[key]);
}

// Method 2
console.log("\nMethod 2: Using Object.entries() method");
Object.entries(myObj).forEach(([key, value]) => {
  console.log(key + ": " + value);
});
