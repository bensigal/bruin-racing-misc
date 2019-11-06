#define TC_PIN A0
#define AREF 5.0
#define ADC_RESOLUTION 10

float reading, voltage, temperature;

float get_voltage(int raw_adc){
  return raw_adc * (AREF / (pow(2, ADC_RESOLUTION) - 1));
}

float get_temperature(float voltage){
  return (voltage - 1.25)/0.005;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  reading = analogRead(TC_PIN);
  voltage = get_voltage(reading);
  temperature = get_temperature(voltage);
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");
  delay(500);
}
