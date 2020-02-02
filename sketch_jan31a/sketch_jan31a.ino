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

void ping(int n) {
  for (int i = 0; i < n; i++) {
    Serial.println("PING");
  }
   Serial.println(" ");
}

void batMap() {
  if ((millis() - lastRead >= INTERVAL)) {
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
      ping(1);
    }
    else if (distance > 300 and distance <= 400) {
      ping(2);
    }
    else if (distance > 200 and distance <= 300) {
      ping(3);
    }
    else if (distance > 100 and distance <= 200) {
      ping(4);
    }
    else if (distance > 0 and distance <= 100) {
      ping(5);
    }
    delay(100);
    //Reset counter back to the current time
    lastRead = millis();
  }
}

void loop() {
  batMap();
}
