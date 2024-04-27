const allInfoJSON = '{"pictures":[{"name":"Picture 1","path":"/path/to/picture1.jpg","date":"2023-05-14"},{"name":"","path":"/path/to/picture2.jpg","date":"2023-05-15"},{"name":"Picture 3","path":"/path/to/picture3.jpg","date":"2023-05-16"}]}';
const namesOnlyJSON = '["Picture 1","Picture 3"]';
const filteredJSON = '{"pictures":[{"name":"Picture 1","path":"/path/to/picture1.jpg","date":"2023-05-14"},{"name":"Picture 3","path":"/path/to/picture3.jpg","date":"2023-05-16"}]}';

// Parsing
const allInfo = JSON.parse(allInfoJSON);
const pictureNames = JSON.parse(namesOnlyJSON);
const filteredGallery = JSON.parse(filteredJSON);

// Convert to Date objects
allInfo.pictures.forEach(picture => {
  picture.date = new Date(picture.date);
});

filteredGallery.pictures.forEach(picture => {
  picture.date = new Date(picture.date);
});

console.log(allInfo);
console.log(pictureNames);
console.log(filteredGallery);