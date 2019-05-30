const int controlPin1 =  2;
const int controlPin2 = 3;
const int controlPin4 = 4;
const int controlPin5 = 5;
const int enablePin = 9;
const int enablePin2 = 10;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 1;
int previousOnOffSwitchState = 0;
int directionSwitchState = 1;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 0;


void setup() {
  //pinMode(directionSwitchPin, INPUT);
  //pinMode(onOffSwitchStateSwitchPin,INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  pinMode(controlPin5, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
  digitalWrite(enablePin2, HIGH);
}

void loop() {
  //onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  //directionSwitchState = digitalRead(directionSwitchPin);
  directionSwitchState = 1;
  //motorSpeed = analogRead(potPin)/4;

  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(directionSwitchState != previousDirectionSwitchState){
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1){
    digitalWrite(controlPin1,HIGH);
    digitalWrite(controlPin2,LOW);
    digitalWrite(controlPin4,HIGH);
    digitalWrite(controlPin5,LOW);
  }
  else{
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    digitalWrite(controlPin4,LOW);
    digitalWrite(controlPin5,HIGH);
  }

  /*if (motorEnabled ==1){
      analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }*/
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
