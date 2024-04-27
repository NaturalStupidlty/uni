function addFieldToObject(obj, key, value) {
  // check if key already exists in object
  if (!(key in obj)) {
    obj[key] = value;
  }
  return obj;
}

let myObj = { name: "John", age: 30 };
myObj = addFieldToObject(myObj, "city", "New York");
myObj = addFieldToObject(myObj, "name", "Mike");
console.log(myObj); // { name: "John", age: 30, city: "New York" }