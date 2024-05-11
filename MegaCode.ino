// C++ code
#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define ROWS 4
#define COLS 4
#define servoPin A1

Servo demoServo;
LiquidCrystal lcd(53, 52, 51, 50, 49, 48);

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  demoServo.attach(servoPin);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
    if (key == '1') {
      //Correct code entered
      Serial.println("Correct");
      lcd.print("Open");
      digitalWrite(12, HIGH);
      demoServo.write(250);
    }
      else if (key == '2'){
      lcd.print("Closed");
      digitalWrite(12,HIGH);
      demoServo.write(-250);
      } 
    else {
      //Incorrect code entered
      digitalWrite(11,HIGH);
      Serial.println("Incorrect");
      lcd.print("Incorrect Passcode");
    }

if (Serial.available()) {
    char command = Serial.read(); // Read the command from the ESP-32

    if (command == '1') {
      // Correct code entered
      Serial.println("Correct");
      lcd.print("Open");
      digitalWrite(12, HIGH);
      demoServo.write(250);
    } else {
      // Incorrect code entered
      Serial.println("Incorrect");
      lcd.print("Closed");
      digitalWrite(11, HIGH);
      demoServo.write(-250);
    }

    delay(1000); //delay to prevent multiple key presses
    lcd.clear();
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  }
  
}
}
