// Declare motor cotrol PIN
//  Motr 1
const int mAE = 3;  // PMW      -ENABLE
const int mAP = 4;  // Digital	-PHASE

//  Motr 2
const int mAE2 = 9;  // PMW      -ENABLE
const int mAP2 = 8;  // Digital	-PHASE

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

  pinMode(mAE2, OUTPUT);
  pinMode(mAP2, OUTPUT);

  pinMode(mMD, OUTPUT);

  // Set MODE "PHASE-ENABLE"
  digitalWrite(mMD, HIGH);

  // Set serial COM port for debug
  Serial.begin(9600);
}

// Function
void drive(int ae, int ap, int spd, int dil = 1000) {
  analogWrite(ae, spd);        // Set ENABLE: range 0 ~ 255
  digitalWrite(ap, LOW);       // Set PHASE: LOW=0 or HIGH=1
  Serial.print("Speed ");    // Display speed
  Serial.println(spd);
  delay(dil);
}
// Main loop
void loop() {
  int spd = 0;
  int spd2 = 0;
  for (spd = 100; spd < 300; spd = spd + 50) {
    for (spd2 = 50; spd2 < 300; spd2 = spd + 60) {
      drive(mAE, mAP, spd);
      drive(mAE2, mAP2,spd2);
    }
  }
  drive(mAE, mAP, 0, 3000);
  drive(mAE2, mAP2, 0, 3000);
}

