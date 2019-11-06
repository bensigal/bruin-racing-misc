int sensorPin   = A0;    // select the input pin
int secondarySensorPin = A5; // select the secondary input pin (for testing referrent voltage, etc.)
int delayLength = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //analogRead gives a value from 0 to 1023, not from 0 to 5
  double voltageIn = 5.0 * analogRead(sensorPin) / 1024.0;
  //Temperature calculation as given by the manufacturers
  double temp      = (voltageIn - 1.25) * 200.0;
  
  //Print to console
  Serial.print("Voltage: "); 
  Serial.println(voltageIn);
  
  Serial.print("Temp:    "); 
  Serial.println(temp);

  //Serial.print("Secondary voltage reader: "); 
  //Serial.println(analogRead(secondarySensorPin) * 5.0 / 1024.0);
  
  delay(delayLength);
}
