async function runCompiler() {
  const code = document.getElementById("code").value;

  const res = await fetch("http://localhost:5000/run", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({ code })
  });

  const data = await res.json();
  document.getElementById("output").innerText = data.output;
}
