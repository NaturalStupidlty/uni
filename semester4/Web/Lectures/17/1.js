const gallery = {
  pictures: [
    { name: "Picture 1", path: "/path/to/picture1.jpg", date: "2023-05-14" },
    { name: "", path: "/path/to/picture2.jpg", date: "2023-05-15" },
    { name: "Picture 3", path: "/path/to/picture3.jpg", date: "2023-05-16" }
  ]
};

// 1
const allInfoJSON = JSON.stringify(gallery);
console.log(allInfoJSON);

// 2
const pictureNames = gallery.pictures
  .filter(picture => picture.name !== "") // Filter out pictures without names
  .map(picture => picture.name); // Extract picture names
const namesOnlyJSON = JSON.stringify(pictureNames);
console.log(namesOnlyJSON);

// 3
const filteredGallery = {
  pictures: gallery.pictures.filter(picture => picture.name !== "")
};
const filteredJSON = JSON.stringify(filteredGallery);
console.log(filteredJSON);
