"use strict";

let categories = document.querySelectorAll(".side-menu > li > a");

categories.forEach(function(element) {
  element.addEventListener("click", function(event) {
      event.preventDefault();
      element.parentElement.classList.toggle("active-category");
      categories.forEach(function(element2) {
        if (element2 !== element) {
          element2.parentElement.classList.remove("active-category");
        }
      });
  });
});