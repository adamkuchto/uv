
const statusTime = document.getElementById("statusTime");
const statusStop = document.getElementById("statusStop");

let timer = null;
let remainingTime = 0;

// Funkcja wysyłająca żądanie do ESP32
function sendRequest(endpoint) {
    fetch(endpoint)
        .then(() => console.log("Wysłano:", endpoint))
        .catch(err => console.error("Błąd:", err));
}

// Odliczanie czasu
function startCountdown(seconds) {
    clearInterval(timer);
    remainingTime = seconds;

    timer = setInterval(() => {
        if (remainingTime > 0) {
            statusTime.textContent = `Pozostało: ${remainingTime}s`;
            remainingTime--;
        } else {
            clearInterval(timer);
            statusTime.textContent = "Zakończono";
        }
    }, 1000);
}

// Przyciski czasu
document.getElementById("30s").addEventListener("click", () => {
    sendRequest("/30");
    startCountdown(30);
    statusStop.textContent = "";
});

document.getElementById("60").addEventListener("click", () => {
    sendRequest("/60");
    startCountdown(60);
    statusStop.textContent = "";
});

document.getElementById("90").addEventListener("click", () => {
    sendRequest("/90");
    startCountdown(90);
    statusStop.textContent = "";
});

document.getElementById("inf").addEventListener("click", () => {
    sendRequest("/inf");
    clearInterval(timer);
    statusTime.textContent = "Tryb ciągły";
    statusStop.textContent = "";
});

// STOP
document.getElementById("stopButton").addEventListener("click", () => {
    sendRequest("/stop");
    clearInterval(timer);
    statusTime.textContent = "";
    statusStop.textContent = "Zatrzymano";
});
