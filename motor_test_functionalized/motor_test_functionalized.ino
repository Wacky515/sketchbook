// Declare motor cotrol PIN
const int mAE = 3;  // PMW      -ENABLE
const int mAP = 4;  // Digital	-PHASE
const int mMD = 7;  // MODE

// FIXME: Fix PIN assign
// For motor shield "DRV8835搭載デュアルモータードライバシールド"
// const int mAE = 6;  // PMW	    -ENABLE
// const int mAP = 8;  // Digital	-PHASE
// const int mMD = 7;  // MODE

void setup() {
  // Setting motor PIN (output)
  pinMode(mAE, OUTPUT);
  pinMode(mAP, OUTPUT);
  pinMode(mMD, OUTPUT);

  // Set MODE "PHASE-ENABLE"
  digitalWrite(mMD, HIGH);

  // Set serial COM port for debug
  Serial.begin(9600);
}

// Function
void drive(int spd, int dil = 1000) {
  analogWrite(mAE, spd);        // Set ENABLE: range 0 ~ 255
  digitalWrite(mAP, LOW);       // Set PHASE: LOW=0 or HIGH=1
  Serial.print(F("Speed "));    // Display speed
    Serial.printlnF((spd));
  delay(dil);
}

// Main loop
void loop() {
  int spd = 0;
  for (spd = 100; spd < 300; spd = spd + 50) {
    drive(spd);
  }
  drive(0, 3000);
}
