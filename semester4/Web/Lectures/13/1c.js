function distanceOrQuadrant(p1, p2) {
  if (p1[0] === p2[0] && p1[1] === p2[1]) {
    return "The two points are the same.";
  } else if (p1[0] === 0 && p1[1] === 0) {
    return "Point 1 is at the origin.";
  } else if (p2[0] === 0 && p2[1] === 0) {
    return "Point 2 is at the origin.";
  } else {
    var q1 = getQuadrant(p1);
    var q2 = getQuadrant(p2);
    if (q1 === q2) {
      return "The distance between the two points is " + distance(p1, p2) + ".";
    } else {
      return "Point 1 is in quadrant " + q1 + ", and point 2 is in quadrant " + q2 + ".";
    }
  }
}

function getQuadrant(point) {
  if (point[0] === 0 || point[1] === 0) {
    if (point[0] === 0 && point[1] > 0) {
      return "positive y-axis";
    } else if (point[0] === 0 && point[1] < 0) {
      return "negative y-axis";
    } else if (point[0] > 0 && point[1] === 0) {
      return "positive x-axis";
    } else if (point[0] < 0 && point[1] === 0) {
      return "negative x-axis";
    } else {
      return "the origin";
    }
  } else if (point[0] > 0 && point[1] > 0) {
    return "I";
  } else if (point[0] < 0 && point[1] > 0) {
    return "II";
  } else if (point[0] < 0 && point[1] < 0) {
    return "III";
  } else {
    return "IV";
  }
}

function distance(p1, p2) {
  var dx = p2[0] - p1[0];
  var dy = p2[1] - p1[1];
  return Math.sqrt(dx * dx + dy * dy);
}

// test cases
console.log(distanceOrQuadrant([1, 2], [3, 4])); // "The distance between the two points is 2.8284271247461903."
console.log(distanceOrQuadrant([1, 2], [-3, 4])); // "Point 1 is in quadrant I, and point 2 is in quadrant II."
console.log(distanceOrQuadrant([0, 0], [3, 4])); // "Point 1 is at the origin."
console.log(distanceOrQuadrant([1, 2], [1, 2])); // "The two points are the same."
console.log(distanceOrQuadrant([0, 2], [1, 0])); // "Point 1 is on the positive y-axis, and point 2 is on the positive x