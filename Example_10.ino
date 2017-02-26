#include<SoftwareSerial.h>
//#include <EEPROM.h>

int rxPin = 7;
int txPin = 6;
int ddPin = 5;
//int lstDir = 0;
//int addr = 0;
//int value  = 0;
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  //value = EEPROM.read(addr);
  Serial.begin(19200);
    delay(1000);
  Serial.println("Hello Dave");
  pinMode (ddPin, OUTPUT);
  Serial.println("Hello Dave, pinmod set");
    delay(1000);
  mySerial.begin(19200);
  Serial.println("Hello Dave, serial began");
    delay(1000);
  Serial.println("Hello Dave, there was a delay");
  
  if (mySerial.available())
    Serial.println(mySerial.read());
  else
    Serial.println("test");
    
  digitalWrite(ddPin, HIGH);
  delay(10);
  digitalWrite(ddPin, LOW);
  delay(50);
  digitalWrite(ddPin, HIGH);
  delay(10);
  mySerial.write(128);
  delay(1000);
  mySerial.write(131);
  delay(10);
  
    //Go staright for 3 seconds then reverse
  driveStraight(500, 4000);
  //driveStraight(-500, 3000);
  drive(100, 2680);
  
  driveStraight(500, 1800);

  drive(100, 2600);
  
  driveStraight(500, 4000);

  drive(100, 3000);

  driveStraight(500, 1800);
//Drive striaght for 3 seconds, then turn left (hopefully) for 1 second, then drive straight agian for 3 seconds to confirm that it goes in a square.
/*
  driveStraight(500, 3000);
  drive(1,1000);
  delay(1000);
  driveStraight(500, 3000);
  */
  driveStraight(0, 3000);
  //endofCode();
  //EEPROM.write(addr,value);
}

void driveStraight(int vel, int time){
  mySerial.write(145);
  sendHighLow(vel);
  sendHighLow(vel);
  delay(time);
}
void drive(int vel, int time){
  mySerial.write(137);
  sendHighLow(vel);
  sendHighLow(vel);
  sendHighLow(-vel);
  sendHighLow(-vel);
  delay(time);
}
void sendHighLow(int send) {
  mySerial.write(highByte(send));
 delay(1);
  mySerial.write(lowByte(send));
}

void swrite(int message){
  mySerial.write(message);
  delay(1000);
}

void wake(){
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(100);
  mySerial.write(128);
  delay(1000);
  mySerial.write(131);
  delay(1000);
}

void endofCode(){
  mySerial.write(143);
  delay(100);
}

void loop() {
  // Serial.println("Hello Dave");
  

 //Serial.println("I love Jesus");
}
