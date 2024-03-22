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

#define GreenLEDPin 35
#define RedLEDPin 33

struct Student{
  String name;
  int id;
};
// Student none = {"None", 0000};
Student chris = {"Chris", 2003};
Student jay = {"Jay", 2005};
Student henry = {"Henry", 2004};
const int numStudents = 3;
Student students[] = {chris, jay, henry};

struct Item{
  String id, title;
  bool checkedOut;
  String checkedOutBy, lastCheeckOutBy;
};

//Array of Items
Item card = {"33 55 14 11", "Card", false, "None", "None"};
Item keychain = {"EF 18 73 1D", "Key Chain", false, "None", "None"};
const int numItems = 2;
Item items[numItems] = {card, keychain};
String id = "EF 18 73 1D";

bool menuShown = false;

void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  RFIDreader.PCD_Init();  // Init MFRC522 card

  lcd.begin(16, 2); // Defines the Dimentions of the Display

  pinMode(GreenLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
}

void loop() {
  //If the menu is not shown, it will be
  if(!menuShown){
    displayPrint("Scan RFID Tag", 0);
    displayPrint("A:Cycle User Logs", 1);
    menuShown = true;
  }
  
  //checks it the A key has been pressed
  char customKey = customKeypad.getKey();
  if (customKey == 'A'){

    //Shows an item, its status, and who has/had it
    for (int i = 0; i < numItems; i++){
      displayPrint(items[i].title.c_str(), 0);
      if(items[i].checkedOut){
        lcd.print(":Out");
        displayPrint(items[i].checkedOutBy.c_str(), 1);
      }
      else{
        lcd.print(":In");
        displayPrint(items[i].lastCheeckOutBy.c_str(), 1);
      }

      //Waits for the user to press the A key to cycle to the next item or return to the menu
      customKey = customKeypad.getKey();
      while (customKey != 'A'){
        customKey = customKeypad.getKey();
      }
    }
    
    //Tells the Menu to load
    menuShown = false;
  }

  //If there is no new tag restart loop
  if ( ! RFIDreader.PICC_IsNewCardPresent()) 
  {
    return;
  }

  // Selects one of the cards
  if ( ! RFIDreader.PICC_ReadCardSerial()) 
  {
    return;
  }

  //Gets the ID of the RFID Tag
  String content= "";
  byte letter;
  for (byte i = 0; i < RFIDreader.uid.size; i++) {
    content.concat(String(RFIDreader.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFIDreader.uid.uidByte[i], HEX));
  }
  content.toUpperCase();

  //finds the item with the ID in the list
  for (int i = 0; i < numItems; i++){

    //Enters when IDs match
    if (content.substring(1) == items[i].id){

      //If the Item is Checked out
      if(items[i].checkedOut){

        //Tells the user the ID was returned
        displayPrint(items[i].title.c_str(), 0);
        displayPrint("Returned", 1);

        //Turns on the Green LED
        digitalWrite(GreenLEDPin, HIGH);

        //Saves the user who last checked out the item
        items[i].lastCheeckOutBy = items[i].checkedOutBy;
        items[i].checkedOutBy = "None";
      }

      //If the Item is not Checked Out
      else{

        //Asks the user for their ID
        displayPrint("Enter ID:", 0);
        displayPrint("", 1);

        //loops until a vaild ID is entered
        int id = 0;
        while(true){

          //loops until 4 digits are entered
          int j = 0;
          while (j < 4){
            char customKey = customKeypad.getKey();
            if (customKey){
              id = id*10 + (customKey - '0');
              j++;
            }
          }

          //check for the ID in the list of students
          for (int j = 0; j < numStudents; j++){

            //sets the user as the person who has checked out the item
            if (students[j].id == id){
              items[i].checkedOutBy = students[j].name;
            }
          }

          //If the user was found exit the loop
          if(items[i].checkedOutBy != "None"){
            break;
          }

          //if a user was not found ask for the ID agian
          else{
            id = 0;
            displayPrint("Renter ID:", 0);

            //turns on the red LED
            digitalWrite(RedLEDPin, HIGH);
          }
        }

        //Makes sure the Red LED is off
        digitalWrite(RedLEDPin, LOW);

        //turns on the Green LED
        digitalWrite(GreenLEDPin, HIGH);

        //Let the user know the item was checked out
        displayPrint(items[i].checkedOutBy.c_str(), 0);
        displayPrint("Checked Out", 1);
      }

      //toggles the state of the item
      items[i].checkedOut = !(items[i].checkedOut);
    }
  }

  //delay to prevent duplicate reads of the RFID
  delay(2000);

  //Tells the menu to show
  menuShown = false;

  //turn off all LEDs
  digitalWrite(GreenLEDPin, LOW);
  digitalWrite(RedLEDPin, LOW);
}

//method to set a line on the display
void displayPrint(const char str[], int row){

  //clears the line
  lcd.setCursor(0, row);
  lcd.print("                ");

  //displays the text
  lcd.setCursor(0, row);
  lcd.print(str);
}