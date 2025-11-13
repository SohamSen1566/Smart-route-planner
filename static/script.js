// =============================
// All cities extracted from CSV
// =============================
const cities = [
"Abbigeri","Agra","Ahmedabad","Aligarh","Ambattur","Amritsar","Aurangabad","Baj Baj",
"Balasore","Bangalore","Barakpur","Bansbaria","Bauria","Bhayandar","Bhalswa Jahangirpur",
"Bhatpara","Bhopal","Bilaspur","Byatarayanpur","Chakapara","Chandannagar","Chandigarh",
"Chennai","Dasarhalli","Delhi","Dhanbad","Faridabad","Garhi","Ghaziabad","Guwahati",
"Gwalior","Haora","Haldwani","Herohalli","Hyderabad","Indore","Jabalpur","Jaipur",
"Jamshedpur","Jodhpur","Kalyan","Kanpur","Kankuria","Kendraparha","Kolkata","Kota",
"Kukatpalli","Loni","Lucknow","Ludhiana","Madipakkam","Madurai","Madhavaram","Manali",
"Meerut","Mirpeta","Mirzapur","Mumbai","Muzaffarpur","Murtazabad","Nagpur","Najafgarh",
"Nangloi Jat","Nasik","Nerkunram","New Delhi","Oulgaret","Pallavaram","Pappakurichchi",
"Patna","Pimpri-Chinchwad","Puducherry","Pune","Puri","Raipur","Rajkot","Ranchi",
"Sabalpur","Salt Lake City","Secunderabad","Shimla","Shrirampur","Sijua","Srinagar",
"Sultanpur Mazra","Supaul","Surat","Thane","Tiruvottiyur","Titagarh","Vadodara",
"Varanasi","Vasai-Virar","Vijayavada","Vishakhapatnam","Yelahanka"
];

// =============================
// Load cities into dropdowns
// =============================
function loadCities() {
    const srcDropdown = document.getElementById("source");
    const destDropdown = document.getElementById("destination");

    cities.forEach(city => {
        let op1 = document.createElement("option");
        op1.value = op1.textContent = city;
        srcDropdown.appendChild(op1);

        let op2 = document.createElement("option");
        op2.value = op2.textContent = city;
        destDropdown.appendChild(op2);
    });
}
window.onload = loadCities;


// =============================
// Find Route Button (API call)
// =============================
document.getElementById("findRoute").addEventListener("click", async () => {
    const src = document.getElementById("source").value.trim();
    const dest = document.getElementById("destination").value.trim();
    const output = document.getElementById("output");

    if (!src || !dest) {
        output.innerHTML = "<p style='color:red;'>⚠ Please select both cities.</p>";
        return;
    }

    output.innerHTML = "<p>Finding route... ⏳</p>";

    try {
        const res = await fetch(`/find_route?src=${src}&dest=${dest}`);
        const data = await res.json();

        if (data.error) {
            output.innerHTML = `
                <div class="output-box">
                    <h3>❌ Error</h3>
                    <pre>${data.error}</pre>
                </div>
            `;
            return;
        }

        // Beautiful output box
        output.innerHTML = `
            <div class="output-box">
                <h3>🚗 Shortest Route</h3>

                <pre>${data.result}</pre>

                <div class="output-divider"></div>

                <p style="text-align:center; color:#0047ab; font-weight:600;">
                    Route computed successfully ✔
                </p>
            </div>
        `;

    } catch (err) {
        output.innerHTML = `
            <div class="output-box">
                <h3>⚠ Network Error</h3>
                <pre>${err}</pre>
            </div>
        `;
    }
});
