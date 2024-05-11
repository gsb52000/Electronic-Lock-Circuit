# Electronic-Lock-Circuit

# Libraries:
Keypad.h: For interfacing with the keypad.<br>
Servo.h: For controlling the servo motor.<br>
LiquidCrystal.h: For controlling the LCD.<br>

# Constants and Pin Definitions:
#define ROWS 4 and #define COLS 4: This defines the number of rows and columns in the keypad matrix.<br>
servoPin is defined as A1 which represents the pin number where the servo motor is connected.<br>

# Objects and Variables:
Servo demoServo: Declares a servo object named demoServo.<br>
LiquidCrystal lcd(53, 52, 51, 50, 49, 48): Initializes an LCD object named lcd with pin numbers for RS, E, D4, D5, D6, and D7.<br>
char keys[ROWS][COLS]: Defines a 4x4 matrix to store the keys of the keypad.<br>
byte rowPins[ROWS] and byte colPins[COLS]: Arrays to store the row and column pin numbers respectively.<br>

# Setup Function:
demoServo.attach(servoPin): Attaches the servo motor to the pin defined by servoPin.<br>
Serial.begin(9600): Initializes serial communication with a baud rate of 9600.<br>
lcd.begin(16, 2): Initializes the LCD with 16 columns and 2 rows.<br>
pinMode(11, OUTPUT) and pinMode(12, OUTPUT): Sets pins 11 and 12 as output pins.<br>

# Loop Function:
char key = keypad.getKey(): Reads a key press from the keypad.<br>
If a key is pressed, it checks which key is pressed:<br>
If '1' is pressed, it prints "Correct" to serial, displays "Open" on the LCD, and moves the servo to position 250.<br>
If '2' is pressed, it prints "Closed" to serial, displays "Closed" on the LCD, and moves the servo to position -250.<br>
If any other key is pressed, it prints "Incorrect" to serial, displays "Incorrect Passcode" on the LCD, and turns on pin 11 (presumably an indicator LED).<br>

# Serial Communication:
If there's data available on the serial port it reads the command.<br>
If the command is '1', it performs the same actions as pressing '1' on the keypad.<br>
If the command is not '1', it performs the same actions as pressing '2' on the keypad.<br>

# Cleanup:
delay(1000): Delays for 1 second to prevent multiple key presses.<br>
lcd.clear(): Clears the LCD.<br>
digitalWrite(12,LOW) and digitalWrite(11,LOW): Turns off pins 11 and 12.<br>
