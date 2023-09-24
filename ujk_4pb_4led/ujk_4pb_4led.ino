int pinLed1 = 2;
int pinLed2 = 3;
int pinLed3 = 4;
int pinLed4 = 5;
int pbKanan = 6;
int pbKiri = 7;
int pbOff = 8;
int pbPause = 9;
int i;


void led(int Nyala) {
  if(Nyala == 1){
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
  if(Nyala == 2){
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  }
  if(Nyala == 3){
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, LOW);
  }
  if(Nyala == 4){
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, HIGH);
  }
}
  void untukOff() {
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
  } 


void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pbKanan, INPUT);
  pinMode(pbKiri, INPUT);
  pinMode(pbPause, INPUT);
  pinMode(pbOff, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  keluar:
  if(digitalRead(pbKanan) == HIGH) {
    while(1) {
      for(i=1; i<5; i++) {
        jump:
        led(i);
        for(int a=0; a<100; a++){delay(3);
        
        if(digitalRead(pbOff) == HIGH) {untukOff(); goto keluar;}
        if(digitalRead(pbKiri) == HIGH) { goto jump1;}
        if(digitalRead(pbPause) == HIGH) {
          while(1) {
            if(digitalRead(pbKiri) == HIGH) { goto jump1;}
            if(digitalRead(pbKanan) == HIGH) { goto jump;}
            if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
          }
        }
      }
    }
  }
}

  if(digitalRead(pbKiri) == HIGH) {
    while(1) {
      for(i=4; i>0; i--) {
        jump1:
        led(i);
        for(int a=0; a<100; a++) {delay(3);

        if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
        if(digitalRead(pbKanan) == HIGH) { goto jump;}
        if(digitalRead(pbPause) == HIGH) {
          while(1) {
            if(digitalRead(pbKanan) == HIGH) {goto jump;}
            if(digitalRead(pbKiri) == HIGH) {goto jump1;}
            if(digitalRead(pbOff) == HIGH) { untukOff(); goto keluar;}
            }
          }
        }
      }
    }
  }
}
