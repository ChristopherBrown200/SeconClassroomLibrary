#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Keypad.h>


//Constant for RFID Reader
#define RST_PIN   48
#define SS_PIN    53
//RFID reader object
MFRC522 RFIDreader(SS_PIN, RST_PIN);

//Constant for Keypad
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {//define the cymbols on the buttons of the keypads
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
//Keypad Object
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//Object for LCD Display
LiquidCrystal lcd(37, 38, 39, 40, 41, 42);


void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  RFIDreader.PCD_Init();  // Init MFRC522 card
  lcd.begin(16, 2); // Defines the Dimentions of the Display
}

void loop() {
  
  //Check for RFID Card
  if ( ! RFIDreader.PICC_IsNewCardPresent() || ! RFIDreader.PICC_ReadCardSerial() ) {
    char customKey = customKeypad.getKey();
  
    if (customKey){
      displayPrint("Test", 0, 1);
    }

    delay(50);
    return;
  }
  
  //Read UID
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < RFIDreader.uid.size; i++) {
    Serial.print(RFIDreader.uid.uidByte[i]);//, HEX);
    Serial.print("|");
  } 
  Serial.println();

delay(2000);
}

void displayPrint(const char str[], int charIndex, int row){
  lcd.setCursor(charIndex, row);
  lcd.print(str);
}