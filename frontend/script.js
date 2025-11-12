const computeBtn = document.getElementById("computeBtn");
const resultArea = document.getElementById("resultArea");

computeBtn.addEventListener("click", async () => {
  const start = document.getElementById("startNode").value.trim();
  const end = document.getElementById("endNode").value.trim();

  if (!start || !end) {
    resultArea.textContent = "⚠️ Please enter both start and end nodes.";
    return;
  }

  resultArea.textContent = "⏳ Computing route...";

  try {
    const response = await fetch("http://localhost:5000/api/route", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ start: Number(start), end: Number(end) }),
    });

    const data = await response.json();
    if (data.error) {
      resultArea.textContent = "❌ Error: " + data.error;
    } else {
      resultArea.textContent = "✅ " + data.result;
    }
  } catch (err) {
    resultArea.textContent = "⚠️ Failed to connect to server.";
    console.error(err);
  }
});
