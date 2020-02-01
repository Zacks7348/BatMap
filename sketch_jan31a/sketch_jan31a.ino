
#define INTERVAL 500 //Times between reads
unsigned long lastRead = 0;

// Ultrasonic Constants
const int trigPin = 9;
const int echoPin = 10;
//Ultrasonic Variables
float duration, distance;


// Button constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// Button Variables
int buttonState = 0;         // variable for reading the pushbutton status
boolean ON = false;
boolean pressed = false;


//Bluetooth Constants
const int bluetoothPin = ;
const int 



void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  //Initialize the Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);


}

void ultrasonic() {
  //Slow down how often the distance is measured
  if ((millis() - lastRead >= INTERVAL) and ON) {
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

void status() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH and !pressed) {
    ON = !ON;
    Serial.println("Status change");
    pressed = !pressed;
  }
  else if (buttonState == LOW and pressed) {
    pressed = !pressed;
  }
}

void loop() {
  status();
  ultrasonic();
}
