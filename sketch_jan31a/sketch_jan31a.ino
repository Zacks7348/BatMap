
#define INTERVAL 500 //Times between reads
unsigned long lastRead = 0;


const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Slow down how often the distance is measured
  if (millis() - lastRead >= INTERVAL) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Measure the time it takes
    duration = pulseIn(echoPin, HIGH);
    //Calculate distance using formula
    distance = (duration * .0343) / 2;
    //Filter out the distance
    if (distance < 500) {
      Serial.print("Distance: ");
      Serial.println(distance);
    }
    delay(100);
    //Reset counter back to the current time
    lastRead = millis();

  }

}
