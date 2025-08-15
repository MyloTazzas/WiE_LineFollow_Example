// Motor enabling pins
int leftMotor = 8;
int rightMotor = 7;

// LeftMotor control 
int leftForward = 6;
int leftBackward = 5;

// RightMotor control
int rightForward = 10;
int rightBackward = 11;

// Sensor pins
int irSensor = A0; 
int sensorVal;

// Ultrasonic sensor pins
int ultrasonicTrigger = 3;
int ultrasonicEcho = 4;

// Setup your pins for input and output
void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);

  pinMode(rightMotor, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  pinMode(ultrasonicTrigger, OUTPUT);
  pinMode(ultrasonicEcho, INPUT);

  Serial.begin(9600);

}
 
// This controls the robots behaviour, everything else builds to allowing this logic to function
void loop() {
  objectDistance = distanceSensor();
  
  if(objectDistance > 10) driveForward(255);
  if(objectDistance < 10) driveBackward(255);
  
  delay(100); 
  // Every 100ms, 0.1s, we repeat this loop
}

// Functions, we can define a movement here then simply call it in the loop.

void driveForward(int speedValue){
  digitalWrite(leftMotor, HIGH);
  analogWrite(leftForward, speedValue);
  analogWrite(leftBackward, 0);

  digitalWrite(rightMotor, HIGH);
  analogWrite(rightForward, speedValue);
  analogWrite(rightBackward, 0);
}

void driveBackward(int speedValue){
  digitalWrite(leftMotor, HIGH);
  analogWrite(leftForward, 0);
  analogWrite(leftBackward, speedValue);

  digitalWrite(rightMotor, HIGH);
  analogWrite(rightForward, 0);
  analogWrite(rightBackward, speedValue);
}

void driveRight(int speedValue){
  digitalWrite(leftMotor, HIGH);
  analogWrite(leftForward, speedValue);
  analogWrite(leftBackward, 0);

  digitalWrite(rightMotor, HIGH);
  analogWrite(rightForward, 0);
  analogWrite(rightBackward, speedValue);
}

void driveLeft(int speedValue){
  digitalWrite(leftMotor, HIGH);
  analogWrite(leftForward, 0);
  analogWrite(leftBackward, speedValue);

  digitalWrite(rightMotor, HIGH);
  analogWrite(rightForward, speedValue);
  analogWrite(rightBackward, 0);
}

int distanceSensor(){
  float duration, distance;

  digitalWrite(triggerPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(triggerPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(triggerPin, LOW); 

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print(distance);
  Serial.println();
  return distance;
}

