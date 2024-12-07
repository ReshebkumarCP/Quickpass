#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 49

MFRC522 rfid(SS_PIN, RST_PIN);



int signal1[] = {2, 3, 4};
int signal2[] = {22, 24, 26};
int signal3[] = {28, 30, 32};
int signal4[] = {11, 10, 9};


int redDelay = 3000;
int yellowDelay = 2000;


int button1 = 5; // Button for signal 1
int button2 = 6; // Button for signal 2
int button3 = 7; // Button for signal 3
int button4 = 8; // Button for signal 4


void SetSignalLed1()
{


  
digitalWrite(signal1[1], HIGH);
digitalWrite(signal1[0], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(3000);


// Making Green LED at signal 1 and red LED's at other signal HIGH
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], LOW);
digitalWrite(signal1[2], HIGH);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(5000);
digitalWrite(signal1[2], LOW);}


void SetSignalLed2()
{digitalWrite(signal2[1], HIGH);
digitalWrite(signal2[0], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(3000);


// Making Green LED at signal 1 and red LED's at other signal HIGH
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], LOW);
digitalWrite(signal2[2], HIGH);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(5000);
digitalWrite(signal2[2], LOW);}


void SetSignalLed3()
{digitalWrite(signal3[1], HIGH);
digitalWrite(signal3[0], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(3000);


// Making Green LED at signal 1 and red LED's at other signal HIGH
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], LOW);
digitalWrite(signal3[2], HIGH);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal4[0], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[2], LOW);
delay(5000);
digitalWrite(signal3[2], LOW);}


void SetSignalLed4()
{digitalWrite(signal4[1], HIGH);
digitalWrite(signal4[0], LOW);
digitalWrite(signal4[2], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
delay(3000);


// Making Green LED at signal 1 and red LED's at other signal HIGH
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], LOW);
digitalWrite(signal4[2], HIGH);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[2], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[2], LOW);
delay(5000);
digitalWrite(signal4[2], LOW);}





void setup() {


  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();


  pinMode(5 , INPUT_PULLUP) ; //Defining the buttons
  pinMode(6 , INPUT_PULLUP) ;
  pinMode(7 , INPUT_PULLUP) ;
  pinMode(8 , INPUT_PULLUP) ;


  
  // Declaring all the LED's as output
  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
}

void loop() {
  

    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) 
    {SetSignalLed1();

    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }
  // Making Green  LED at signal 1 and red LED's at other signal HIGH
  digitalWrite(signal1[2], HIGH);
  digitalWrite(signal1[0], LOW);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

      {
 


      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1(); 
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }



  // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
  digitalWrite(signal1[1], HIGH);
  digitalWrite(signal1[2], LOW);
  delay(yellowDelay);
  digitalWrite(signal1[1], LOW);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // Making Green  LED at signal 2 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[2], HIGH);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // Making Green LED at signal 2 LOW and making yellow LED at signal 2 HIGH for 2 seconds
  digitalWrite(signal2[1], HIGH);
  digitalWrite(signal2[2], LOW);
  delay(yellowDelay);
  digitalWrite(signal2[1], LOW);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // Making Green  LED at signal 3 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[2], HIGH);
  digitalWrite(signal3[0], LOW);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }
  // Making Green LED at signal 3 LOW and making yellow LED at signal 3 HIGH for 2 seconds
  digitalWrite(signal3[1], HIGH);
  digitalWrite(signal3[2], LOW);
  delay(yellowDelay);
  digitalWrite(signal3[1], LOW);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // Making Green  LED at signal 4 and red LED's at other signal HIGH
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[2], HIGH);
  digitalWrite(signal4[0], LOW);
  delay(redDelay);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1();

  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // Making Green LED at signal 4 LOW and making yellow LED at signal 4 HIGH for 2 seconds
  digitalWrite(signal4[1], HIGH);
  digitalWrite(signal4[2], LOW);
  delay(yellowDelay);
  digitalWrite(signal4[1], LOW);

      if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Making Green LED at signal 1 LOW and making yellow LED at signal 1 HIGH for 2 seconds
SetSignalLed1(); 
  }else {
    // Check buttons to set individual signals to green
    if (digitalRead(button1) == LOW) {
      SetSignalLed1();
    } else if (digitalRead(button2) == LOW) {
      SetSignalLed2();
    } else if (digitalRead(button3) == LOW) {
      SetSignalLed3();
    } else if (digitalRead(button4) == LOW) {
      SetSignalLed4();
    }
  }

  // ...



// ...
 // Add a short delay for stability

      }}


