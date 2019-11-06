#define INPUT_PIN A0
#define THRESHOLD 100
//0: Just the voltage, 1: Every time it changes, 2: Speed
#define MODE 2

//In ms
#define SPEED_MEASUREMENT_INTERVAL 5000
//In in
#define CIRCUMFERENCE 2*PI*18

void setup() {
  Serial.begin(9600);
  #if MODE==2
    Serial.println("Beginning in speed measurement mode.");
  #endif
}

void loop() {
  
  #if MODE==0
  
    Serial.println(analogRead(INPUT_PIN));
    
  #elif MODE==1
  
    Serial.println("High");
    while(analogRead(INPUT_PIN) > THRESHOLD){
      ;
    }
    Serial.println("Low");
    while(analogRead(INPUT_PIN <= THRESHOLD)){
      ;
    }
    
  #elif MODE==2
  
    int startTick = millis();
    int highs = 0;
    while(millis() < startTick + SPEED_MEASUREMENT_INTERVAL){
      while(analogRead(INPUT_PIN) > THRESHOLD){
        ;
      }
      highs++;
      while(analogRead(INPUT_PIN) <= THRESHOLD){
        ;
      }
    }
    double timePassed = millis() - startTick;
    Serial.print("Time passed (ms): ");
    Serial.println(timePassed);
    
    Serial.print("Highs measured: ");
    Serial.println(highs);

    Serial.print("Hz: ");
    double hertz = highs*1000.0/timePassed;
    Serial.println(hertz);

    Serial.print("Rpm: ");
    Serial.println(hertz*60.0);

    Serial.print("MPH: ");
    //dividing by three is becacuse there are three high points on the thing
    double milesTravelled = highs/3*CIRCUMFERENCE/12.0/5280.0;
    Serial.println(milesTravelled/timePassed*1000*60*60);
    
  #endif
}
