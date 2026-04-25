
const statusTime = document.getElementById("statusTime");
const statusStop = document.getElementById("statusStop");

function sendRequest(endpoint) {
    fetch(endpoint)
        .then(() => console.log("Wysłano:", endpoint))
        .catch(err => console.error("Błąd:", err));
}

document.getElementById("30s").addEventListener("click", () => {
    sendRequest("/30");
    statusTime.textContent = "Wysłano: 30s";
    statusStop.textContent = "";
});

document.getElementById("60").addEventListener("click", () => {
    sendRequest("/60");
    statusTime.textContent = "Wysłano: 60s";
    statusStop.textContent = "";
});

document.getElementById("90").addEventListener("click", () => {
    sendRequest("/90");
    statusTime.textContent = "Wysłano: 90s";
    statusStop.textContent = "";
});

document.getElementById("inf").addEventListener("click", () => {
    sendRequest("/inf");
    statusTime.textContent = "Tryb ciągły";
    statusStop.textContent = "";
});

// STOP
document.getElementById("stopButton").addEventListener("click", () => {
    sendRequest("/stop");
    statusTime.textContent = "";
    statusStop.textContent = "Zatrzymano";
});
