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

  // Serial COM port for display out
  Serial.begin(9600);
}

void loop() {
  // TODO: Class and For loop
  analogWrite(mAE, 50);		// ENABLE set 0 ~ 255
  digitalWrite(mAP, LOW);		// PHASE set LOW=0, HIGH=1
  Serial.println("Speed 50");  	// Display speed
  delay(1000);

  analogWrite(mAE, 100);
  digitalWrite(mAP, LOW);
  Serial.println("Speed 100");
  delay(1000);

  analogWrite(mAE, 150);
  digitalWrite(mAP, 0);
  Serial.println("Speed 150");
  delay(1000);

  analogWrite(mAE, 200);
  digitalWrite(mAP, 0);
  Serial.println("Speed 200");
  delay(1000);

  analogWrite(mAE, 250);
  digitalWrite(mAP, 0);
  Serial.println("Speed 250");
  delay(1000);

  analogWrite(mAE, 0);
  digitalWrite(mAP, LOW);
  Serial.println("Speed 0");
  delay(1000);

}
