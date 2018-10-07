/*
 * poti as sensetive selector:
 * Vin and GND to the bouth sides of 10k poti
 * 10k poti out to the sensor pin
 * + of electret micro to sensor pin
 * - of electret micro to GND
 */
int sensorPin = PIN1;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(0, sensorValue>50);
  digitalWrite(1, sensorValue>60);
  digitalWrite(3, sensorValue>90);

  if (sensorValue>220) {
    delay(200 + 10*(sensorValue-220));
    digitalWrite(4, HIGH);
    delay(200 + 10*(sensorValue-220));
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, sensorValue>100);
  }
}


