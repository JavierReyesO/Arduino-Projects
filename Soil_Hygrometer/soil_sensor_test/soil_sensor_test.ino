#define soil_moisture A6

void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int percentValue = map(analogRead(soil_moisture), 1023, 0, 0, 100);
  Serial.print("Humidity Percent: ");
  Serial.print(percentValue);
  Serial.println("%");
  delay(30000); // on miliseconds
}
