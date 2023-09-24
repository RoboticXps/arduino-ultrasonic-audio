// Play audio file from your computer based on Ultrasonic sensor values with Arduino.
// Example by RoboticX

// Define the ultrasonic sensor pin
const int trigPin = 2;
const int echoPin = 3;

// Define the distance threshold
const int distanceThreshold = 15;

void setup()
{
  // Set the ultrasonic sensor pins as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // Measure the distance using the ultrasonic sensor
  long distance = measureDistance();

  // If the distance is less than the threshold, send a serial message to the laptop
  if (distance < distanceThreshold)
  {
    Serial.println("Play audio");
  }
}

// Function to measure the distance using the ultrasonic sensor
long measureDistance()
{
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the pulse to return
  long pulseTime = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = pulseTime / 58;

  return distance;
}
