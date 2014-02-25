int tempPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int out = 13;

void setup() {
  Serial.begin(9600);
  pinMode(out,OUTPUT);
}

void loop() {
    sensorValue = analogRead(tempPin);

    float voltage = (sensorValue/1024.0) * 5;
    
    Serial.print(voltage*100);
    Serial.print("\n");
    
    digitalWrite(out,HIGH);
    
    delay(100);
}
