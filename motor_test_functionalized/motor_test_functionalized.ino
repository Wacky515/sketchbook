// Declare motor cotrol PIN
const int mAE = 3;  // PMW	-Enable
const int mAP = 4;  // Digital	-PHASE
const int mMD = 7;  // PMW

// For motor shield "DRV8835搭載デュアルモータードライバシールド"
// const int mAE = 6;  // PMW	-Enable
// const int mAP = 8;  // Digital	-PHASE
// const int mMD = 7;  // PMW

void setup() {
  // Setting output motor PIN
  pinMode(mAE, OUTPUT);
  pinMode(mAP, OUTPUT);
  pinMode(mMD, OUTPUT);

  // Setting PHASE - ENABLE
  digitalWrite(mMD, HIGH);

  // Serial com for debug
  Serial.begin(9600);
}

// Function
void drive(int spd, int dil = 1000) {
  analogWrite(mAE, spd);      // ENABLE set 0 ~ 255
  digitalWrite(mAP, LOW);     // PHASE set LOW=0, HIGH=1
  Serial.print("Speed ");	  // Display speed
    Serial.println(spd);              // Display speed
  delay(dil);
}

void loop() {
  // Do class and for loop
  int spd = 0;
  for (spd = 100; spd < 300; spd = spd + 50) {
    drive(spd);
  }
  drive(0, 3000);
}
