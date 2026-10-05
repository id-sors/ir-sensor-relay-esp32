const int IR_PIN    = 32;
const int RELAY_PIN = 26;

const bool RELAY_ACTIVE_LOW = true;   
const bool IR_ACTIVE_LOW    = true;  
const unsigned long DEBOUNCE_MS = 300;

bool relayOn = false;
bool lastDetected = false;
unsigned long lastToggle = 0;

void setRelay(bool on) {
  digitalWrite(RELAY_PIN, (on == RELAY_ACTIVE_LOW) ? LOW : HIGH);
}

bool irDetected() {
  return digitalRead(IR_PIN) == (IR_ACTIVE_LOW ? LOW : HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);   // start OFF
}

void loop() {
  bool detected = irDetected();

  // Toggle only on the moment an object appears (not-detected -> detected)
  if (detected && !lastDetected && (millis() - lastToggle > DEBOUNCE_MS)) {
    relayOn = !relayOn;
    setRelay(relayOn);
    lastToggle = millis();
    Serial.println(relayOn ? "Relay ON" : "Relay OFF");
  }

  lastDetected = detected;
  delay(10);
}