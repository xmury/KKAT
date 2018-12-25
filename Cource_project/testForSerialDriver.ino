int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
   
   if (Serial.available() > 0) {
        incomingByte = Serial.read();
        Serial.println(incomingByte);
        digitalWrite(8, HIGH);
        delay(1);
    }
    digitalWrite(8, LOW);
}