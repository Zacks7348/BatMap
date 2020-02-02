#define INTERVAL 500 //Times between reads
unsigned long lastRead = 0;

// Ultrasonic Constants
const int trigPin = 9;
const int echoPin = 10;
//Ultrasonic Variables
float duration, distance;

void setup() {
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:

  //Initialize the Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void ping(int n, float distance) {
  for (int i = 0; i < n; i++) {
    Serial.print("BatMap: PING (");
    Serial.print(distance);
    Serial.println(" cm)");
  }
}

void batMap() {
  if ((millis() - lastRead >= INTERVAL)) {
    Serial.println("BatMap: ");
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
    if (distance > 400 and distance <= 500) {
      ping(1, distance);
    }
    else if (distance > 300 and distance <= 400) {
      ping(2, distance);
    }
    else if (distance > 200 and distance <= 300) {
      ping(3, distance);
    }
    else if (distance > 100 and distance <= 200) {
      ping(4, distance);
    }
    else if (distance > 0 and distance <= 100) {
      ping(5, distance);
    }
    delay(100);
    //Reset counter back to the current time
    lastRead = millis();
  }
}

void loop() {
  batMap();
}
