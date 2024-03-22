#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
//#include "Item.h"


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

struct Student{
  String name;
  int id;
};
Student chris = {"Chris", 0644};
Student jay = {"Jay", 7691};
Student henry = {"Henry", 2004};

struct Item{
  String id, title;
  bool checkedOut;
};

//Array of Items
Item card = {"33 55 14 11", "card", false};
Item keychain = {"EF 18 73 1D", "key chain", false};
const int numItems = 2;
Item items[numItems] = {card, keychain};
String id = "EF 18 73 1D";


void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  RFIDreader.PCD_Init();  // Init MFRC522 card

  lcd.begin(16, 2); // Defines the Dimentions of the Display
}

void loop() {
  
  if ( ! RFIDreader.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! RFIDreader.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < RFIDreader.uid.size; i++) 
  {
    content.concat(String(RFIDreader.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFIDreader.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content.substring(1));
  Serial.println(items[0].id);
  for (int i = 0; i < numItems; i++){
    if (content.substring(1) == items[i].id){
      displayPrint(items[i].title.c_str(), 0);
      if(items[i].checkedOut){
        displayPrint("Returned", 1);
        
      }
      else{
        displayPrint("Enter Id:", 0);
        int id = 0;
        int j = 0;
        while (j < 4){
          char customKey = customKeypad.getKey();
          if (customKey){
            id = id*10 + customKey;
            j++;
          }
        }
        Serial.println(id);
        displayPrint("Checked Out", 1);
      }
      items[i].checkedOut = !(items[i].checkedOut);
    }
  }


delay(2000);
}

void displayPrint(const char str[], int row){
  lcd.setCursor(0, row);
  lcd.print("                ");
  lcd.setCursor(0, row);
  lcd.print(str);
}