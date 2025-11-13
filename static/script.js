document.getElementById("findRoute").addEventListener("click", async () => {
    const src = document.getElementById("source").value.trim();
    const dest = document.getElementById("destination").value.trim();
    const output = document.getElementById("output");

    if (!src || !dest) {
        output.innerHTML = "<p style='color:red;'>⚠ Please enter both cities.</p>";
        return;
    }

    output.innerHTML = "<p>Finding route... ⏳</p>";

    try {
        const res = await fetch(`/find_route?src=${src}&dest=${dest}`);
        const data = await res.json();

        if (data.error) {
            output.innerHTML = `<p style='color:red;'>${data.error}</p>`;
            return;
        }

        output.innerHTML = `
            <h3>Shortest Route Result</h3>
            <pre>${data.result}</pre>
        `;
    } catch (err) {
        output.innerHTML = `<p style='color:red;'>Error: ${err}</p>`;
    }
});
