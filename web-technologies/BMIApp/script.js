document.getElementById("calculateBtn").addEventListener("click", function() {
  const weight = parseFloat(document.getElementById("weight").value);
  const height = parseFloat(document.getElementById("height").value);

  // Validation
  if (!weight || !height || weight <= 0 || height <= 0) {
    alert("Please enter valid values.");
    return;
  }

  // Calculate BMI
  const bmi = weight / (height * height);
  const bmiRounded = bmi.toFixed(2);

  // Determine Category and Note
  let category = "";
  let note = "";

  if (bmi < 18.5) {
    category = "Underweight";
    note = "You are underweight. Eat nutritious food.";
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    category = "Normal weight";
    note = "You have a healthy body weight.";
  } else if (bmi >= 25 && bmi <= 29.9) {
    category = "Overweight";
    note = "You are slightly overweight. Exercise regularly.";
  } else {
    category = "Obese";
    note = "You are in the obese range. Consult a healthcare provider.";
  }

  // Store values in localStorage
  localStorage.setItem("weight", weight);
  localStorage.setItem("height", height);
  localStorage.setItem("bmi", bmiRounded);
  localStorage.setItem("category", category);
  localStorage.setItem("note", note);

  // Redirect to summary page
  window.location.href = "summary.html";
});
