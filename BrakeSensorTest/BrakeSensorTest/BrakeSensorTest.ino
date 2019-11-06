const int BRAKE_PIN = A0;
int brakeValue = 0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  brakeValue = analogRead(BRAKE_PIN);
  Serial.println(brakeValue);
//  delay(1000);
}
