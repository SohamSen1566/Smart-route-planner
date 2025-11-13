from flask import Flask, render_template, request, jsonify
import subprocess
import json

app = Flask(__name__)

# -----------------------------
# ROUTE: Serve Frontend
# -----------------------------
@app.route("/")
def home():
    return render_template("index.html")


# -----------------------------
# ROUTE: Call C++ Backend
# -----------------------------
@app.route("/find_route")
def find_route():
    src = request.args.get("src")
    dest = request.args.get("dest")

    if not src or not dest:
        return jsonify({"error": "Missing source or destination"}), 400

    # Run the C++ exe
    try:
        process = subprocess.Popen(
            ["cpp_backend/dijkstra.exe", src, dest],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        output, error = process.communicate()

        if error:
            return jsonify({"error": error}), 500

        # Expecting C++ to print JSON string or plain text
        return jsonify({"result": output})

    except Exception as e:
        return jsonify({"error": str(e)}), 500


if __name__ == "__main__":
    app.run(debug=True)
