
int latchPin = 8;

int clockPin = 12;

int dataPin = 11;
int buttonPin=13;
int buttonState=0;

byte colDataMatrix[8] = { B01111111,

B10111111,

B11011111,

B11101111,

B11110111,

B11111011,

B11111101,

B11111110

};

byte rowDataMatrix[8] = { 
B10101010,

B01010000,

B00101101,

B01010000,

B00101101,

B10000111,

B00000101,

B10101010

};byte rowDataMatrix1[8] = { 
B10101010,

B01010000,

B00101101,

B01010000,

B10000111,

B00101101,

B00000101,

B10101010

};

// 定義顯示器顯示的時間 (延遲時間), 預設 1ms

int delay_time = 1;

void setup() {
 pinMode(buttonPin,INPUT);

pinMode(latchPin,OUTPUT);

pinMode(clockPin,OUTPUT);

pinMode(dataPin,OUTPUT);

}

void loop() {
buttonState=digitalRead(buttonPin);
if(buttonState==HIGH){
for(int i = 0; i < 8 ; i++){

//byte colData = colDataMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(delay_time);

}

}
else{
  for(int i = 0; i < 8 ; i++){

//byte colData = colDataMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix1[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(delay_time);
  }
}

}
