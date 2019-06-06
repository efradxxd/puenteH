const int controlPin1 =  2;
const int controlPin2 = 3;
const int controlPin4 = 4;
const int controlPin5 = 5;
const int enablePin = 9;
const int enablePin2 = 10;

int onOffSwitchState = 1;
int previousOnOffSwitchState = 0;
int directionSwitchState = 1;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;


const int Trigger = 13;   //Pin digital 2 para el Trigger del sensor
const int Echo = 12;   //Pin digital 3 para el Echo del sensor


void setup() {
  Serial.begin(9600); 
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  pinMode(controlPin5, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
  digitalWrite(enablePin2, HIGH);


  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0


}

void loop() {

  long d; //distancia en centimetros 
  d = dcal();
  Serial.print(d);  
  Serial.print("\t");    
  //onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
//  delay(1);
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
    MotorSpeedOn();
  }
  else{
    MotorSpeedOff();
  }
  if(d <= 20){
    //MotorSpeedOff();
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, HIGH);
    //delay(10000);
    digitalWrite(controlPin4,HIGH);
    digitalWrite(controlPin5,HIGH);
//    digitalWrite(controlPin1, HIGH);
//    digitalWrite(controlPin2, LOW);
//    delay(3000);
    
  }
  if(d <= 100){
    //MotorSpeedOff();
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, HIGH);
    //delay(10000);
    digitalWrite(controlPin4,HIGH);
    digitalWrite(controlPin5,HIGH);
//    digitalWrite(controlPin1, HIGH);
//    digitalWrite(controlPin2, LOW);
//    delay(3000);
    
  }
  //delay(3000);
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}

void MotorSpeedOn(){
  digitalWrite(controlPin1,HIGH);
  digitalWrite(controlPin2,LOW);
  digitalWrite(controlPin4,HIGH);
  digitalWrite(controlPin5,LOW);
}
void MotorSpeedOff(){
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
  digitalWrite(controlPin4,LOW);
  digitalWrite(controlPin5,HIGH);
}
int dcal(){
  long t; //timepo que demora en llegar el eco

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  return t/59; 
}
