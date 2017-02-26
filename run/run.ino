
#include<SoftwareSerial.h>

 int rxPin = 7;    // goes to 4
 int txPin = 6;    // goes to 3
 int ddPin = 5;    // goes to 5

 SoftwareSerial mySerial(rxPin, txPin);

 void setup() {
  
   Serial.begin(19200);
     delay(1000);
   pinMode (ddPin, OUTPUT);
     delay(1000);
   mySerial.begin(19200);
     delay(1000);
  
   if (mySerial.available())
     Serial.println(mySerial.read());
   else
     Serial.println("test");
    
  wake();
  
  // travel 2 metres
  driveStraight(500, 4000);    

  // make first turn
  drive(100, 2680);

  // travel 1 meter
  driveStraight(500, 1800);

  // make second turn
  drive(100, 2600);

  // travel 2 meters
  driveStraight(500, 4000);

  // make last turn
  drive(100, 3000);

  // last 1 meter stretch
  driveStraight(500, 1800);

  // STOP
  driveStraight(0, 3000);
  
} // end setup

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
}

