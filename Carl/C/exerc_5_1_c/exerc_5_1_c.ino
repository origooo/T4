int tempPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int out = 13;


void setup() {
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  
  for(int i = 2; i <= 12; i++)
    pinMode(i,OUTPUT);
}

void loop() {
    sensorValue = analogRead(tempPin);
    float voltage = (sensorValue/1024.0) * 5;
    
    Serial.print(voltage*100);
    Serial.print("\n");
    
    calc_Digits();
    
    delay(100);
}

void calc_Digits() {
    
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    
    delay(100);
    
//    for(int i = 2; i <= 8; i++){
//      digitalWrite(i, HIGH);
//    }

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
}
