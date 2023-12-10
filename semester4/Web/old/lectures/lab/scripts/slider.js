"use strict";

let slider = document.getElementById('slider');
let slides = [...slider.querySelectorAll("img")];
let currentSlide = slider.querySelector("img.active");
let currentSlideIndex = slides.indexOf(currentSlide);

function changeSlide(direction) {
    let nextSlideIndex = currentSlideIndex + direction;
    if (nextSlideIndex < 0) {
        nextSlideIndex = slides.length - 1;
    } else if (nextSlideIndex >= slides.length) {
        nextSlideIndex = 0;
    }
    currentSlide.classList.remove("active");
    slides[nextSlideIndex].classList.add("active");
    currentSlide = slides[nextSlideIndex];
    currentSlideIndex = nextSlideIndex;
}

// timer for slides
let timer = setInterval(() => {
    changeSlide(1);
}, 4000);

// click on arrows
document.getElementById("previous").addEventListener("click", () => {
    clearInterval(timer);
    changeSlide(-1);
    timer = setInterval(() => {
        changeSlide(1);
    }, 4000);
});

document.getElementById("next").addEventListener("click", () => {
    clearInterval(timer);
    changeSlide(1);
    timer = setInterval(() => {
        changeSlide(1);
    }, 4000);
});
