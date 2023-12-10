let feedbackLink = document.getElementById("feedback-link");
let feedbackForm = document.getElementById("feedback-form");
let feedbackBackground = document.getElementById("feedback-background");

function toggleFeedback() {
  feedbackForm.classList.toggle("hidden");
  feedbackBackground.classList.toggle("hidden");
}

feedbackLink.addEventListener("click", function(e) {
  e.preventDefault();
  toggleFeedback();
});

document.getElementById("close-button").addEventListener("click", function(e) {
  e.preventDefault();
  toggleFeedback()
});

